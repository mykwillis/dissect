#include "project.h"
#include "CFunction.h"

/*
typedef struct tagFUNCTION_INFO {
	BSTR		Name;
	BSTR		DocString;
	FUNCKIND	FuncKind;
	INVOKEKIND	InvKind;
	CALLCONV	CallConv;
	DWORD		Address;		// custom
	DWORD		Size;			// custom
	HTYPE		ReturnType;
	int			NumberOfParams;
	[size_is(NumberOfParams)]
	HTYPE *		Types;
	[size_is(NumberOfParams)]
	BSTR *		Names;
} FUNCTION_INFO;
*/

STDMETHODIMP
CFunction::GetFunctionInfo(FUNCTION_INFO **ppFunctionInfo)
{
	_ASSERT( NULL != m_pITypeInfo );
	_ASSERT( MEMBERID_NIL != m_MemberID );

	*ppFunctionInfo = new CFunctionInfo;

	HRESULT h = ReadFunctionInfo(m_pITypeInfo, m_Index, *ppFunctionInfo);
	if ( FAILED(h) )
		delete (CFunctionInfo *) *ppFunctionInfo;

	return h;
}

//static
HRESULT
CFunction::ReadFunctionInfo(ITypeInfo2 *pITypeInfo, int Index, FUNCTION_INFO *pFunctionInfo)
{
	HRESULT h;

	//
	// Grab the FUNCDESC for this function
	//
	FUNCDESC *FuncDesc;
	h = pITypeInfo->GetFuncDesc(Index, &FuncDesc);
	if ( FAILED(h) )
		return E_FAIL;

	//
	// Get the name and docstring
	//
	h = pITypeInfo->GetDocumentation(FuncDesc->memid, &pFunctionInfo->Name, &pFunctionInfo->DocString, NULL, NULL);
	if ( FAILED(h) )	{
		pITypeInfo->ReleaseFuncDesc(FuncDesc);
		return h;
	}


	//
	// Copy over the FUNCKIND, INVOKEKIND, and CALLCONV
	//
	pFunctionInfo->FuncKind		= FuncDesc->funckind;
	pFunctionInfo->InvKind		= FuncDesc->invkind;
	pFunctionInfo->CallConv		= FuncDesc->callconv;

	//
	// Get the base address and size from custom data
	//
	VARIANT v;
	pFunctionInfo->Address = 0;	// init
	h = pITypeInfo->GetFuncCustData( Index, GUID_CD_Address, &v );
	if ( SUCCEEDED(h) )	{
		_ASSERT( v.vt == VT_UI4 );
		pFunctionInfo->Address = v.ulVal;
	}

	pFunctionInfo->Size = 0;
	h = pITypeInfo->GetFuncCustData( Index, GUID_CD_Size, &v );
	if ( SUCCEEDED(h) )	{
		_ASSERT( v.vt == VT_UI4 );
		pFunctionInfo->Size = v.ulVal;
	}

	//
	// Get the return type
	//
	pFunctionInfo->ReturnType = (HTYPE) 0;	// BUGBUG

	//
	// Get the parameter types
	//
	pFunctionInfo->NumberOfParams = FuncDesc->cParams;
	pFunctionInfo->Types = new HTYPE[ pFunctionInfo->NumberOfParams ];
	for (int i=0;i<pFunctionInfo->NumberOfParams;i++)	{
		pFunctionInfo->Types[i] = (HTYPE) 0;	// BUGBUG
	}

	//
	// Get the parameter names
	//
	pFunctionInfo->Names = new BSTR[ pFunctionInfo->NumberOfParams ];
	pITypeInfo->GetNames( FuncDesc->memid, pFunctionInfo->Names, pFunctionInfo->NumberOfParams, NULL );

	pITypeInfo->ReleaseFuncDesc( FuncDesc );

	return S_OK;
}

