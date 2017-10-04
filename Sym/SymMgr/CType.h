#ifndef _CTYPE_H
#define _CTYPE_H

#define IS_STANDARD_HTYPE( htype )	\
	( (DWORD)htype & 0x80000000 )
#define HTYPE_TO_VT( htype )	\
	((VARTYPE)((DWORD)htype & ~0x80000000))

//
// This is the object stored internally by the symbol manager
// to represent a type.  A pointer to this object is also cast
// to an IType for client requests.
//
class CType :
	public IType,
	public CComObjectRoot
{
public:
	BEGIN_COM_MAP(CType)
		COM_INTERFACE_ENTRY(IType)
	END_COM_MAP()

	//
	// IType Methods
	//
	STDMETHOD(GetTypeInfo)(TYPE_INFO **TypeInfo);
	STDMETHOD(ReleaseTypeInfo)(TYPE_INFO *TypeInfo);
	STDMETHOD(Update)(TYPE_INFO *TypeInfo);
	
	STDMETHOD(SetName)(BSTR Name);
	STDMETHOD(SetDocString)(BSTR DocString);
	STDMETHOD(SetMemberName)(int Position, BSTR Name);
	STDMETHOD(SetMemberType)(int Position, HTYPE Type);
	STDMETHOD(SetMemberValue)(int Position, DWORD Value);

#if LATER
	STDMETHOD(EnumTypeMembers)(IEnumTypeMembers **ppEnum);
	STDMETHOD(GetTypeMemberByOffset)(DWORD Offset, BSTR *Name, TYPE_OR_VALUE *TypeOrValue);
#endif

	//
	// Internal conenience functions
	//
	DWORD GetSize()			{ return m_TypeInfo.Size; }
	TYPEKIND GetTypeKind()	{ return m_TypeInfo.TypeKind; }
	OLECHAR *GetName()		{ return m_TypeInfo.Name; }
	HREFTYPE GetRefType(ICreateTypeInfo2 *);

	//
	// Public Construction
	//
	static CType *CreateTypeFromTypeInfo(ITypeInfo2 *pITypeInfo);
	static CType *CreateNewType(TYPE_INFO *TypeInfo, ICreateTypeLib2 *pICreateTypeLib);

protected:
	~CType();	// only CComObjectRoot<CType>::Release() should destroy this object

private:
	//
	// Serialization between TYPE_INFO and the COM type library
	//
	static HRESULT ReadTypeInfo(ITypeInfo2 *pITypeInfo, TYPE_INFO &TypeInfo);
	static HRESULT WriteTypeInfo(ICreateTypeInfo2 *pICreateTypeInfo, TYPE_INFO *TypeInfo);

	//
	// Dissect representation of this type
	//
	TYPE_INFO	m_TypeInfo;

	//
	// COM ITypeInfo of corresponding to this type.
	//
	CComPtr<ITypeInfo2> m_pITypeInfo;

};


#endif // _CTYPE_H