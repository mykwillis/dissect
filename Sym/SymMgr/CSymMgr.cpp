#include "project.h"
#include "CSymMgr.h"
#include "CType.h"
#include "CModule.h"
#include "CSymbol.h"

#include <wchar.h>	// swprintf
HRESULT MakeUniqueNameWithAddress(BSTR *pbs, DWORD dwAddr)
{
	// new buffer size must be size of passed in string + underscore + 8 digits + NULL
	size_t s = wcslen(*pbs) + 1 + 8 + 1;

	wchar_t *c = new wchar_t[s];
	wchar_t buf[20];

	// i.e., "Function_10a8"
	swprintf(c, L"%ws_%ws", *pbs, _itow(dwAddr, buf, 0x10) );

	::SysFreeString(*pbs);

	*pbs = ::SysAllocString(c);

	delete [] c;
	return S_OK;
}

STDMETHODIMP
CSymMgr::CreateNew(OLECHAR *Path)
{
	//
	// Create a new type lib for this image
	//
	HRESULT h = ::CreateTypeLib2(SYS_WIN32, Path, &m_pICreateTypeLib);
	if ( FAILED(h) )	{
		return h;
	}

	//
	// Get an ITypeLib interface to the type library
	//
	h = m_pICreateTypeLib->QueryInterface(IID_ITypeLib2, (void **)&m_pITypeLib);
	if ( FAILED(h) )	{
		return h;
	}
	
	//
	// Get an ITypeComp interface to the type library
	//
	h = m_pICreateTypeLib->QueryInterface(IID_ITypeComp, (void **)&m_pITypeComp);
	if ( FAILED(h) )	{
		return h;
	}

	//
	// Create the orphan
	//
	MODULE_INFO ModuleInfo;
	ModuleInfo.Name = L"<unknown>";
	ModuleInfo.DocString = NULL;

	m_pIOrphanModule = CModule::CreateNewModule(&ModuleInfo, m_pICreateTypeLib);

	return S_OK;
}

STDMETHODIMP
CSymMgr::OpenExisting(OLECHAR *)
{
	return E_NOTIMPL;
}

CSymMgr::~CSymMgr()
{
	HRESULT h = m_pICreateTypeLib->SaveAllChanges();
	if ( FAILED(h) )	{
		_ASSERT(0);
		// yipes
	}
	for(POSITION pos=m_ModuleList.GetHeadPosition();pos!=NULL;)	{
		m_ModuleList.GetNext(pos)->Release();
	}
	for(pos=m_TypeList.GetHeadPosition();pos!=NULL;)	{
		m_TypeList.GetNext(pos)->Release();
	}
}


//
//
// Type Methods ----------------------------------------------------
//
//

STDMETHODIMP
CSymMgr::AddType(IType **ppType, TYPE_INFO *TypeInfo)
{
	CType *Type = CType::CreateNewType(TypeInfo, m_pICreateTypeLib);
	if (!Type)
		return E_FAIL;

	Type->AddRef();
	m_TypeList.AddHead(Type);

	return Type->QueryInterface(IID_IType, (void **)ppType);
}


STDMETHODIMP
CSymMgr::GetTypeByName(IType **ppType, BSTR Name)
{
	POSITION pos;
	for (pos=m_TypeList.GetHeadPosition();pos!=NULL; )	{
		CType *Type = m_TypeList.GetNext(pos);
		if (!wcscmp(Type->GetName(), Name))	{
			return Type->QueryInterface(IID_IType, (void **)ppType);
		}
	}

	return E_FAIL;
}

STDMETHODIMP
CSymMgr::GetTypeByHandle(IType **ppType, HTYPE Handle)
{
	if (!Handle)
		return E_FAIL;

	*ppType = (IType *)Handle;
	(*ppType)->AddRef();
	return S_OK;
}

STDMETHODIMP
CSymMgr::GetTypeHandle(HTYPE *Handle, IType *Type)
{
	*Handle = (HTYPE)Type;
	if (!Type)
		return E_FAIL;
	else	{
		Type->AddRef();
		return S_OK;
	}
}

