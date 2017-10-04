#include "project.h"
#include "CModule.h"
#include "CSymbol.h"

/*
typedef struct tagMODULE_INFO	{
	BSTR	Name;				// 
	BSTR	DocString;			//
	DWORD	BaseAddress;		// custom
	DWORD	Size;				// custom
} MODULE_INFO;
*/

void
CopyModuleInfo(MODULE_INFO &Dest, MODULE_INFO&Source)
{
	Dest.Name			= ::SysAllocString( Source.Name );
	Dest.DocString		= ::SysAllocString( Source.DocString );
	Dest.BaseAddress	= Source.BaseAddress;
	Dest.Size			= Source.Size;
}
void
ReleaseModuleInfo(MODULE_INFO &Module)
{
	::SysFreeString( Module.Name );
	::SysFreeString( Module.DocString );
}

STDMETHODIMP
CModule::GetModuleInfo(MODULE_INFO **ModuleInfo)
{
	*ModuleInfo = new MODULE_INFO;
	::CopyModuleInfo(**ModuleInfo, m_ModuleInfo);
	return S_OK;
}

STDMETHODIMP
CModule::ReleaseModuleInfo(MODULE_INFO *pModuleInfo)
{
	_ASSERT( NULL != pModuleInfo );
	::ReleaseModuleInfo( m_ModuleInfo );
	delete pModuleInfo;
	return S_OK;
}

CModule::CModule()
{
	m_NextSymbolIndex = 0;
}

CModule::~CModule()
{
	::ReleaseModuleInfo(m_ModuleInfo);
	for(POSITION pos=m_SymbolList.GetHeadPosition();pos!=NULL;)	{
		CSymbol *Symbol = m_SymbolList.GetNext(pos);
		Symbol->Release();
	}
}

//static 
CModule *
CModule::CreateModuleFromTypeInfo(ITypeInfo2 *pITypeInfo)
{
	_ASSERT(pITypeInfo != NULL);

	//
	// Allocate and initialize the new CModule object
	//
	CModule *Module = new CComObject<CModule>();
	Module->m_pITypeInfo = pITypeInfo;

	//
	// Read the MODULE_INFO in from the given ITypeInfo
	//
	ReadModuleInfo(pITypeInfo, &Module->m_ModuleInfo);

	return Module;
}
//static
CModule *
CModule::CreateNewModule(MODULE_INFO *ModuleInfo, ICreateTypeLib2 *pICreateTypeLib)
{
	_ASSERT(NULL != ModuleInfo);
	_ASSERT(NULL != pICreateTypeLib);

	//
	// Allocate the new CModule object
	//
	CModule *Module = new CComObject<CModule>();

	//
	// Copy the MODULE_INFO from that given
	//
	CopyModuleInfo(Module->m_ModuleInfo, *ModuleInfo);
	
	//
	// Create a new ICreateTypeInfo in this type lib
	//
	CComPtr<ICreateTypeInfo> pITemp;
	CComPtr<ICreateTypeInfo2> pICreateTypeInfo;
	if (FAILED(pICreateTypeLib->CreateTypeInfo(ModuleInfo->Name, TKIND_MODULE, &pITemp)))	{
		delete Module;
		return NULL;
	}
	pITemp->QueryInterface(IID_ICreateTypeInfo2, reinterpret_cast<void **>(&pICreateTypeInfo));

	
	//
	// Get an ITypeInfo to store in the CModule
	//
	if (FAILED(pICreateTypeInfo->QueryInterface(IID_ITypeInfo, reinterpret_cast<void **>(&Module->m_pITypeInfo))))	{
		delete Module;
		return NULL;
	}

	//
	// Commit the MODULE_INFO to the ITypeInfo
	//
	WriteModuleInfo(pICreateTypeInfo, &Module->m_ModuleInfo);

	return Module;
}

//static
HRESULT
CModule::ReadModuleInfo(ITypeInfo2 *pITypeInfo, MODULE_INFO *pModuleInfo)
{
	HRESULT h;

	//
	// Verify that this type info refers to a module
	//
	TYPEKIND TypeKind;
	h = pITypeInfo->GetTypeKind(&TypeKind);
	if ( FAILED(h) || TypeKind != TKIND_MODULE )
		return E_FAIL;

	//
	// Get the name and docstring
	//
	h = pITypeInfo->GetDocumentation(MEMBERID_NIL, &pModuleInfo->Name, &pModuleInfo->DocString, NULL, NULL);
	if ( FAILED(h) )
		return h;


	//
	// Get the base address and size from custom data
	//
	VARIANT v;
	pModuleInfo->BaseAddress = 0;	// init
	h = pITypeInfo->GetCustData( GUID_CD_Address, &v );
	if ( SUCCEEDED(h) )	{
		_ASSERT( v.vt == VT_UI4 );
		pModuleInfo->BaseAddress = v.ulVal;
	}

	pModuleInfo->Size = 0;
	h = pITypeInfo->GetCustData( GUID_CD_Size, &v );
	if ( SUCCEEDED(h) )	{
		_ASSERT( v.vt == VT_UI4 );
		pModuleInfo->Size = v.ulVal;
	}


	return S_OK;
}

//static 
HRESULT
CModule::WriteModuleInfo(ICreateTypeInfo2 *pICreateTypeInfo, MODULE_INFO *ModuleInfo)
{
	//
	// Write the name and docstring
	//
	HRESULT h = pICreateTypeInfo->SetName(ModuleInfo->Name);
	if ( FAILED(h) )
		return h;

	pICreateTypeInfo->SetDocString(ModuleInfo->DocString);	// silent failure

	//
	// Write the base address and size to custom data
	//
	VARIANT v;
	v.vt = VT_UI4;
	v.ulVal = ModuleInfo->BaseAddress;
	pICreateTypeInfo->SetCustData( GUID_CD_Address, &v );	// silent failure

	v.ulVal = ModuleInfo->Size;
	pICreateTypeInfo->SetCustData( GUID_CD_Size, &v );		// silent failure

	return S_OK;
}

