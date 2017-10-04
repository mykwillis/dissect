#include "project.h"
#include "CType.h"

//
//
// Copy Routines	--------------------------------------
//
// These routines perform a deep copy of a symbol.
//
//

void
CopyTypeInfoAlias(ALIAS_INFO &Dest, ALIAS_INFO &Source)
{
	Dest.Type = Source.Type;
	if ( !IS_STANDARD_HTYPE(Source.Type) )
		((IType *)(Dest.Type))->AddRef();
}
void
CopyTypeInfoEnum(ENUM_INFO &Dest, ENUM_INFO &Source)
{
	Dest.NumberOfMembers = Source.NumberOfMembers;
	Dest.Values = new DWORD[ Source.NumberOfMembers ];
	Dest.Names = new BSTR[ Source.NumberOfMembers ];
	for (int i=0;i<Source.NumberOfMembers;i++)	{
		Dest.Values[i] = Source.Values[i];
		Dest.Names[i] = ::SysAllocString( Source.Names[i] );
	}
}
void
CopyTypeInfoRecord(RECORD_INFO &Dest, RECORD_INFO &Source)
{
	Dest.NumberOfMembers = Source.NumberOfMembers;
	Dest.Types = new HTYPE[ Source.NumberOfMembers ];
	Dest.Names = new BSTR[ Source.NumberOfMembers ];
	for (int i=0;i<Source.NumberOfMembers;i++)	{
		Dest.Types[i] = Source.Types[i];
		if ( !IS_STANDARD_HTYPE(Source.Types[i]) )
			((IType *)(Dest.Types[i]))->AddRef();
		Dest.Names[i] = ::SysAllocString( Source.Names[i] );
	}
}
void
CopyTypeInfoUnion(UNION_INFO &Dest, UNION_INFO &Source)
{
	Dest.NumberOfMembers = Source.NumberOfMembers;
	Dest.Types = new HTYPE[ Source.NumberOfMembers ];
	Dest.Names = new BSTR[ Source.NumberOfMembers ];
	for (int i=0;i<Source.NumberOfMembers;i++)	{
		Dest.Types[i] = Source.Types[i];
		if ( !IS_STANDARD_HTYPE(Source.Types[i]) )
			((IType *)(Dest.Types[i]))->AddRef();
		Dest.Names[i] = ::SysAllocString( Source.Names[i] );
	}
}
void
CopyTypeInfo(TYPE_INFO &Dest, TYPE_INFO &Source)
{
	Dest.Name		= ::SysAllocString( Source.Name );
	Dest.DocString	= ::SysAllocString( Source.DocString );
	Dest.Size		= Source.Size;
	Dest.TypeKind	= Source.TypeKind;

	switch( Source.TypeKind )	{
	case TKIND_UNION:
		CopyTypeInfoUnion(Dest.Union, Source.Union);
		break;
	case TKIND_RECORD:
		CopyTypeInfoRecord(Dest.Record, Source.Record);
		break;
	case TKIND_ENUM:
		CopyTypeInfoEnum(Dest.Enum, Source.Enum);
		break;
	case TKIND_ALIAS:
		CopyTypeInfoAlias(Dest.Alias, Source.Alias);
		break;
	default:
		_ASSERT(0);
	}

}

//
//
// Release Routines	-----------------------------------
//
// These routines release all resources associated
// with a symbol.
//
//