STDMETHODIMP
CSymMgr::CloseTypeHandle(HTYPE Handle)
{
	if ((HTYPE)0 == Handle)
		return E_FAIL;

	((IType *)Handle)->Release();
	return S_OK;
}

STDMETHODIMP
CSymMgr::EnumTypes(IEnumTypes **ppEnum)
{
	typedef CComEnum<IEnumTypes, &IID_IEnumTypes, IType *, _CopyInterface<IType> > CEnumTypes;
	CComObject<CEnumTypes> *Enum = new CComObject<CEnumTypes>;

	IType **Types = new IType* [m_TypeList.GetCount()];
	POSITION pos; int i;
	for (pos=m_TypeList.GetHeadPosition(), i=0;pos!=NULL; i++)
		Types[i] = m_TypeList.GetNext(pos);

	Enum->Init(&Types[0], &Types[m_TypeList.GetCount()], NULL, AtlFlagTakeOwnership);

	//
	// I'm not sure why this is necessary, but this is the technique used by
	// Microsoft code using the CComEnum<> template.
	//
	HRESULT hr = Enum->_InternalQueryInterface(IID_IEnumTypes, (void**)ppEnum);
	if (FAILED(hr))
		delete Enum;
	
	return hr;
}

//
//
// Module Methods ----------------------------------------------
//
//

STDMETHODIMP
CSymMgr::AddModule(IModule **ppModule, MODULE_INFO *ModuleInfo)
{
	//
	// Make sure this module doesn't overlap any existing module
	//
	if ( (NULL != GetModuleByAddress(ModuleInfo->BaseAddress)) ||
		 (NULL != GetModuleByAddress(ModuleInfo->BaseAddress + ModuleInfo->Size)) )
		 return E_FAIL;	// overlaps

	CModule *Module = CModule::CreateNewModule(ModuleInfo, m_pICreateTypeLib);
	if (!Module)
		return E_FAIL;

	Module->AddRef();
	m_ModuleList.AddHead(Module);

	return Module->QueryInterface(IID_IModule, (void **)ppModule);
}

STDMETHODIMP
CSymMgr::GetModuleByName(IModule **ppIModule, BSTR Name)
{
	CModule *Module = GetModuleByName(Name);
	if (!Module)	{
		*ppIModule = NULL;
		return E_FAIL;
	}
	return Module->QueryInterface(IID_IModule, (void **)ppIModule);
}

STDMETHODIMP
CSymMgr::GetModuleByAddress(IModule **ppIModule, DWORD Address)
{
	CModule *Module = GetModuleByAddress(Address);
	if (!Module)	{
		*ppIModule = NULL;
		return E_FAIL;
	}
	return Module->QueryInterface(IID_IModule, (void **)ppIModule);
}

CModule *
CSymMgr::GetModuleByAddress(DWORD Address)
{
	for (POSITION pos=m_ModuleList.GetHeadPosition();pos!=NULL; )	{
		CModule *Module = m_ModuleList.GetNext(pos);
		if ( Module->Contains( Address ) )
			return Module;
	}
	return NULL;
}
CModule *
CSymMgr::GetModuleByName(OLECHAR *Name)
{
	for (POSITION pos=m_ModuleList.GetHeadPosition();pos!=NULL; )	{
		CModule *Module = m_ModuleList.GetNext(pos);
		if ( !wcscmp(Module->Name(), Name) )
			return Module;
	}
	return NULL;

}

STDMETHODIMP
CSymMgr::EnumModules(IEnumModules **ppEnum)
{
	typedef CComEnum<IEnumModules, &IID_IEnumModules, IModule *, _CopyInterface<IModule> > CEnumModules;
	CComObject<CEnumModules> *Enum = new CComObject<CEnumModules>;

	IModule **Modules = new IModule* [m_ModuleList.GetCount()];
	POSITION pos; int i;
	for(pos=m_ModuleList.GetHeadPosition(), i=0;pos!=NULL; i++ )
		Modules[i] = m_ModuleList.GetNext(pos);

	Enum->Init(&Modules[0], &Modules[m_ModuleList.GetCount()], NULL, AtlFlagTakeOwnership);

	//
	// I'm not sure why this is necessary, but this is the technique used by
	// Microsoft code using the CComEnum<> template.
	//
	HRESULT hr = Enum->_InternalQueryInterface(IID_IEnumModules, (void**)ppEnum);
	if (FAILED(hr))
		delete Enum;
	
	return hr;
}

