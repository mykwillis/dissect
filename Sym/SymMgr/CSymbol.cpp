#include "project.h"
#include "CSymbol.h"
#include "CType.h"

void
BuildElemdescFromHtype(ELEMDESC *Elemdesc, ICreateTypeInfo2 *pICreateTypeInfo, HTYPE Type)
{
	if ( IS_STANDARD_HTYPE( Type ) )	{
		Elemdesc->tdesc.vt = HTYPE_TO_VT( Type );
	} else {
		Elemdesc->tdesc.vt = VT_USERDEFINED;
		Elemdesc->tdesc.hreftype = ((CType *)Type)->GetRefType( pICreateTypeInfo );
	}
//		Elemdesc->paramdesc = { 0, 0 } // default params
}

void
CopySymbolInfoLocal(LOCAL_INFO& Dest, LOCAL_INFO& Source)
{
	Dest.Dummy = Source.Dummy;	// !!
}
void
CopySymbolInfoGlobal(GLOBAL_INFO& Dest, GLOBAL_INFO& Source)
{
	Dest.Type = Source.Type;
	if ( !IS_STANDARD_HTYPE(Dest.Type) ) 
		((IType *)Dest.Type)->AddRef();
}
void
CopySymbolInfoFunc(FUNCTION_INFO& Dest, FUNCTION_INFO& Source)
{
	Dest.FuncKind = Source.FuncKind;
	Dest.InvKind = Source.InvKind;
	Dest.CallConv = Source.CallConv;
	Dest.ReturnType = Source.ReturnType;
	if ( !IS_STANDARD_HTYPE(Dest.ReturnType) ) ((IType *)Dest.ReturnType)->AddRef();
	Dest.NumberOfParams = Source.NumberOfParams;
	Dest.Types = new HTYPE[Dest.NumberOfParams];
	Dest.Names = new BSTR[Dest.NumberOfParams];
	for (int i=0;i<Dest.NumberOfParams;i++)	{
		Dest.Types[i] = Source.Types[i];
		if ( !IS_STANDARD_HTYPE(Dest.Types[i]) ) ((IType *)Dest.Types[i])->AddRef();
		Dest.Names[i] = ::SysAllocString( Source.Names[i] );
	}
}
void
CopySymbolInfo(SYMBOL_INFO& Dest, SYMBOL_INFO& Source)
{
	Dest.Name = ::SysAllocString( Source.Name );
	Dest.DocString = ::SysAllocString( Source.DocString );
	Dest.Address = Source.Address;
	Dest.Size = Source.Size;
	Dest.SymKind = Source.SymKind;

	switch( Dest.SymKind )	{
	case SKIND_FUNC:
		CopySymbolInfoFunc(Dest.Function, Source.Function);
		break;
	case SKIND_GLOBAL:
		CopySymbolInfoGlobal(Dest.Global, Source.Global);
		break;
	case SKIND_LOCAL:
		CopySymbolInfoLocal(Dest.Local, Source.Local);
		break;
	case SKIND_UNKNOWN:
		break;
	default:
		_ASSERT(0);
		break;
	}
}
void
ReleaseSymbolInfoLocal(LOCAL_INFO& )
{
	// empty
}
void
ReleaseSymbolInfoGlobal(GLOBAL_INFO& Global)
{
	if ( !IS_STANDARD_HTYPE(Global.Type) ) 
		((IType *)Global.Type)->Release();
}
void
ReleaseSymbolInfoFunc(FUNCTION_INFO& Function)
{
	if ( !IS_STANDARD_HTYPE(Function.ReturnType) ) 
		((IType *)Function.ReturnType)->Release();
	for (int i=0;i<Function.NumberOfParams;i++)	{
		if ( !IS_STANDARD_HTYPE(Function.Types[i]) )
			((IType *)Function.Types[i])->Release();
		::SysFreeString( Function.Names[i] );
	}
	delete [] Function.Types;
	delete [] Function.Names;
}
void
ReleaseSymbolInfo(SYMBOL_INFO& Symbol)
{
	::SysFreeString( Symbol.Name );
	::SysFreeString( Symbol.DocString );
	switch (Symbol.SymKind)	{
	case SKIND_FUNC:
		ReleaseSymbolInfoFunc(Symbol.Function);
		break;
	case SKIND_GLOBAL:
		ReleaseSymbolInfoGlobal(Symbol.Global);
		break;
	case SKIND_LOCAL:
		ReleaseSymbolInfoLocal(Symbol.Local);
		break;
	case SKIND_UNKNOWN:
		break;
	default:
		_ASSERT(0);
		break;
	}
}
STDMETHODIMP
CSymbol::GetSymbolInfo(SYMBOL_INFO **SymbolInfo)
{
	*SymbolInfo = new SYMBOL_INFO;
	::CopySymbolInfo(**SymbolInfo, m_SymbolInfo);
	return S_OK;
}