void
ReleaseTypeInfoAlias(ALIAS_INFO &Alias)
{
	if ( !IS_STANDARD_HTYPE(Alias.Type) )
		((IType *)(Alias.Type))->Release();
}
void
ReleaseTypeInfoEnum(ENUM_INFO &Enum)
{
	for (int i=0;i<Enum.NumberOfMembers;i++)	{
		::SysFreeString( Enum.Names[i] );
	}
	delete [] Enum.Names;
	delete [] Enum.Values;
}
void
ReleaseTypeInfoRecord(RECORD_INFO &Record)
{
	for (int i=0;i<Record.NumberOfMembers;i++)	{
		if ( !IS_STANDARD_HTYPE(Record.Types[i]) )
			((IType *)(Record.Types[i]))->Release();
		::SysFreeString( Record.Names[i] );
	}
	delete [] Record.Types;
	delete [] Record.Names;
}
void
ReleaseTypeInfoUnion(UNION_INFO &Union)
{
	for (int i=0;i<Union.NumberOfMembers;i++)	{
		if ( !IS_STANDARD_HTYPE(Union.Types[i]) )
			((IType *)(Union.Types[i]))->Release();
		::SysFreeString( Union.Names[i] );
	}
	delete [] Union.Types;
	delete [] Union.Names;
}
void
ReleaseTypeInfo(TYPE_INFO &TypeInfo)
{
	::SysFreeString( TypeInfo.Name );

	switch( TypeInfo.TypeKind )	{
	case TKIND_UNION:
		ReleaseTypeInfoUnion(TypeInfo.Union);
		break;
	case TKIND_RECORD:
		ReleaseTypeInfoRecord(TypeInfo.Record);
		break;
	case TKIND_ENUM:
		ReleaseTypeInfoEnum(TypeInfo.Enum);
		break;
	case TKIND_ALIAS:
		ReleaseTypeInfoAlias(TypeInfo.Alias);
		break;
	default:
		_ASSERT(0);
	}
}

//
//
// Read Routines	--------------------------------------
//
// These routines read a TYPE_INFO structure in from
// an ITypeInfo2 interface.
//
//

HRESULT
ReadTypeInfoRecord(ITypeInfo2 *pITypeInfo, RECORD_INFO &Record)
{
	TYPEATTR *TypeAttr;
	pITypeInfo->GetTypeAttr(&TypeAttr);

	//
	// Allocate space for the Types and Names
	//
	Record.NumberOfMembers = TypeAttr->cVars;
	Record.Types = new HTYPE[Record.NumberOfMembers];
	Record.Names = new BSTR[Record.NumberOfMembers];

	//
	// Get the names
	//
	UINT Count;
	pITypeInfo->GetNames(MEMBERID_NIL, Record.Names, Record.NumberOfMembers, &Count);

	//
	// Get an HTYPE for each member.  We have to convert this
	// somehow...
	//
	for (int i=0;i<Record.NumberOfMembers;i++)	{
		//pITypeInfo->GetVarDesc(0, &VarDesc);
		//if (VT_USERDEFINED == VarDesc.elemdescVar.tdesc.vt)	{
		//	Record.Types[i] = VarDesc.elemdescVar.tdesc.hreftype;
		//}
		Record.Types[i] = (HTYPE)0;	// BUGBUG
	}

	pITypeInfo->ReleaseTypeAttr(TypeAttr);

	return S_OK;
}
HRESULT
ReadTypeInfoEnum(ITypeInfo2 *pITypeInfo, ENUM_INFO &Enum)
{
	TYPEATTR *TypeAttr;
	pITypeInfo->GetTypeAttr(&TypeAttr);

	//
	// Allocate space for the Types and Names
	//
	Enum.NumberOfMembers = TypeAttr->cVars;
	Enum.Values = new DWORD[Enum.NumberOfMembers];
	Enum.Names = new BSTR[Enum.NumberOfMembers];

	//
	// Get the names
	//
	UINT Count;
	pITypeInfo->GetNames(MEMBERID_NIL, Enum.Names, Enum.NumberOfMembers, &Count);

	//
	// Get the values...
	// somehow...
	//
	for (int i=0;i<Enum.NumberOfMembers;i++)	{
		//pITypeInfo->GetVarDesc(0, &VarDesc);
		//if (VT_USERDEFINED == VarDesc.elemdescVar.tdesc.vt)	{
		//	Enum.Types[i] = VarDesc.elemdescVar.tdesc.hreftype;
		//}
		Enum.Values[i] = (DWORD)0;	// BUGBUG
	}

	pITypeInfo->ReleaseTypeAttr(TypeAttr);

	return S_OK;
}