//
//
// Symbol Methods -----------------------------------------------
//
//

STDMETHODIMP
CSymMgr::AddSymbol(ISymbol **ppSymbol, SYMBOL_INFO *SymbolInfo)
{
	//
	// Find the containing module for this symbol.  If it doesn't
	// live in any known module, put it with the orphans.
	//
	CModule *Module = GetModuleByAddress(SymbolInfo->Address);
	if (!Module)
		Module = m_pIOrphanModule;

	return Module->AddSymbol(ppSymbol, SymbolInfo);
}

STDMETHODIMP
CSymMgr::GetSymbolByName(ISymbol **ppSymbol, BSTR Name)
{
	//
	// The Name should be of the form:
	//	[ Module! ] < SymbolName | PartialName* >
	//
	// BUGBUG: Fix this...
	//
	POSITION pos;
	for (pos=m_ModuleList.GetHeadPosition();pos!=NULL; )	{
		CModule *Module = m_ModuleList.GetNext(pos);
		if (SUCCEEDED(Module->GetSymbolByName(ppSymbol, Name)))
			return S_OK;
	}

	*ppSymbol = NULL;
	return E_FAIL;
}

STDMETHODIMP
CSymMgr::GetSymbolByAddress(ISymbol **ppSymbol, DWORD Address)
{
	CModule *Module = GetModuleByAddress(Address);
	if (!Module)
		Module = m_pIOrphanModule;


	return Module->GetSymbolByAddress(ppSymbol, Address);
}

STDMETHODIMP
CSymMgr::EnumSymbols(IEnumSymbols **ppEnum)
{
	//
	// Iterate through each symbol, getting an IEnumSymbols
	// for each module.  Then, dump all the acquired pointers
	// into a new enumeration.
	//

	int NumberOfModules = m_ModuleList.GetCount();
	IEnumSymbols **EnumSymbols = new IEnumSymbols *[NumberOfModules];
	
	CTypedPtrList<CPtrList, ISymbol *>	SymbolList;

	POSITION pos; int i;
	for (pos=m_ModuleList.GetHeadPosition(), i=0;pos!=NULL; i++ )	{
		//
		// Get the next module in the list
		//
		CModule *Module = m_ModuleList.GetNext(pos);

		//
		// Get an enumeration for the symbols in this module
		//
		if (FAILED(Module->EnumSymbols(&EnumSymbols[i])))
			EnumSymbols[i] = NULL;

		//
		// Empty all of the symbols into the CList
		//
		if (EnumSymbols[i])	{
			ISymbol *pISym;
			DWORD Got;
			HRESULT h = EnumSymbols[i]->Next(1, &pISym, &Got);
			while (Got && SUCCEEDED(h))	{
				SymbolList.AddHead(pISym);
				h = EnumSymbols[i]->Next(1, &pISym, &Got);
			}
		}
	}

	//
	// Free the symbol enumerators from above
	//
	for (int j=0;j<NumberOfModules;j++)	{
		EnumSymbols[j]->Release();
	}
	delete [] EnumSymbols;

	//
	// Transfer the interface pointers from the SymbolList to a contiguous
	// array so that ATL can work for us.
	//
	int NumberOfSymbols = SymbolList.GetCount();
	ISymbol **SymbolArray = new ISymbol *[NumberOfSymbols];

	for (pos=SymbolList.GetHeadPosition(), i=0; pos!=NULL; i++)
		SymbolArray[i] = SymbolList.GetNext(pos);

	typedef CComEnum<IEnumSymbols, &IID_IEnumSymbols, ISymbol *, _CopyInterface<ISymbol> > CEnumSymbols;
	CComObject<CEnumSymbols> *Enum = new CComObject<CEnumSymbols>;

	Enum->Init(&SymbolArray[0], &SymbolArray[SymbolList.GetCount()], NULL, AtlFlagTakeOwnership);

	//
	// I'm not sure why this is necessary, but this is the technique used by
	// Microsoft code using the CComEnum<> template.
	//
	HRESULT hr = Enum->_InternalQueryInterface(IID_IEnumSymbols, (void**)ppEnum);
	if (FAILED(hr))
		delete Enum;
	
	return hr;
}

