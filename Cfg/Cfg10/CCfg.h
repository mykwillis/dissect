#ifndef _CCFG_H
#define _CCFG_H
#include "resource.h"

class CProcedure;
class CBasicBlock;

class CCfg: 
	public IDisCfg, 
	public CComObjectRoot,
	public CComCoClass<CCfg, &CLSID_Cfg10>
{
public:
	DECLARE_CLASSFACTORY();
	DECLARE_REGISTRY_RESOURCEID(IDR_CCFG);
	BEGIN_COM_MAP(CCfg)
		COM_INTERFACE_ENTRY(IDisCfg)
	END_COM_MAP()

public:
	CCfg();
	~CCfg();
	STDMETHOD(Attach)(IDisLdr *pILdr, IDisDis *pIDis, IDisSymMgr *pISym);

	STDMETHOD(Parse)(DWORD Address);
	STDMETHOD(ParseAllSymbols)();
	STDMETHOD(Clear)();
	STDMETHOD(EnumBasicBlocks)(IDisEnumBASIC_BLOCK **ppEnum);
	STDMETHOD(GetNextBasicBlock)(DWORD Address, BASIC_BLOCK *BasicBlock);
	STDMETHOD(ParseProcedure)(DWORD Address, PROCEDURE *Procedure);
	
	STDMETHOD(DestroyProcedure)(PROCEDURE *Procedure);
	
	STDMETHOD(GetEdgesIn)(DWORD Address, DIS_REF *Refs, int *count);
	STDMETHOD(GetDataReferences)(DWORD Address, IEnumInstructions **ppEnum);
protected:
	BOOL ScanForReference(DWORD Address, DWORD *Addr, DIS_REF *Ref);
	CBasicBlock *ParseBlock(CProcedure *, DWORD Address);
	CProcedure *ParseProcedure(DWORD Address, OLECHAR *Name = NULL);
	//STDMETHOD(I_ParseFunc)(CProcedure *, DWORD);

	CBasicBlock *FindBasicBlock(DWORD Address);
	CBasicBlock *FindContainingBasicBlock(DWORD Address);
	DWORD FindNextBasicBlockAddress(DWORD Address);
	CBasicBlock *InsertBasicBlock(DWORD Address, BOOL Allocate, CBasicBlock *cbb);
	CBasicBlock *AllocateBasicBlock(DWORD Address);
	void DeallocateBasicBlock(CBasicBlock *);

	CProcedure *FindProcedure(DWORD Address);
	CProcedure *FindContainingProcedure(DWORD Address);
	DWORD FindNextProcedureAddress(DWORD Address);
	CProcedure *InsertProcedure(DWORD Address, OLECHAR *Name, BOOL Allocate, CProcedure *cbb);
	CProcedure *AllocateProcedure(DWORD Address, OLECHAR *Name);

	BOOL AddAllBasicBlocksToProc( CProcedure *Proc, CBasicBlock *Block );

	void MarkProcedureEntryPoint(DWORD Address);

private:
	CComPtr<IDisLdr> m_pILdr;
	CComPtr<IDisDis> m_pIDis;
	CComPtr<IDisSymMgr> m_pISym;

#ifdef USE_TREE
	AVL_TREE	m_BasicBlockTree;
#else
	LIST_ENTRY	m_BasicBlockList;
#endif
	LIST_ENTRY	m_ProcedureList;
};

#endif // _CCFG_H