//static 
HRESULT
CFunction::WriteFunctionInfo(ICreateTypeInfo2 *pICreateTypeInfo, int Index, FUNCTION_INFO *FunctionInfo)
{
	HRESULT h;

	//
	// Create a FUNCDSC for this FUNCTION_INFO
	//
	FUNCDESC FuncDesc;

	//
	// Build ELEMDESC for return type
	//
	BuildElemdescFromHtype(&FuncDesc.elemdescFunc, pICreateTypeInfo, FunctionInfo->ReturnType);

	//
	// Build ELEMDESCs for each parameter
	//
	ELEMDESC *Elemdesc = new ELEMDESC[FunctionInfo->NumberOfParams];
	for (int i=0;i<FunctionInfo->NumberOfParams;i++)	{
		BuildElemdescFromHtype(&Elemdesc[i], pICreateTypeInfo, FunctionInfo->Types[i]);
	}
	FuncDesc.cParams	= (short) FunctionInfo->NumberOfParams;
	FuncDesc.lprgelemdescParam = Elemdesc;
	FuncDesc.cParamsOpt = 0;

	//
	// Copy over the FUNCKIND, INVOKEKIND, and CALLCONV
	//
	FuncDesc.funckind	= FunctionInfo->FuncKind;
	FuncDesc.invkind	= FunctionInfo->InvKind;
	FuncDesc.callconv	= FunctionInfo->CallConv;

	//
	// Fill in the rest of the FUNCDESC
	//
	FuncDesc.memid		= MEMBERID_NIL;
	FuncDesc.lprgscode	= NULL;
	FuncDesc.oVft		= 0;
	FuncDesc.cScodes	= 0;
	FuncDesc.wFuncFlags = 0;

	//
	// Add the FUNCDESC to the ITypeInfo
	//
	h = pICreateTypeInfo->AddFuncDesc(Index, &FuncDesc);
	if ( FAILED(h) )	{
		delete [] Elemdesc;
		return h;
	}

	//
	// Set the function and parameter names
	//
	OLECHAR **AllNames = new OLECHAR *[FuncDesc.cParams+1];
	AllNames[0] = FunctionInfo->Name;
	for (i=0;i<FuncDesc.cParams;i++)	{
		AllNames[i+1] = FunctionInfo->Names[i];
	}
	h = pICreateTypeInfo->SetFuncAndParamNames(Index, AllNames, FuncDesc.cParams+1);
	if ( FAILED(h) )	{
		// non-fatal, though.  We've already added the function...
		delete [] AllNames;
	}

	//
	// Write the docstring (name was already written)
	//
	pICreateTypeInfo->SetFuncDocString(Index, FunctionInfo->Name);

	//
	// Write the address and size to custom data
	//
	VARIANT v;
	v.vt = VT_UI4;
	v.ulVal = FunctionInfo->Address;
	pICreateTypeInfo->SetCustData( GUID_CD_Address, &v );	// silent failure

	v.ulVal = FunctionInfo->Size;
	pICreateTypeInfo->SetCustData( GUID_CD_Size, &v );		// silent failure

	return S_OK;
}

STDMETHODIMP
CFunction::ReleaseFunctionInfo(FUNCTION_INFO *pFunctionInfo)
{
	delete (CFunctionInfo *) pFunctionInfo;
	return S_OK;
}

STDMETHODIMP
CFunction::Attach(ITypeInfo2 *pITypeInfo, int Index)
{
	m_pITypeInfo = pITypeInfo;
	m_Index = Index;
	return S_OK;
}

STDMETHODIMP
CFunction::Update(FUNCTION_INFO *FunctionInfo)
{
	//
	// We can only Update() if our ITypeInfo interface points to an object
	// that supports ICreateTypeInfo2
	//
	CComQIPtr<ICreateTypeInfo2, &IID_ICreateTypeInfo2> pICreateTypeInfo(m_pITypeInfo);
	if ( !pICreateTypeInfo )
		return E_FAIL;

	return WriteFunctionInfo( pICreateTypeInfo, m_Index, FunctionInfo );
}
