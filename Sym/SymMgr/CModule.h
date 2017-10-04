#ifndef _CMODULE_H
#define _CMODULE_H

class CSymbol;

//
// This is the object stored internally by the symbol manager
// to represent a module.  A pointer to this object is also cast
// to an IModule for client requests.
//
class CModule :
	public IModule,
	public CComObjectRoot
{
public:
	BEGIN_COM_MAP(CModule)
		COM_INTERFACE_ENTRY(IModule)
	END_COM_MAP()

	//
	// IModule Methods
	//
	STDMETHOD(GetModuleInfo)(MODULE_INFO **ModuleInfo);
	STDMETHOD(ReleaseModuleInfo)(MODULE_INFO *ModuleInfo);

	//
	// Symbol methods
	//
	STDMETHOD(AddSymbol)(ISymbol **ppISymbol, SYMBOL_INFO *SymbolInfo);
	STDMETHOD(GetSymbolByName)(ISymbol **ppISymbol, BSTR Name);
	STDMETHOD(GetSymbolByAddress)(ISymbol **ppISymbol, DWORD Address);
	STDMETHOD(EnumSymbols)(IEnumSymbols **ppEnum);

	//
	// Public Construction
	//
	static CModule *CreateModuleFromTypeInfo(ITypeInfo2 *pITypeInfo);
	static CModule *CreateNewModule(MODULE_INFO *ModuleInfo, ICreateTypeLib2 *pICreateTypeLib);

	BOOL	Contains(DWORD Address);
	DWORD	Address()		{ return m_ModuleInfo.BaseAddress; }
	DWORD	HighAddress()	{ return m_ModuleInfo.BaseAddress + m_ModuleInfo.Size; }
	LPCWSTR	Name()			{ return m_ModuleInfo.Name; }

	STDMETHOD(Update)(MODULE_INFO *ModuleInfo);

protected:
	CModule();	// only CComObjectRoot<CModule>::
	~CModule();	// only CComObjectRoot<CModule>::Release() should destroy an object

private:
	//
	// Private Construction, Destruction, and Serialization
	//
	static HRESULT ReadModuleInfo(ITypeInfo2 *pITypeInfo, MODULE_INFO *pModuleInfo);
	static HRESULT WriteModuleInfo(ICreateTypeInfo2 *pICreateTypeInfo, MODULE_INFO *ModuleInfo);

	int	GetNextSymbolIndex() { return m_NextSymbolIndex++; }

	//
	// Dissect representation of this module
	//
	MODULE_INFO	m_ModuleInfo;

	//
	// COM ITypeInfo of corresponding to this module.
	//
	CComPtr<ITypeInfo2> m_pITypeInfo;

	//
	// List of all symbols in this module
	//
	CTypedPtrList<CPtrList, CSymbol *>	m_SymbolList;

	//
	// Next symbol index
	int	m_NextSymbolIndex;
};


#endif // _CMODULE_H