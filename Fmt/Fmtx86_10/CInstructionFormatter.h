#ifndef _CINSTRUCTIONFORMATTER_H
#define _CINSTRUCTIONFORMATTER_H
#include "resource.h"

class CInstructionFormatter: 
	public IDisFmt, 
	public CComObjectRoot,
	public CComCoClass<CInstructionFormatter, &CLSID_Fmtx86>
{
public:
	DECLARE_CLASSFACTORY();

	DECLARE_REGISTRY_RESOURCEID(IDR_CINSTRUCTIONFORMATTER);

	BEGIN_COM_MAP(CInstructionFormatter)
		COM_INTERFACE_ENTRY(IDisFmt)
	END_COM_MAP()


	CInstructionFormatter()
	{/*empty*/}

	//
	// IDisFmt methods
	//
	STDMETHOD(GetInstructionString)(PINSTRUCTION pInst, BSTR *pbstr);
	STDMETHOD(SetSymbolManager)(IDisSymMgr *pISym);

	//
	// IDisInstructionFormatter methods
	//
	STDMETHOD(GetAnsiString)(IDisInstruction *pIInst, unsigned char *pStr, ULONG ulLen);
	STDMETHOD(GetAnsiString2)(INSTRUCTION &inst, unsigned char *pStr, ULONG ulLen);
protected:
	int FormatOPERAND_MEMPTR(MEMPTR& mp, char *pBuf, int cBuf);
	int FormatOPERAND(OPERAND& op, char *pBuf, int cBuf, BOOL bXlate = FALSE);
	int FormatOPERAND_IMM(IMM& imm, char *pBuf, int cBuf, BOOL bXlate = FALSE);
private:
	CComPtr<IDisSymMgr> m_pISym;
};
#endif // _CINSTRUCTIONFORMATTER_H