STDMETHODIMP
CSymbol::ReleaseSymbolInfo(SYMBOL_INFO *SymbolInfo)
{
	_ASSERT( NULL != SymbolInfo );
	::ReleaseSymbolInfo(*SymbolInfo);
	delete SymbolInfo;
	return S_OK;
}

HRESULT
WriteSymbolInfoFunc(ICreateTypeInfo2 *pICreateTypeInfo, int Index, SYMBOL_INFO *SymbolInfo)
{
	FUNCTION_INFO &FunctionInfo = SymbolInfo->Function;
	FUNCDESC funcdesc;
	HRESULT h;

	//
	// Build ELEMDESC for return type
	//
	BuildElemdescFromHtype(&funcdesc.elemdescFunc, pICreateTypeInfo, FunctionInfo.ReturnType);

	//
	// Build ELEMDESCs for each parameter
	//
	ELEMDESC *Elemdesc = new ELEMDESC[FunctionInfo.NumberOfParams];
	for (int i=0;i<FunctionInfo.NumberOfParams;i++)	{
		BuildElemdescFromHtype(&Elemdesc[i], pICreateTypeInfo, FunctionInfo.Types[i]);
	}

	//
	// Fill in the rest of the FUNCDESC
	//

	funcdesc.memid		= MEMBERID_NIL;
	funcdesc.lprgscode	= NULL;
	funcdesc.lprgelemdescParam = Elemdesc;
	funcdesc.funckind	= FunctionInfo.FuncKind;
	funcdesc.invkind	= FunctionInfo.InvKind;
	funcdesc.callconv	= FunctionInfo.CallConv;
	funcdesc.cParams	= (short)FunctionInfo.NumberOfParams;
	funcdesc.cParamsOpt = 0;
	funcdesc.oVft		= 0;
	funcdesc.cScodes	= 0;
	funcdesc.wFuncFlags = 0;

	h = pICreateTypeInfo->AddFuncDesc(Index, &funcdesc);
	if ( FAILED(h) )	{
		delete [] Elemdesc;
		return h;
	}

	//
	// Write out all names (the first name is the function name)
	//
	OLECHAR **AllNames = new OLECHAR *[FunctionInfo.NumberOfParams+1];
	AllNames[0] = SymbolInfo->Name;
	for (i=0;i<FunctionInfo.NumberOfParams;i++)	{
		AllNames[i+1] = FunctionInfo.Names[i];
	}
	h = pICreateTypeInfo->SetFuncAndParamNames(Index, AllNames, FunctionInfo.NumberOfParams+1);
#if 0
		// this should be done in client code

	if ( TYPE_E_AMBIGUOUSNAME == h )	{
		// we have a duplicate name here.  This can happen with 'vftable'
		// symbols for some classes with multiple inheritance, and I imagine
		// it's possible in some other fringe cases as well.
		// Build a unique name by concatenating the address of the symbol
		// to its name.  If this fails, too, just make a unique name up.
		BSTR bsName = ::SysAllocString( Name );
		MakeUniqueNameWithAddress(/* in, out */ &bsName, Address);
		AllNames[0] = bsName;
		h = pICreateTypeInfo->SetFuncAndParamNames(0, AllNames, cParams+1);
		if ( TYPE_E_AMBIGUOUSNAME == h )	{
			// god damn!  just make a unique name up!
			::SysFreeString(bsName);
			bsName = ::SysAllocString(L"Function");
			MakeUniqueNameWithAddress(/* in, out */&bsName, Address);
			AllNames[0] = bsName;
			h = pICreateTypeInfo->SetFuncAndParamNames(Index, AllNames, cParams+1);
		}
		//::SysFreeString(bsName);
	}
#endif
	if ( FAILED(h) )	{
		delete [] AllNames;
		return h;	// BUGBUG: clean up!
	}

	//
	// Write out the DocString
	//
	pICreateTypeInfo->SetFuncDocString( Index, SymbolInfo->DocString );	// silent failure

	//
	// Write out address and size as custom data
	//
	VARIANT v;
	v.vt = VT_UI4;
	v.ulVal = SymbolInfo->Address;
	pICreateTypeInfo->SetFuncCustData(Index, GUID_CD_Address, &v);	// silent failure
	v.ulVal = SymbolInfo->Size;
	pICreateTypeInfo->SetFuncCustData(Index, GUID_CD_Size, &v);		// silent failure

	return S_OK;

}

