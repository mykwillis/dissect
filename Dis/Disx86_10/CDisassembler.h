#ifndef _CDISASSEMBLER_H
#define _CDISASSEMBLER_H

class CBasicBlock;
class CEngine;
class CPEImage;
class CDisassembler	: public IDisDis, public CUnknown
{
public:
	CDisassembler() : CUnknown(NULL)
	{ /* empty */ }
	~CDisassembler()
	{ /* empty */ }

	//
	// IUnknown methods
	//
	DECLARE_IUNKNOWN
	STDMETHOD(NondelegatingQueryInterface)(const IID& iid, void ** ppv)
	{
		if (iid == IID_IDisDis)	{
			return FinishQI(static_cast<IDisDis *>(this), ppv);
		} else {
			return CUnknown::NondelegatingQueryInterface(iid, ppv);
		}
	}

	//
	// IDisDis methods
	//
	STDMETHOD(Disasm)(IN DWORD dwPtr, IN DWORD dwVA, OUT INSTRUCTION *pInst);

};

#endif // _CDISASSEMBLER