STDMETHODIMP
CModule::Update(MODULE_INFO *ModuleInfo)
{
	//
	// We can only Update() if our ITypeInfo interface points to an object
	// that supports ICreateTypeInfo2
	//
	CComQIPtr<ICreateTypeInfo2, &IID_ICreateTypeInfo2> pICreateTypeInfo(m_pITypeInfo);
	if ( !pICreateTypeInfo )
		return E_FAIL;

	return WriteModuleInfo( pICreateTypeInfo, ModuleInfo );
}

STDMETHODIMP
CModule::AddSymbol(ISymbol **ppSymbol, SYMBOL_INFO *SymbolInfo)
{
	//
	// If we already have a symbol of this name, fail
	//
	CComPtr<ISymbol> pISymbol;
	if ( SUCCEEDED(GetSymbolByName(&pISymbol, SymbolInfo->Name)) )
		return E_FAIL;

	//
	// Check that this symbol sits in our virtual address range
	//
	if (SymbolInfo->Address < m_ModuleInfo.BaseAddress ||
		SymbolInfo->Address > m_ModuleInfo.BaseAddress + m_ModuleInfo.Size)
		return E_FAIL;

	//
	// Get a pointer to the ICreateTypeInfo for our type library
	//
	CComQIPtr<ICreateTypeInfo2, &IID_ICreateTypeInfo2> pICreateTypeInfo(m_pITypeInfo);
	if ( !pICreateTypeInfo )
		return E_FAIL;

	//
	// Create the new CSymbol object
	//
	CSymbol *NewSymbol = CSymbol::CreateNewSymbol( SymbolInfo, pICreateTypeInfo, GetNextSymbolIndex() );
	if (NewSymbol && ppSymbol)	{
		*ppSymbol = NewSymbol;
		(*ppSymbol)->AddRef();
	}
	if (!NewSymbol)
		return E_FAIL;
		
	//
	// Add it to our list in address order
	//
	for(POSITION pos=m_SymbolList.GetHeadPosition();pos!=NULL;)	{
		CSymbol *Symbol = m_SymbolList.GetNext(pos);
		if (Symbol->Address() > NewSymbol->Address())	{
			pos = m_SymbolList.InsertBefore(pos, NewSymbol);
			break;
		}
	}
	if(pos==NULL)
		m_SymbolList.AddTail(NewSymbol);

	NewSymbol->AddRef();	// for the list
	return S_OK;
}

STDMETHODIMP
CModule::GetSymbolByAddress(ISymbol **ppSymbol, DWORD Address)
{
	CSymbol *NearestSymbol = NULL;
	*ppSymbol = NULL;
	for(POSITION pos=m_SymbolList.GetHeadPosition();pos!=NULL; )	{
		CSymbol *Symbol = m_SymbolList.GetNext(pos);
		if ( Symbol->Contains(Address) )	{
			*ppSymbol = Symbol;
			(*ppSymbol)->AddRef();
			break;
		} else {
			if (Symbol->Delta(Address) > 0 &&
				(!NearestSymbol ||
				Symbol->Delta(Address) < NearestSymbol->Delta(Address)) )
				NearestSymbol = Symbol;
		}
	}

	if (!*ppSymbol)	{
		if (NearestSymbol)	{
			*ppSymbol = NearestSymbol;
			(*ppSymbol)->AddRef();
		}
	}

	return *ppSymbol == NULL ? E_FAIL : S_OK;
}

STDMETHODIMP
CModule::GetSymbolByName(ISymbol **ppSymbol, BSTR Name)
{
	*ppSymbol = NULL;
	for(POSITION pos=m_SymbolList.GetHeadPosition();pos!=NULL; )	{
		CSymbol *Symbol = m_SymbolList.GetNext(pos);
		if ( !wcscmp(Symbol->Name(), Name) )	{
			*ppSymbol = Symbol;
			(*ppSymbol)->AddRef();
			break;
		}
	}
	return *ppSymbol == NULL ? E_FAIL : S_OK;
}

BOOL
CModule::Contains(DWORD Address)
{
	if ( this->Address() <= Address && HighAddress() > Address )
		return TRUE;
	else
		return FALSE;
}

STDMETHODIMP
CModule::EnumSymbols(IEnumSymbols **ppEnum)
{
	int NumberOfSymbols = m_SymbolList.GetCount();
	ISymbol **SymbolArray = new ISymbol *[NumberOfSymbols];

	POSITION pos; int i;
	for(pos=m_SymbolList.GetHeadPosition(), i=0;pos!=NULL; i++)	{
		SymbolArray[i] = m_SymbolList.GetNext(pos);
		SymbolArray[i]->AddRef();
	}

	typedef CComEnum<IEnumSymbols, &IID_IEnumSymbols, ISymbol *, _CopyInterface<ISymbol> > CEnumSymbols;
	CComObject<CEnumSymbols> *Enum = new CComObject<CEnumSymbols>;

	Enum->Init(&SymbolArray[0], &SymbolArray[NumberOfSymbols], NULL, AtlFlagTakeOwnership);

	//
	// I'm not sure why this is necessary, but this is the technique used by
	// Microsoft code using the CComEnum<> template.
	//
	HRESULT hr = Enum->_InternalQueryInterface(IID_IEnumSymbols, (void**)ppEnum);
	if (FAILED(hr))
		delete Enum;
	
	return hr;

}