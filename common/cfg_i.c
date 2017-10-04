/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun May 24 09:03:50 1998
 */
/* Compiler settings for cfg.idl:
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

const IID IID_IDisEnumBASIC_BLOCK = {0x2597F640,0xD489,0x11d1,{0xAE,0xA4,0x00,0x00,0xC0,0x86,0x6B,0x0E}};


const IID IID_IDisCfg = {0xDD6DD9F0,0xD0A8,0x11d1,{0xAE,0xA0,0x9A,0xBA,0xAD,0x00,0x00,0x00}};


#ifdef __cplusplus
}
#endif