HRESULT
WriteSymbolInfoGlobal(ICreateTypeInfo2 *pICreateTypeInfo, int Index, SYMBOL_INFO *SymbolInfo)
{
	GLOBAL_INFO& GlobalInfo = SymbolInfo->Global;
	VARDESC vardesc;
	BuildElemdescFromHtype(&vardesc.elemdescVar, pICreateTypeInfo, GlobalInfo.Type);
	vardesc.memid = MEMBERID_NIL;
	vardesc.varkind = VAR_STATIC;
	vardesc.wVarFlags = 0;
	vardesc.oInst = 0;

	HRESULT h = pICreateTypeInfo->AddVarDesc(Index, &vardesc);
	if ( FAILED(h) )	{
		return h;
	}

	h = pICreateTypeInfo->SetVarName(Index, SymbolInfo->Name);
	if ( FAILED(h) )
		return h;

	//
	// Write out the DocString
	//
	if (SymbolInfo->DocString)
		pICreateTypeInfo->SetVarDocString( Index, SymbolInfo->DocString );	// silent failure

	//
	// Write out address and size as custom data
	//
	VARIANT v;
	v.vt = VT_UI4;
	v.ulVal = SymbolInfo->Address;
	pICreateTypeInfo->SetVarCustData(Index, GUID_CD_Address, &v);	// silent failure
	v.ulVal = SymbolInfo->Size;
	pICreateTypeInfo->SetVarCustData(Index, GUID_CD_Size, &v);		// silent failure

	return S_OK;

}

HRESULT
WriteSymbolInfoLocal(ICreateTypeInfo2 *pICreateTypeInfo, int Index, SYMBOL_INFO *SymbolInfo)
{
	return E_NOTIMPL;
}

HRESULT
WriteSymbolInfoUnknown(ICreateTypeInfo2 *pICreateTypeInfo, int Index, SYMBOL_INFO *SymbolInfo)
{
	//
	// We write a symbol of unknown type as a SKIND_GLOBAL
	// with type VT_UI1.  Eventually, this should probably go
	// in as an array of bytes with length==size.
	//
	SYMBOL_INFO SymbolInfo2;
	CopySymbolInfo(SymbolInfo2, *SymbolInfo);
	SymbolInfo2.SymKind = SKIND_GLOBAL;
	SymbolInfo2.Global.Type = STANDARD_HTYPE( VT_UI1 );
	HRESULT h = WriteSymbolInfoGlobal(pICreateTypeInfo, Index, &SymbolInfo2);
	ReleaseSymbolInfo(SymbolInfo2);
	return h;
}


//static
HRESULT
CSymbol::WriteSymbolInfo(ICreateTypeInfo2 *pICreateTypeInfo, int Index, SYMBOL_INFO *SymbolInfo)
{
	HRESULT h;

	//
	// We can't write the common fields of SYMBOL_INFO here, since
	// different symbol types have different methods of saving this
	// information to the type library (i.e., SetFuncName(), SetVarName() )
	// 
	switch( SymbolInfo->SymKind )	{
	case SKIND_FUNC:
		h = WriteSymbolInfoFunc(pICreateTypeInfo, Index, SymbolInfo);
		break;
	case SKIND_GLOBAL:
		h = WriteSymbolInfoGlobal(pICreateTypeInfo, Index, SymbolInfo);
		break;
	case SKIND_LOCAL:
		h = WriteSymbolInfoLocal(pICreateTypeInfo, Index, SymbolInfo);
		break;
	case SKIND_UNKNOWN:
		h = WriteSymbolInfoUnknown(pICreateTypeInfo, Index, SymbolInfo);
		break;

	default:
		_ASSERT(0);
		break;
	}

	return h;
}


BOOL
CSymbol::Contains(DWORD Address)
{
	if ( this->Address() <= Address && 
		( HighAddress() > Address || this->Address() == Address ) )
		return TRUE;
	else
		return FALSE;
}

//static 
CSymbol *
CSymbol::CreateSymbolFromTypeInfo(ITypeInfo2 *pITypeInfo)
{
	return NULL;
}

//static
CSymbol *
CSymbol::CreateNewSymbol(SYMBOL_INFO *SymbolInfo, ICreateTypeInfo2 *pICreateTypeInfo, int Index)
{
	_ASSERT(NULL != SymbolInfo);
	_ASSERT(NULL != pICreateTypeInfo);

	//
	// Allocate the new CSymbol object
	//
	CSymbol *Symbol = new CComObject<CSymbol>();

	//
	// Copy the SYMBOL_INFO from that given
	//
	CopySymbolInfo(Symbol->m_SymbolInfo, *SymbolInfo);

	//
	// Set up other internal CSymbol fields
	//
	Symbol->m_Index = Index;
	pICreateTypeInfo->QueryInterface(IID_ITypeInfo2, (void **)&(Symbol->m_pITypeInfo));

	//
	// Write out the SYMBOL_INFO
	//
	WriteSymbolInfo(pICreateTypeInfo, Symbol->m_Index, &Symbol->m_SymbolInfo);

	//
	// return the symbol
	//
	return Symbol;

}

CSymbol::~CSymbol()
{
	::ReleaseSymbolInfo(m_SymbolInfo);
}