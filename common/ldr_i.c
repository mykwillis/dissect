/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun May 17 20:59:29 1998
 */
/* Compiler settings for ldr.idl:
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

const IID IID_IEnumImages = {0x2D05BF30,0xE8FB,0x11d1,{0xAE,0xC0,0x34,0xC2,0x6F,0x00,0x00,0x00}};


const IID IID_IDisLdr = {0x8D5E0E60,0xBA37,0x11d1,{0xAE,0x8C,0x00,0x00,0xC0,0x86,0x6B,0x0E}};


const IID IID_IDisEnumImports = {0x2DB7E190,0xD35E,0x11d1,{0xAE,0xA2,0x7C,0x65,0x0A,0x00,0x00,0x00}};


const IID IID_IDisEnumExports = {0x2DB7E191,0xD35E,0x11d1,{0xAE,0xA2,0x7C,0x65,0x0A,0x00,0x00,0x00}};


const IID IID_IEnumSections = {0x413A1770,0xE851,0x11d1,{0xAE,0xBF,0x3A,0x43,0xC2,0x00,0x00,0x00}};


const IID IID_IDisImg = {0xF4EDD6B0,0xBC4D,0x11d1,{0xAE,0x8F,0xB8,0xBB,0x59,0x00,0x00,0x00}};


#ifdef __cplusplus
}
#endif

