#include "project.h"
#include "CReg.h"

#ifndef ASSERT
#define ASSERT(x)
#endif

PCSTR
ControlRegNames[] =
{
	"cr0",
	"cr1",
	"cr2",
	"cr3",
	"cr4",
	"cr5",
	"cr6",
	"cr7"
};
#define NUM_CONTROL_REG_NAMES	((sizeof(ControlRegNames)/sizeof(ControlRegNames[0])))

PCSTR
DebugRegNames[] =
{
	"d0",
	"d1",
	"d2",
	"d3",
	"d4",
	"d5",
	"d6",
	"d7"
};
#define NUM_DEBUG_REG_NAMES	((sizeof(DebugRegNames)/sizeof(DebugRegNames[0])))

PCSTR
TestRegNames[] =
{
	"t0",
	"t1",
	"t2",
	"t3",
	"t4",
	"t5",
	"t6",
	"t7"
};
#define NUM_TEST_REG_NAMES	((sizeof(TestRegNames)/sizeof(TestRegNames[0])))

PCSTR
GeneralRegNames[] =
{
	"eax",
	"ecx",
	"edx",
	"ebx",
	"esp",
	"ebp",
	"esi",
	"edi"
};
#define NUM_GENERAL_REG_NAMES	((sizeof(GeneralRegNames)/sizeof(GeneralRegNames[0])))

PCSTR
MMXRegNames[] =
{
	"mm0",
	"mm1",
	"mm2",
	"mm3",
	"mm4",
	"mm5",
	"mm6",
	"mm7"
};
#define NUM_MMX_REG_NAMES	((sizeof(MMXRegNames)/sizeof(MMXRegNames[0])))

PCSTR
ByteRegNames[] =
{
	"al",
	"cl",
	"dl",
	"bl",
	"ah",
	"ch",
	"dh",
	"bh"
};
#define NUM_BYTE_REG_NAMES	((sizeof(ByteRegNames)/sizeof(ByteRegNames[0])))

PCSTR
SegmentRegNames[] =
{
	"cs",
	"ds",
	"es",
	"fs",
	"gs",
	"ss"
};
#define NUM_SEGMENT_REG_NAMES	((sizeof(SegmentRegNames)/sizeof(SegmentRegNames[0])))

CReg::CReg()
{

}

CReg::CReg(int rNum, REGTYPE type)
{
	ASSERT(rNum < 8);
	m_type = type;
	m_rNum = rNum;
}

CReg::CReg(REG& r)
{
	m_type = r.type;
	m_rNum = r.num;
}

void
CReg::SetNum(int rNum)
{
	ASSERT(rNum < 8);
	m_rNum = rNum;
}

void
CReg::SetType(REGTYPE type)
{
	m_type = type;
}

void
CReg::SetTypeGeneral(SIZE_ATTRIBUTE size)
{
	switch(size)	{
	case SIZE_8:
		m_type = REGTYPE_GEN_BYTE;
		break;
	case SIZE_16:
		m_type = REGTYPE_GEN_WORD;
		break;
	case SIZE_32:
		m_type = REGTYPE_GEN_DWORD;
		break;
	case SIZE_64:
		m_type = REGTYPE_MMX;
		break;
	default:
		ASSERT(0);
	}
	
}

PCSTR 
CReg::Name8(int rNum)
{
	ASSERT(rNum < NUM_BYTE_REG_NAMES );
	return ByteRegNames[rNum];
}

PCSTR 
CReg::Name32(int rNum)
{
	ASSERT(rNum < NUM_GENERAL_REG_NAMES );
	return GeneralRegNames[rNum];
}

PCSTR 
CReg::Name16(int rNum)
{
	ASSERT(rNum < NUM_GENERAL_REG_NAMES );
	return (PCSTR)((PCHAR)(GeneralRegNames[rNum])+1);

}

PCSTR 
CReg::NameControl(int rNum)
{
	ASSERT(rNum < NUM_CONTROL_REG_NAMES );
	return ByteRegNames[rNum];
}

PCSTR
CReg::NameGeneral(int rNum, SIZE_ATTRIBUTE size)
{
	switch(size)	{
	case SIZE_8:
		return Name8(rNum);
	case SIZE_16:
		return Name16(rNum);
	case SIZE_32:
		return Name32(rNum);
	default:
		ASSERT(0);
		return NULL;
	}
}
PCSTR 
CReg::NameDebug(int rNum)
{
	ASSERT(rNum < NUM_DEBUG_REG_NAMES );
	return ByteRegNames[rNum];
}

PCSTR 
CReg::NameMMX(int rNum)
{
	ASSERT(rNum < NUM_MMX_REG_NAMES );
	return MMXRegNames[rNum];
}

PCSTR 
CReg::NameSeg(int rNum)
{
	ASSERT(rNum < NUM_SEGMENT_REG_NAMES );
	return SegmentRegNames[rNum];
}

PCSTR 
CReg::NameTest(int rNum)
{
	ASSERT(rNum < NUM_TEST_REG_NAMES );
	return TestRegNames[rNum];
}

//static
PCSTR
CReg::Name(REG_TYPE type, REG_NUM idx)
{
	switch(type)	{
//	case REGTYPE_NONE:
//		return "???";
	case REGTYPE_GEN_BYTE:
		return Name8(idx);
	case REGTYPE_GEN_WORD:
		return Name16(idx);
	case REGTYPE_GEN_DWORD:
		return Name32(idx);
//	case REGTYPE_GEN_QWORD:
//		return Name64(idx);
	case REGTYPE_MMX:
		return NameMMX(idx);
	case REGTYPE_CONTROL:
		return NameControl(idx);
	case REGTYPE_TEST:
		return NameTest(idx);
	case REGTYPE_DEBUG:
		return NameDebug(idx);
	case REGTYPE_SEG:
		return NameSeg(idx);
	case REGTYPE_FLAGS:
		return "eflags";
//	case REGTYPE_SYSTEM:
//		return "system";
	default:
		return "???";
	}
}