HRESULT
ReadTypeInfoUnion(ITypeInfo2 *pITypeInfo, UNION_INFO &Union)
{
	TYPEATTR *TypeAttr;
	pITypeInfo->GetTypeAttr(&TypeAttr);

	//
	// Allocate space for the Types and Names
	//
	Union.NumberOfMembers = TypeAttr->cVars;
	Union.Types = new HTYPE[Union.NumberOfMembers];
	Union.Names = new BSTR[Union.NumberOfMembers];

	//
	// Get the names
	//
	UINT Count;
	pITypeInfo->GetNames(MEMBERID_NIL, Union.Names, Union.NumberOfMembers, &Count);

	//
	// Get an HTYPE for each member.  We have to convert this
	// somehow...
	//
	for (int i=0;i<Union.NumberOfMembers;i++)	{
		//pITypeInfo->GetVarDesc(0, &VarDesc);
		//if (VT_USERDEFINED == VarDesc.elemdescVar.tdesc.vt)	{
		//	Union.Types[i] = VarDesc.elemdescVar.tdesc.hreftype;
		//}
		Union.Types[i] = (HTYPE)0;	// BUGBUG
	}

	pITypeInfo->ReleaseTypeAttr(TypeAttr);

	return S_OK;
}
HRESULT
ReadTypeInfoAlias(ITypeInfo2 *pITypeInfo, ALIAS_INFO &Alias)
{
	TYPEATTR *TypeAttr;
	pITypeInfo->GetTypeAttr(&TypeAttr);
	Alias.Type = (HTYPE)0;
	pITypeInfo->ReleaseTypeAttr(TypeAttr);

	return S_OK;
}
//static
HRESULT
CType::ReadTypeInfo(ITypeInfo2 *pITypeInfo, TYPE_INFO &TypeInfo)
{
	HRESULT h;

	//
	// Get the TKIND and verify it's one we support
	//
	h = pITypeInfo->GetTypeKind(&TypeInfo.TypeKind);
	if ( FAILED(h) )
		return h;
	if (    TypeInfo.TypeKind != TKIND_RECORD	&&
			TypeInfo.TypeKind != TKIND_ENUM		&&
			TypeInfo.TypeKind != TKIND_ALIAS	&&
			TypeInfo.TypeKind != TKIND_UNION )
		return E_FAIL;

	//
	// Get the name and docstring
	//
	h = pITypeInfo->GetDocumentation(MEMBERID_NIL, &TypeInfo.Name, &TypeInfo.DocString, NULL, NULL);
	if ( FAILED(h) )
		return h;


	TYPEATTR *TypeAttr;
	h = pITypeInfo->GetTypeAttr(&TypeAttr);

	//
	// Get the size
	//
	TypeInfo.Size = TypeAttr->cbSizeInstance;

	pITypeInfo->ReleaseTypeAttr(TypeAttr);

	//
	// Switch out based on specific type kind
	//
	switch(TypeInfo.TypeKind)	{
	case TKIND_RECORD:
		h = ReadTypeInfoRecord(pITypeInfo, TypeInfo.Record);
		break;
	case TKIND_ENUM:
		h = ReadTypeInfoEnum(pITypeInfo, TypeInfo.Enum);
		break;
	case TKIND_ALIAS:
		h = ReadTypeInfoAlias(pITypeInfo, TypeInfo.Alias);
		break;
	case TKIND_UNION:
		h = ReadTypeInfoUnion(pITypeInfo, TypeInfo.Union);
		break;
	default:
		_ASSERT(0);
		break;
	}

	if (FAILED(h))	{
		::SysFreeString( TypeInfo.Name );
		::SysFreeString( TypeInfo.DocString );
		TypeInfo.Name = NULL;
		TypeInfo.DocString = NULL;
		return h;
	}

	return S_OK;
}

//
//
// Write Routines	-------------------------------------
//
// These routines write a TYPE_INFO structure to a given
// ICreateTypeInfo2 interface.
//
//

