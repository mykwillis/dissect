#ifndef _CSYMBOL_H
#define _CSYMBOL_H

//
// This is the object stored internally by the symbol manager
// to represent a symbol.  Pointers to the ISymbol interface
// of this object can be used throughout Dissect code, which
// can provide the SYMBOL_INFO for the symbol.
//
// Internally, CSymbol (like CType) converts the Dissect
// SYMBOL_INFO information into appropriate ITypeInfo types.
// Each CSymbol is associated with a specific module via
// an ITypeInfo interface pointer.  A unique index 
// specifies each symbol's position in the module's ITypeInfo
//
class CSymbol :
	public ISymbol,
	public CComObjectRoot
{
public:
	BEGIN_COM_MAP(CSymbol)
		COM_INTERFACE_ENTRY(ISymbol)
	END_COM_MAP()

	//
	// ISymbol Methods
	//
	STDMETHOD(GetSymbolInfo)(SYMBOL_INFO **SymbolInfo);
	STDMETHOD(ReleaseSymbolInfo)(SYMBOL_INFO *SymbolInfo);

	LPCWSTR Name()			{ return m_SymbolInfo.Name;		}
	DWORD	Address()		{ return m_SymbolInfo.Address; }
	DWORD	HighAddress()	{ return m_SymbolInfo.Address + m_SymbolInfo.Size; }
	BOOL	Contains(DWORD Address);
	int		Delta(DWORD Address)	{ return Address - this->Address(); }

	static CSymbol *CreateSymbolFromTypeInfo(ITypeInfo2 *pITypeInfo);
	static CSymbol *CreateNewSymbol(SYMBOL_INFO *TypeInfo, ICreateTypeInfo2 *pITypeInfo, int Index);

protected:
	~CSymbol();	// only CComObjectRoot<CSymbol>::Release() should destroy this object

private:
	static HRESULT ReadSymbolInfo(ITypeInfo2 *pITypeInfo, int Index, SYMBOL_INFO &SymbolInfo);
	static HRESULT WriteSymbolInfo(ICreateTypeInfo2 *pICreateTypeInfo, int Index, SYMBOL_INFO *SymbolInfo);
	//
	// Dissect SYMBOL_INFO representation of symbol
	//
	SYMBOL_INFO	m_SymbolInfo;
	
	//
	// COM ITypeInfo of which this symbol is a member.
	//
	CComPtr<ITypeInfo2> m_pITypeInfo;

	//
	// Index of this symbol in the ITypeInfo
	//
	int m_Index;
};

#endif // _CSYMBOL_H
