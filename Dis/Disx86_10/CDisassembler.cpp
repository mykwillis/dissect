#include "project.h"
#include "CDisassembler.h"
#include "CInstruction.h"


STDMETHODIMP
CDisassembler::Disasm(IN DWORD dwPtr,			// a dereferenceable pointer
					  IN DWORD dwVA,			// the virtual address of this code if it were loaded at its preferred address
					  OUT INSTRUCTION *pInst)
{
	CInstruction inst;
	try {
		UINT rc = inst.Dis((PBYTE)dwPtr, dwVA);
		if (rc)	{
			inst.GetINSTRUCTION(pInst);
			return S_OK;
		}
	} catch(...)	{
	}

	return E_FAIL;
}









////////////////////////////////////////////////////////////////////////////
// The rest of this file is obsolete, but retained for reference
////////////////////////////////////////////////////////////////////////////

#if 0
#define BUILDPTR( cast, ptr, addvalue) (cast)( (DWORD)(ptr)+(DWORD)(addvalue))
PBYTE
CDisassembler::Dis(PBYTE pStart, PBYTE pEnd)
{
	ASSERT( pStart < pEnd );
	CArray<CInstruction *, CInstruction *>	arrInst;
	CBasicBlock		*pBlk;
	CInstruction	*pInst;
	// build the list of basic blocks
	// from section 6.4 of the dragon book:
	//
	// 1. First determine the set of leaders, the first statement of basic blocks,
	//	  using the following rules:
	//	i)	The first statement is a leader
	//	ii)	Any statement that is the target of a conditional or unconditional
	//		goto [Jxx] is a leader
	//	iii)Any statement that immediately follows a goto or conditional goto
	//		statement is a leader
	// 2. For each leader, its basic block consists of the leader and all statements
	//	  up to but not including the next leader or the end of the program [range]
	//

	// to make this a little cleaner, our algorithm is:
	// - disassemble all of the instructions in our range, and put them in
	//    the arrInst array.
	//	-) mark the first instruction as a leader.
	//	-) if an instruction is a jump, mark the following instruction and
	//		the target of the jump (if in our range) as leaders
	// - move the instructions from the arrInst into CBasicBlock objects,
	//	  allocating a new basic block each time a leader instruction is encountered.
	//

	// set the array up to allocate about the right amount of memory
	arrInst.SetSize( (pEnd - pStart) / 4 );	// about 4 bytes per instruction...

	// disassemble all the instructions
	while (pStart < pEnd)	{
		pInst = new CInstruction();
		pStart += pInst->Dis(pStart);
		arrInst.Add(pInst);
	}

	// mark all of the leaders
	// rule 1.i) first instruction is leader
	if ( arrInst.GetSize() )
		arrInst[0]->SetBasicBlockLeader();

	int arrSize = arrInst.GetSize();
	for (int i=0;i<arrSize;i++)	{
		//rule 1.ii) and instruction that is the target of a jmp is a leader
		if ( pInst->isJmp() )	{
			PBYTE pTarget = (PBYTE) pInst->GetJmpTarget();
		}
	
	// rule i) the first statement is a leader
	pInst = new CInstruction();		// allocate an instruction
	pStart += pInst->Dis(pStart);	// read from the stream
	pBlk += pInst;					// add the instruction to the first basic block
	m_bbList.AddHead(pInst);		// add the basic block to our list

	// now, loop until we hit the end point
	while (pStart < pEnd)	{
		
		// rule iii); if the last statement was a goto, this one is a leader
		if (pInst->isJmp())	{
			// make a new basic block, giving it the old block as predecessor
			CBasicBlock *pNewBlk = new CBasicBlock(pBlk);

			m_bbList.AddTail(pBlk);		// add the new block to our list of blocks
		}

		pBlk = new CBasicBlock();			
		pStart += pBlk->ReadBlock(pStart);
		m_bbList.AddHead(pBlk);
	}



		pInst = new CInstruction();
		pStart += i->Dis(pStart);
		m_instList.AddTail(i);
	}
	return pStart;
}

