#ifndef _DIS_EXCEPTION_H
#define _DIS_EXCEPTION_H

class XDisException	{
private:
	char *m_msg;
public:
	XDisException()
		{
		m_msg = NULL;
		};
	XDisException(char *fmt, ...);

	char *getMessage()
		{
			return "nada";
		}
	XDisException& operator=(XDisException& x)
		{
//			m_msg = strdup(x.m_msg);
			x;
			return *this;
		}
	~XDisException()
		{
//			if (m_msg) free(m_msg);
			m_msg = NULL;
		}
};

#endif // _DIS_EXCEPTION_H