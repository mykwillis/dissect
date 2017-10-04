/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Sat Mar 21 21:37:08 1998
 */
/* Compiler settings for sys.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"

#ifndef __sys_h__
#define __sys_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL__intf_0000
 * at Sat Mar 21 21:37:08 1998
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


typedef 
enum tagCONFIDENCE
    {	CONFIDENCE_0	= 0,
	NO_CONFIDENCE	= CONFIDENCE_0,
	CONFIDENCE_1	= NO_CONFIDENCE + 1,
	CONFIDENCE_LOW	= CONFIDENCE_1,
	CONFIDENCE_2	= CONFIDENCE_LOW + 1,
	CONFIDENCE_3	= CONFIDENCE_2 + 1,
	CONFIDENCE_4	= CONFIDENCE_3 + 1,
	CONFIDENCE_5	= CONFIDENCE_4 + 1,
	CONFIDENCE_MEDIUM	= CONFIDENCE_5,
	CONFIDENCE_6	= CONFIDENCE_MEDIUM + 1,
	CONFIDENCE_7	= CONFIDENCE_6 + 1,
	CONFIDENCE_8	= CONFIDENCE_7 + 1,
	CONFIDENCE_9	= CONFIDENCE_8 + 1,
	CONFIDENCE_HIGH	= CONFIDENCE_9,
	CONFIDENCE_10	= CONFIDENCE_HIGH + 1,
	COMPLETE_CONFIDENCE	= CONFIDENCE_10
    }	CONFIDENCE;



extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