STDMETHODIMP
CDisassembler::Disassemble(IDisSection *pSec)
{
	// we don't actually disassembler; we just get ready to enumerate
	IDisLocation *pLoc;
	HRESULT hr = pSec->QueryInterface(IID_IDisLocation, (void **)&pLoc);
	ASSERT( SUCCEEDED(hr) );

	DWORD dwImageOff;
	hr = pLoc->GetImageOffset(&dwImageOff);
	ASSERT( SUCCEEDED(hr) );

	DWORD dwSize;
	hr = pLoc->GetSize(&dwSize);
	ASSERT( SUCCEEDED(hr) );

	IDisFileParser *pParse;
	hr = pSec->GetFileParser(&pParse);
	ASSERT( SUCCEEDED(hr) );
	
	IDisFileMapping *pMap;
	hr = pParse->QueryInterface(IID_IDisFileMapping, (void **)&pMap);
	ASSERT( SUCCEEDED(hr) );

	hr = pMap->ConvertImageOffsetToPtr(dwImageOff, &m_pBegin);
	ASSERT( SUCCEEDED(hr) );

	m_pEnd = BUILDPTR( BYTE *, m_pBegin, dwSize );

	pParse->Release();
	pMap->Release();
	pLoc->Release();

	return S_OK;

}

BOOL
CDisassembler::Disasm(PDISASM_STACK pData)
{
	CInstruction inst;
	INSTRUCTION instruction;
	//ATTRIB_LIST al;
	//al.pHead = NULL;
	char buf[256];
	PBYTE pCur = pData->pBase;
	PBYTE pEnd = pData->pBase + pData->ulLength;
	DWORD dwLabel = pData->dwLabelBase;

	//
	// Calculate difference between virtual address and actual
	// 
	int delta = pData->dwLabelBase - (DWORD)pData->pBase;


	//
	// Do the control flow analysis
	//
	if ( pData->pIControlFlow )
		while (pCur < pEnd)	{
			//
			// Disassemble the instruction at pCur
			//
			UINT len = inst.Dis(pCur, (DWORD)pCur + delta);

			//
			// Drop the instruction to the control
			//
			pData->pIControlFlow->Drop( &inst );

			//
			// Advance to next instruction
			//
			pCur += len;
		}

	//
	// Do the data flow analysis
	//
	pCur = pData->pBase;
	if ( pData->pIDataFlow )
		while (pCur < pEnd)	{
			DWORD dwVA = (DWORD)pCur + delta;

			//
			// Disassemble the instruction at pCur
			//
			UINT len = inst.Dis(pCur, dwVA);

			//
			// Drop the instruction to the control
			//
			pData->pIControlFlow->Drop( &inst );

			//
			// Advance to next instruction
			//
			pCur += len;
		}

	//
	// Do the formatting and output
	//
	pCur = pData->pBase;
	while (pCur < pEnd)	{
		//
		// Disassemble the instruction at pCur
		//
		UINT len = inst.Dis(pCur, (DWORD)pCur + delta);

		//
		// Convert to INSTRUCTION
		//
		inst.GetINSTRUCTION(&instruction);

		//
		// Format into a char buffer
		//
		if (pData->pIFormat)
			pData->pIFormat->GetAnsiString(&inst, (unsigned char *)buf, sizeof(buf));

		//
		// Output instruction
		//
		if ( pData->pIOutput == DISASM_OUTPUT_STDOUT )
			puts(buf);
		else
			pData->pIOutput->Drop(&inst, (char *)buf);

		//
		// Advance to next instruction
		//
		pCur += len;
		dwLabel += len;
	}

	//
	// Flush stdout
	//
	if ( pData->pIOutput == DISASM_OUTPUT_STDOUT )
		fflush(stdout);

	return TRUE;
}
#endif // if 0


#if SHIT_BALLS
STDMETHODIMP
CDisassembler::EnumInstructions(IDisEnumInstructions **ppEnum)
{
	CList<IDisInstruction *, IDisInstruction *> list;
	CInstruction *pInst;

	BYTE *pCur = m_pBegin;
	while(pCur < m_pEnd)	{
		pInst = new CInstruction();
		pCur += pInst->Dis(pCur);
		list.AddTail(pInst);
	}

	*ppEnum = new CEnumFromCList<IDisInstruction, IDisEnumInstructions>(list);

	POSITION p = list.GetHeadPosition();
	while (p)	{
		(list.GetNext(p))->Release();
	}

	return S_OK;
}
#endif // SHIT_BALLS

