/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Mon Apr 13 20:19:06 1998
 */
/* Compiler settings for fmt.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __fmt_h__
#define __fmt_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IDisFmt_FWD_DEFINED__
#define __IDisFmt_FWD_DEFINED__
typedef interface IDisFmt IDisFmt;
#endif 	/* __IDisFmt_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "dis.h"
#include "sym.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IDisFmt_INTERFACE_DEFINED__
#define __IDisFmt_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IDisFmt
 * at Mon Apr 13 20:19:06 1998
 * using MIDL 3.00.44
 ****************************************/
/* [object][uuid] */ 



EXTERN_C const IID IID_IDisFmt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IDisFmt : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetInstructionString( 
            /* [in] */ PINSTRUCTION pInst,
            /* [out] */ BSTR __RPC_FAR *pbStr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSymbolManager( 
            /* [in] */ IDisSymMgr __RPC_FAR *pISym) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDisFmtVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDisFmt __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDisFmt __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDisFmt __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInstructionString )( 
            IDisFmt __RPC_FAR * This,
            /* [in] */ PINSTRUCTION pInst,
            /* [out] */ BSTR __RPC_FAR *pbStr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSymbolManager )( 
            IDisFmt __RPC_FAR * This,
            /* [in] */ IDisSymMgr __RPC_FAR *pISym);
        
        END_INTERFACE
    } IDisFmtVtbl;

    interface IDisFmt
    {
        CONST_VTBL struct IDisFmtVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDisFmt_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDisFmt_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDisFmt_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDisFmt_GetInstructionString(This,pInst,pbStr)	\
    (This)->lpVtbl -> GetInstructionString(This,pInst,pbStr)

#define IDisFmt_SetSymbolManager(This,pISym)	\
    (This)->lpVtbl -> SetSymbolManager(This,pISym)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IDisFmt_GetInstructionString_Proxy( 
    IDisFmt __RPC_FAR * This,
    /* [in] */ PINSTRUCTION pInst,
    /* [out] */ BSTR __RPC_FAR *pbStr);


void __RPC_STUB IDisFmt_GetInstructionString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisFmt_SetSymbolManager_Proxy( 
    IDisFmt __RPC_FAR * This,
    /* [in] */ IDisSymMgr __RPC_FAR *pISym);


void __RPC_STUB IDisFmt_SetSymbolManager_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDisFmt_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
