#include "project.h"
#include "XDisException.h"

XDisException::XDisException(char *fmt, ...)
{
	char buf[1024];
	va_list args;
	va_start(args, fmt);
	::wvsprintf(buf, fmt, args);
	va_end(args);
//_msg = strdup( buf ); 

	OutputDebugString(buf);
	OutputDebugString("\n"); // ack ack cough cough
}
