#ifndef _CADDRESSING_METHOD
#define _CADDRESSING_METHOD

class CAddressingMethod
{
private:
	ADDRESSING_METHOD	m_method;
public:
	operator ADDRESSING_METHOD() const
		{ return m_method; }

	static CHAR	GetCode(ADDRESSING_METHOD type);
	CHAR GetCode(void) const
		{ return GetCode(m_method); }

	static PCSTR GetName(ADDRESSING_METHOD type);
	PCSTR	GetName(void) const
		{ return GetName(m_method); }

	static PCSTR GetDescription(ADDRESSING_METHOD type);
	PCSTR	GetDescription(void) const
		{ return GetDescription(m_method); }


};

#endif