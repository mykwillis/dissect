/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun May 24 08:36:18 1998
 */
/* Compiler settings for dis.idl:
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

const IID IID_IDisDis = {0xAFC3E230,0xB956,0x11d1,{0xAE,0x8B,0x00,0x00,0xC0,0x86,0x6B,0x0E}};


const IID IID_IDisInstruction = {0x54CF88F0,0x5E30,0x11d1,{0xAE,0x36,0x00,0x00,0xC0,0x86,0x6B,0x0E}};


const IID IID_IEnumInstructions = {0xAF413E90,0xF303,0x11d1,{0xAE,0xC8,0x00,0x00,0xC0,0x86,0x6B,0x0E}};


#ifdef __cplusplus
}
#endif

