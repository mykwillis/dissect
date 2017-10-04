#ifndef _DISASM_PROJECT_H
#define _DISASM_PROJECT_H

#define DUMPBIN_EMULATION	1

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

//
// Include necessary MFC crap
//
#include <afx.h>
#include <afxtempl.h>
#include <iostream.h>
//#include <ole2.h>
#include <comcat.h>	// ICatRegister

//
// CUnknown support
//
#include "..\..\common\CUnknown.h"
//#include "..\Studio\Dissect.h"		// generated interface/structures
//#include "..\Dis\CEnumFromCList.h"

//
// Precompile the OpcodeMap header file, since it won't often change
//
//#include "DisTypes.h"			// internal types, despite the name
#include "OpcodeMap.h"

//
// Dissect Interface definitions
//
#include "..\..\common\dis.h"	// IDisDis (Disassembler) interface

//
// Utility macros
//
#define _STR(__s) #__s
#define _FL_MSG(__f,__l,__msg) __f "(" _STR(__l) ") : " __msg

#define _ERROR(__msg) \
	message(_FL_MSG(__FILE__,__LINE__,"error: " __msg))
#define _WARN(__msg)  \
	message(_FL_MSG(__FILE__,__LINE__,"warning: " __msg))
#define _TODO(_msg)  \
	message(_FL_MSG(__FILE__,__LINE__,"todo: " _msg))

#define _MSG(__msg)  message(__msg)

#define BITTEST(_word, _bit)	((BOOL)(_word & _bit ? 1 : 0 ))

#endif // _DISASM_PROJECT_H