HRESULT
WriteTypeInfoRecord(ICreateTypeInfo2 *pICreateTypeInfo, RECORD_INFO &Record)
{
	//
	// Translate the (Dissect) HTYPEs to (type library) HREFTYPEs
	//
	HREFTYPE *RefTypes = new HREFTYPE[Record.NumberOfMembers];
	for (int i=0;i<Record.NumberOfMembers;i++)	{
		if ( IS_STANDARD_HTYPE( Record.Types[i] ) )
			continue;

		RefTypes[i] = ((CType *)Record.Types[i])->GetRefType( pICreateTypeInfo );
	}


	//
	// Fill in the common areas of a VARDESC
	//
	VARDESC vardesc;
	vardesc.memid		= MEMBERID_NIL;	// should be ignored, anyhow
	vardesc.lpstrSchema = NULL;			// reserved

	vardesc.wVarFlags	= 0;
	vardesc.varkind		= VAR_PERINSTANCE;
//	vardesc.elemdescVar.paramdesc	= { 0, 0 };	// used for default parameters

	//
	// Loop through all of the members of this record, filling in
	// the VARDESC fields appropriately before calling AddVarDesc()
	//
	DWORD NextOffset = vardesc.oInst = 0;
	for ( i=0;i<Record.NumberOfMembers;i++)	{
		//
		// Get the TYPEDESC for this member
		//
		if ( IS_STANDARD_HTYPE( Record.Types[i] ) )	{
			vardesc.elemdescVar.tdesc.vt	= HTYPE_TO_VT( Record.Types[i] );
		} else {
			vardesc.elemdescVar.tdesc.vt	= VT_USERDEFINED;
			vardesc.elemdescVar.tdesc.hreftype	= RefTypes[i];
		}
		
		//
		// Calculate the offset of the next member
		// BUGBUG: We have to take alignment into account here!
		//
		vardesc.oInst = NextOffset;
		if ( IS_STANDARD_HTYPE(Record.Types[i]) )
			NextOffset += 4;	//BUGBUG: Must get actual size here!!!
		else
			NextOffset += ((CType *)Record.Types[i])->GetSize();

		//
		// Add the VARDESC for this member, and set its name
		//
		HRESULT hr = pICreateTypeInfo->AddVarDesc(i, &vardesc);
		if (FAILED(hr)) {
			delete [] RefTypes;
			return hr;
		}
		hr = pICreateTypeInfo->SetVarName(i, Record.Names[i]);
		if (FAILED(hr)) {
			delete [] RefTypes;
			return hr;
		}
	}

	delete [] RefTypes;

	return S_OK;
}
HRESULT
WriteTypeInfoUnion(ICreateTypeInfo2 *pICreateTypeInfo, UNION_INFO &Union)
{
	//
	// Translate the (Dissect) HTYPEs to (type library) HREFTYPEs
	//
	HREFTYPE *RefTypes = new HREFTYPE[Union.NumberOfMembers];
	for (int i=0;i<Union.NumberOfMembers;i++)	{
		if ( IS_STANDARD_HTYPE( Union.Types[i] ) )
			continue;

		RefTypes[i] = ((CType *)(Union.Types[i]))->GetRefType( pICreateTypeInfo );
	}


	//
	// Fill in the common areas of a VARDESC
	//
	VARDESC vardesc;
	vardesc.memid		= MEMBERID_NIL;	// should be ignored, anyhow
	vardesc.lpstrSchema = NULL;			// reserved

	vardesc.wVarFlags	= 0;
	vardesc.varkind		= VAR_PERINSTANCE;
	vardesc.oInst		= 0;			// all members of a union are at offset 0
//	vardesc.elemdescVar.paramdesc	= { 0, 0 };	// used for default parameters

	//
	// Loop through all of the members of this record, filling in
	// the VARDESC fields appropriately before calling AddVarDesc()
	//
	for ( i=0;i<Union.NumberOfMembers;i++)	{
		//
		// Get the TYPEDESC for this member
		//
		if ( IS_STANDARD_HTYPE( Union.Types[i] ) )	{
			vardesc.elemdescVar.tdesc.vt	= HTYPE_TO_VT( Union.Types[i] );
		} else {
			vardesc.elemdescVar.tdesc.vt	= VT_USERDEFINED;
			vardesc.elemdescVar.tdesc.hreftype	= RefTypes[i];
		}
		
		//
		// Add the VARDESC for this member, and set its name
		//
		HRESULT hr = pICreateTypeInfo->AddVarDesc(i, &vardesc);
		if (FAILED(hr)) {
			delete [] RefTypes;
			return hr;
		}
		hr = pICreateTypeInfo->SetVarName(i, Union.Names[i]);
		if (FAILED(hr)) {
			delete [] RefTypes;
			return hr;
		}
	}

	delete [] RefTypes;

	return S_OK;
}
HRESULT
WriteTypeInfoEnum(ICreateTypeInfo2 *pICreateTypeInfo, ENUM_INFO &Enum)
{
	//
	// Loop through all of the members of this enum, creating a VARIANT of
	// kind VAR_CONST for each one.  Each of these VARIANTS will then be
	// added in the proper index of the TKIND_ENUM along with its name.
	//
	VARIANT variant;
	variant.vt = VT_UI4;	// BUGBUG: 2 bytes or 4?

	VARDESC vardesc;
	vardesc.memid		= MEMBERID_NIL;	// should be ignored, anyhow
	vardesc.lpstrSchema = NULL;			// reserved
	vardesc.lpvarValue	= &variant;		// constant value
	vardesc.wVarFlags	= 0;
	vardesc.varkind		= VAR_CONST;
	vardesc.elemdescVar.tdesc.vt	= VT_UI4;	// BUGBUG: is this supposed to be 2 bytes?
//	vardesc.elemdescVar.paramdesc	= { 0, 0 };	// used for default parameters

	for (int i=0;i<Enum.NumberOfMembers;i++)	{
		variant.ulVal = Enum.Values[i];
		HRESULT hr = pICreateTypeInfo->AddVarDesc(i, &vardesc);
		if (FAILED(hr)) {
			return hr;
		}
		hr = pICreateTypeInfo->SetVarName(i, Enum.Names[i]);
		if (FAILED(hr)) {
			return hr;
		}
	}

	return S_OK;
}
HRESULT
WriteTypeInfoAlias(ICreateTypeInfo2 *pICreateTypeInfo, ALIAS_INFO &Alias)
{
	//
	// Set up the alias
	//
	TYPEDESC typedesc;
	if ( IS_STANDARD_HTYPE( Alias.Type ) )	{
		//
		// Standard HTYPEs can be statically converted to VARTYPEs
		//
		typedesc.vt = HTYPE_TO_VT( Alias.Type );
	} else {
		//
		// Convert the HTYPE to an HREFTYPE and mark this VARTYPE as
		// user-defined.
		//
		typedesc.vt = VT_USERDEFINED;
		typedesc.hreftype = ((CType *)Alias.Type)->GetRefType(pICreateTypeInfo);
		if (!typedesc.hreftype)	{
			return E_FAIL;	// the HTYPE was invalid
		}
	}

	//
	// Punch it in.
	//
	HRESULT hr = pICreateTypeInfo->SetTypeDescAlias(&typedesc);
	if ( FAILED(hr) )	{
		return hr;
	}

	return S_OK;
}

