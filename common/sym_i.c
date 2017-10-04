/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun May 24 08:36:22 1998
 */
/* Compiler settings for sym.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IType = {0xAFAEAFC0,0xE089,0x11d1,{0xAE,0xB5,0xBE,0xBB,0x53,0x00,0x00,0x00}};


const IID IID_ISymbol = {0xD8FCD7C0,0xE088,0x11d1,{0xAE,0xB5,0xBE,0xBB,0x53,0x00,0x00,0x00}};


const IID IID_IModule = {0xA1A6D0F0,0xDE0D,0x11d1,{0xAE,0xB3,0x00,0x00,0xC0,0x86,0x6B,0x0E}};


const IID IID_IEnumTypes = {0x9C3EC8C0,0xE2A1,0x11d1,{0xAE,0xB8,0x00,0x00,0xC0,0x86,0x6B,0x0E}};


const IID IID_IEnumSymbols = {0xAD8750F0,0xBBAC,0x11d1,{0xAE,0x8F,0xB8,0xBB,0x59,0x00,0x00,0x00}};


const IID IID_IEnumModules = {0x9C3EC8C1,0xE2A1,0x11d1,{0xAE,0xB8,0x00,0x00,0xC0,0x86,0x6B,0x0E}};


const IID IID_IDisSymMgr = {0x215643D0,0xBBA7,0x11d1,{0xAE,0x8F,0xB8,0xBB,0x59,0x00,0x00,0x00}};


const IID IID_IDisSmX = {0x0F715AB0,0xBBA9,0x11d1,{0xAE,0x8F,0xB8,0xBB,0x59,0x00,0x00,0x00}};


const IID IID_IDisFunction = {0x28C36830,0xBBC0,0x11d1,{0xAE,0x8F,0xB8,0xBB,0x59,0x00,0x00,0x00}};


#ifdef __cplusplus
}
#endif