ITypeInfo *
CSymMgr::BindTypeInfo(OLECHAR *Name)
{
	CComPtr<ITypeInfo> pITypeInfo;
	CComPtr<ITypeComp> pITypeComp;
	LCID lcid = MAKELCID(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), SORT_DEFAULT);


	HRESULT hash = ::LHashValOfName(lcid, Name);
	HRESULT hr = m_pITypeComp->BindType(Name, hash, &pITypeInfo, &pITypeComp );
	if ( FAILED(hr) )
		return NULL;

	pITypeInfo->AddRef();
	return pITypeInfo;
}

void
CSymMgr::BuildElemdescFromHtype(ELEMDESC *Elemdesc, ICreateTypeInfo2 *pICreateTypeInfo, HTYPE Type)
{
	if ( IS_STANDARD_HTYPE( Type ) )	{
		Elemdesc->tdesc.vt = HTYPE_TO_VT( Type );
	} else {
		Elemdesc->tdesc.vt = VT_USERDEFINED;
		Elemdesc->tdesc.hreftype = GetRefType( pICreateTypeInfo, Type );
	}
//		Elemdesc->paramdesc = { 0, 0 } // default params
}

HREFTYPE
CSymMgr::GetRefType(ICreateTypeInfo2 *pICreateTypeInfo, HTYPE Handle )
{
	CType *Type = (CType *)Handle;
	return Type->GetRefType(pICreateTypeInfo);
}


STDMETHODIMP
CSymMgr::Extract(IDisImg *pIImg)
{
	//
	// Here, we will eventually determine what type of debug
	// info is present in the module, then load the appropriate
	// extractor for that type.  For now, we just use CSmxImageHlp
	//

	//
	// Create a symbol extractor instance
	//
	CComPtr<IDisSmX> pISmX;
	HRESULT h = CoCreateInstance(CLSID_SmxImageHlp, NULL, CLSCTX_ALL, IID_IDisSmX, (void **)&pISmX);
	if ( FAILED(h) )	{
		return h;
	}
	
	//
	// extract the symbols from the image
	//
	h = pISmX->Extract( pIImg, (IDisSymMgr *)this);
	if ( FAILED(h) )	{
		return h;
	}

	//
	// Make a symbol for each import
	//
	CComPtr<IDisEnumImports> pEnumImports;
	IMG_IMPORT import;
	h = pIImg->EnumImports(&pEnumImports);
	if ( FAILED(h) )	{
		return S_OK;	// well, that's OK.
	}
	DWORD dwGot;
	h = pEnumImports->Next(1, &import, &dwGot);
	while ( SUCCEEDED(h) && dwGot ) {
//		printf("IMPORT: %ws!%ws Addr: %Xh\n", import.Module, import.Name, import.Address);

		wchar_t *w = new wchar_t [ wcslen(import.Name) + 9 ];
		swprintf(w, L"__imp__%ws", import.Name);

		SYMBOL_INFO SymbolInfo;
		SymbolInfo.Name			= ::SysAllocString(w);
		SymbolInfo.DocString	= import.Module;
		SymbolInfo.Address		= import.Address;
		SymbolInfo.Size			= 4;
		SymbolInfo.SymKind		= SKIND_GLOBAL;
		SymbolInfo.Global.Type	= STANDARD_HTYPE( VT_UI4 );

		AddSymbol(NULL, &SymbolInfo);

		::SysFreeString(import.Name);
		::SysFreeString(import.Module);
		::SysFreeString(SymbolInfo.Name);
		delete [] w;
		
		h =  pEnumImports->Next(1, &import, &dwGot);
	}

	return S_OK;
}