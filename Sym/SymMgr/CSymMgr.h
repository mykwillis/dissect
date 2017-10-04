#ifndef _CSYMMGR_H
#define _CSYMMGR_H
#include "resource.h"

#define IS_STANDARD_HTYPE( htype )	\
	( (DWORD)htype & 0x80000000 )
#define HTYPE_TO_VT( htype )	\
	((VARTYPE)((DWORD)htype & ~0x80000000))

class CModule;
class CType;
class CSymbol;

class CSymMgr : 
	public IDisSymMgr, 
	public CComObjectRoot,
	public CComCoClass<CSymMgr, &CLSID_SymMgr>
{
public:
	//
	// ATL Housekeeping
	//
	DECLARE_CLASSFACTORY();

	DECLARE_REGISTRY_RESOURCEID(IDR_CSYMMGR);

	BEGIN_COM_MAP(CSymMgr)
		COM_INTERFACE_ENTRY(IDisSymMgr)
	END_COM_MAP()

	//
	// IDisSymMgr methods
	//

	//
	// Type Methods
	//
	STDMETHOD(AddType)(IType **ppType, TYPE_INFO *TypeInfo);
	STDMETHOD(GetTypeByName)(IType **ppType, BSTR Name);
	STDMETHOD(GetTypeByHandle)(IType **ppType, HTYPE Handle);
	STDMETHOD(GetTypeHandle)(HTYPE *Handle, IType *pType);
	STDMETHOD(CloseTypeHandle)(HTYPE Handle);
	STDMETHOD(EnumTypes)(IEnumTypes **ppEnum);

	//
	// Symbol methods
	//
	STDMETHOD(AddSymbol)(ISymbol **ppISymbol, SYMBOL_INFO *SymbolInfo);
	STDMETHOD(GetSymbolByName)(ISymbol **ppISymbol, BSTR Name);
	STDMETHOD(GetSymbolByAddress)(ISymbol **ppISymbol, DWORD Address);
	STDMETHOD(EnumSymbols)(IEnumSymbols **ppEnum);

	//
	// Module methods
	//
	STDMETHOD(AddModule)(IModule **ppIModule, MODULE_INFO *ModuleInfo);
	STDMETHOD(GetModuleByName)(IModule **ppIModule, BSTR Name);
	STDMETHOD(GetModuleByAddress)(IModule **ppIModule, DWORD Address);
	STDMETHOD(EnumModules)(IEnumModules **ppEnum);
	
	//
	// Construction and Destruction
	//
	~CSymMgr();

	STDMETHOD(CreateNew)(OLECHAR *Path);
	STDMETHOD(OpenExisting)(OLECHAR *Path);

	STDMETHOD(Extract)(IDisImg *Image);
protected:
	BOOL	IsTypeName(OLECHAR *Name);
	BOOL	IsFuncName(OLECHAR *Name);

	ITypeInfo *BindTypeInfo(OLECHAR *Name);
	ITypeInfo *BindTypeInfo(HTYPE Handle);
	HREFTYPE GetRefType(ICreateTypeInfo2 *pICreateTypeInfo, HTYPE Type );
	void BuildElemdescFromHtype(ELEMDESC *Elemdesc, ICreateTypeInfo2 *pICreateTypeInfo, HTYPE Type);

	//
	// Internal utility functions
	//
	CModule *GetModuleByAddress(DWORD Address);
	CModule *GetModuleByName(OLECHAR *Name);

	CType *GetTypeByName(OLECHAR *Name);

	CSymbol *GetSymbolByAddress(DWORD Address);
	CSymbol *GetSymbolByName(OLECHAR *Name);

private:

	//
	// m_ITypeLib and m_ICreateTypeLib point to interfaces on
	// the same object representing the COM type library.
	//
	CComPtr<ITypeLib2>			m_pITypeLib;
	CComPtr<ICreateTypeLib2>	m_pICreateTypeLib;
	CComPtr<ITypeComp>			m_pITypeComp;

	CModule *					m_pIOrphanModule;

	CTypedPtrList<CPtrList, CModule *>	m_ModuleList;
	CTypedPtrList<CPtrList, CType *>	m_TypeList;
};

#endif // _CSYMMGR_H