//static 
HRESULT
CType::WriteTypeInfo(ICreateTypeInfo2 *pICreateTypeInfo, TYPE_INFO *TypeInfo)
{
	//
	// Write the name and docstring
	//
	HRESULT h = pICreateTypeInfo->SetName(TypeInfo->Name);
	if ( FAILED(h) )
		return h;

	pICreateTypeInfo->SetDocString(TypeInfo->DocString);	// silent failure

	//
	// Write the size to custom data
	//
	VARIANT v;
	v.vt = VT_UI4;
	v.ulVal = TypeInfo->Size;
	pICreateTypeInfo->SetCustData( GUID_CD_Size, &v );		// silent failure

	//
	// Switch out based on specific type kind
	//
	switch(TypeInfo->TypeKind)	{
	case TKIND_RECORD:
		h = WriteTypeInfoRecord(pICreateTypeInfo, TypeInfo->Record);
		break;
	case TKIND_ENUM:
		h = WriteTypeInfoEnum(pICreateTypeInfo, TypeInfo->Enum);
		break;
	case TKIND_ALIAS:
		h = WriteTypeInfoAlias(pICreateTypeInfo, TypeInfo->Alias);
		break;
	case TKIND_UNION:
		h = WriteTypeInfoUnion(pICreateTypeInfo, TypeInfo->Union);
		break;
	default:
		_ASSERT(0);
		break;
	}

	return S_OK;
}

