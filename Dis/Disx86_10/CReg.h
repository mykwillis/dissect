#ifndef _CREG_H
#define _CREG_H

class CReg
{
protected:
	int m_rNum;	// register number (index)
	REGTYPE	m_type;

public:
	CReg();
	CReg(int rNum, REGTYPE type);
	CReg(REG& r);

	PCSTR Name() const
	{ return Name(m_type, (REG_NUM)m_rNum); }

	static PCSTR Name(REG_TYPE type, REG_NUM idx);
	static PCSTR Name(REG& r)
	{ return Name(r.type, r.num); }

	void SetNum(int rNum);
	void SetType(REGTYPE type);
	REGTYPE	GetType(void) const
	{ return m_type; }
	int	GetNum(void) const
	{ return m_rNum; }

	void SetTypeGeneral(SIZE_ATTRIBUTE size);

	void SetNumGeneral(int rNum, SIZE_ATTRIBUTE size)
		{ SetNum(rNum); SetTypeGeneral(size); }

	PCSTR Name8() const		{ return Name8(m_rNum);		}
	static PCSTR Name8(int rNum);
	
	PCSTR Name16() const	{ return Name16(m_rNum);		}
	static PCSTR Name16(int rNum);

	PCSTR Name32() const	{ return Name32(m_rNum);		}
	static PCSTR Name32(int rNum);

	PCSTR NameGeneral(SIZE_ATTRIBUTE size) const
		{ return NameGeneral(m_rNum, size); }
	static PCSTR NameGeneral(int rNum, SIZE_ATTRIBUTE size);

	PCSTR NameControl()const{ return NameControl(m_rNum);	}
	static PCSTR NameControl(int rNum);

	PCSTR NameDebug() const	{ return NameDebug(m_rNum);	}
	static PCSTR NameDebug(int rNum);

	PCSTR NameSeg() const	{ return NameSeg(m_rNum);	}
	static PCSTR NameSeg(int rNum);

	PCSTR NameTest() const	{ return NameTest(m_rNum);	}
	static PCSTR NameTest(int rNum);

	PCSTR NameMMX() const	{ return NameMMX(m_rNum);	}
	static PCSTR NameMMX(int rNum);

	operator REG() const {
		REG r;
		r.type = GetType();
		r.num = (REG_NUM) GetNum();
		return r;
	}
};
#endif // _CREG_H
