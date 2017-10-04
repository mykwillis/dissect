#ifndef _CFUNCTION_H
#define _CFUNCTION_H

#include "CSymbol.h"

class CFunction :
	public IFunction,
	public CComObjectRoot
{
public:
	BEGIN_COM_MAP(CFunction)
		COM_INTERFACE_ENTRY(IFunction)
	END_COM_MAP()

	//
	// ISymbol Methods
	//
	STDMETHOD(GetSymbolName)(BSTR *Name)
		{ return m_Symbol.GetSymbolName(Name); }
	STDMETHOD(GetSymbolType)(SYMKIND *Kind)
		{ return SYMKIND_FUNC; }

	//
	// IFunction Methods
	//
	STDMETHOD(GetFunctionInfo)(FUNCTION_INFO **FunctionInfo);
	STDMETHOD(ReleaseFunctionInfo)(FUNCTION_INFO *FunctionInfo);

	//
	// Internal
	//
	STDMETHOD(Attach)(ITypeInfo2 *pITypeInfo, int Index);
	STDMETHOD(Update)(FUNCTION_INFO *FunctionInfo);

protected:
	static HRESULT ReadFunctionInfo(ITypeInfo2 *pITypeInfo, int Index, FUNCTION_INFO *FunctionInfo);
	static HRESULT WriteFunctionInfo(ICreateTypeInfo2 *pICreateTypeInfo, int Index, FUNCTION_INFO *FunctionInfo);

private:
	CSymbol	m_Symbol;
	CComPtr<ITypeInfo2> m_pITypeInfo;
	int	m_Index;
};

#endif // _CFUNCTION_H