STDMETHODIMP
CType::Update(TYPE_INFO *TypeInfo)
{
	//
	// We can only Update() if our ITypeInfo interface points to an object
	// that supports ICreateTypeInfo2
	//
	CComQIPtr<ICreateTypeInfo2, &IID_ICreateTypeInfo2> pICreateTypeInfo(m_pITypeInfo);
	if ( !pICreateTypeInfo )
		return E_FAIL;

	return WriteTypeInfo( pICreateTypeInfo, TypeInfo );
}



STDMETHODIMP
CType::GetTypeInfo(TYPE_INFO **TypeInfo)
{
	*TypeInfo = new TYPE_INFO;
	::CopyTypeInfo(**TypeInfo, m_TypeInfo);
	return S_OK;
}

STDMETHODIMP
CType::ReleaseTypeInfo(TYPE_INFO *TypeInfo)
{
	_ASSERT( NULL != TypeInfo );
	::ReleaseTypeInfo(*TypeInfo);
	delete TypeInfo;
	return S_OK;
}

//static 
CType *
CType::CreateTypeFromTypeInfo(ITypeInfo2 *pITypeInfo)
{
	_ASSERT(pITypeInfo != NULL);

	//
	// Allocate and initialize the new CType object
	//
	CType *Type = new CComObject<CType>();
	Type->m_pITypeInfo = pITypeInfo;

	//
	// Read the TYPE_INFO in from the given ITypeInfo
	//
	ReadTypeInfo(pITypeInfo, Type->m_TypeInfo);

	return Type;
}

//static
CType *
CType::CreateNewType(TYPE_INFO *TypeInfo, ICreateTypeLib2 *pICreateTypeLib)
{
	_ASSERT(NULL != TypeInfo);
	_ASSERT(NULL != pICreateTypeLib);

	//
	// Allocate the new CType object
	//
	CType *Type = new CComObject<CType>();

	//
	// Copy the TYPE_INFO from that given
	//
	CopyTypeInfo(Type->m_TypeInfo, *TypeInfo);
	
	//
	// Create a new ICreateTypeInfo in this type lib
	//
	CComPtr<ICreateTypeInfo2> pICreateTypeInfo;
	if (FAILED(pICreateTypeLib->CreateTypeInfo(TypeInfo->Name, TypeInfo->TypeKind, (ICreateTypeInfo **)&pICreateTypeInfo)))	{
		delete Type;
		return NULL;
	}
	
	//
	// Get an ITypeInfo to store in the CType
	//
	if (FAILED(pICreateTypeInfo->QueryInterface(IID_ITypeInfo, reinterpret_cast<void **>(&Type->m_pITypeInfo))))	{
		delete Type;
		return NULL;
	}

	//
	// Commit the TYPE_INFO to the ITypeInfo
	//
	WriteTypeInfo(pICreateTypeInfo, &Type->m_TypeInfo);

	return Type;
}

HREFTYPE
CType::GetRefType(ICreateTypeInfo2 *pICreateTypeInfo)
{
	HREFTYPE h;

	if (FAILED(pICreateTypeInfo->AddRefTypeInfo(m_pITypeInfo, &h)))
		return (HREFTYPE)0;
	return h;

}

STDMETHODIMP
CType::SetMemberValue(int /*Position*/, DWORD /*Value*/)
{
	return E_NOTIMPL;
}
STDMETHODIMP
CType::SetMemberName(int /*Position*/, BSTR /*Name*/)
{
	return E_NOTIMPL;
}
STDMETHODIMP
CType::SetMemberType(int /*Position*/, HTYPE)
{
	return E_NOTIMPL;
}
STDMETHODIMP
CType::SetName(BSTR /*Name*/)
{
	return E_NOTIMPL;
}
STDMETHODIMP
CType::SetDocString(BSTR /*DocString*/)
{
	return E_NOTIMPL;
}
CType::~CType()
{
	::ReleaseTypeInfo(m_TypeInfo);
}