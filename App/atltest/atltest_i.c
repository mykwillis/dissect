/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 3.00.44 */
/* at Thu Apr 02 21:32:54 1998
 */
/* Compiler settings for atltest.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
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

const IID IID_IClassName = {0x9859BB82,0xCAB2,0x11D1,{0xAE,0x9A,0xB2,0xD3,0x26,0x00,0x00,0x00}};


const IID LIBID_ATLTESTLib = {0x9859BB80,0xCAB2,0x11D1,{0xAE,0x9A,0xB2,0xD3,0x26,0x00,0x00,0x00}};


const CLSID CLSID_ClassName = {0x9859BB83,0xCAB2,0x11D1,{0xAE,0x9A,0xB2,0xD3,0x26,0x00,0x00,0x00}};


#ifdef __cplusplus
}
#endif

