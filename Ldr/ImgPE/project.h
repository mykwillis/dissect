#ifndef _PROJECT_H
#define _PROJECT_H

//
// Disable annoying Level 4 warnings
//
#pragma warning(disable : 4010 4201 4214 4115 4514)
	// warning C4010: single-line comment contains line-continuation character
	// warning C4201: nonstandard extension used : nameless struct/union
	// winnt.h(188) : warning C4201: nonstandard extension used : 
	//					nameless struct/union
	// winnt.h(1357) : warning C4214: nonstandard extension used : bit field types other than int
	// rpcndr.h(1891) : warning C4115: 'IRpcStubBuffer' : named type definition in parentheses
	// warning C4514: 'Int64ShllMod32' : unreferenced inline function has been removed
#define STRICT
#define _WIN32_WINNT 0x0400
#define _ATL_APARTMENT_THREADED


#include <atlbase.h>
extern CComModule _Module;
#include <atlcom.h>

#include <windows.h>
#include <comcat.h>	// ICatRegister

//
// Private CLSIDs
//
#include "guids.h"				

//
// Dissect Interface definitions
//
#include "..\..\common\ldr.h"	// image loader interface

//
// Utility macros
//
#include "..\..\common\util.h"

#endif // _PROJECT_H