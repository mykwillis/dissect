/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun May 24 09:03:50 1998
 */
/* Compiler settings for cfg.idl:
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

#ifndef __cfg_h__
#define __cfg_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IDisEnumBASIC_BLOCK_FWD_DEFINED__
#define __IDisEnumBASIC_BLOCK_FWD_DEFINED__
typedef interface IDisEnumBASIC_BLOCK IDisEnumBASIC_BLOCK;
#endif 	/* __IDisEnumBASIC_BLOCK_FWD_DEFINED__ */


#ifndef __IDisCfg_FWD_DEFINED__
#define __IDisCfg_FWD_DEFINED__
typedef interface IDisCfg IDisCfg;
#endif 	/* __IDisCfg_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "dis.h"
#include "ldr.h"
#include "sym.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL__intf_0000
 * at Sun May 24 09:03:50 1998
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


typedef 
enum tagREFTYPE
    {	REFTYPE_UJMP	= 1,
	REFTYPE_CJMP	= REFTYPE_UJMP + 1,
	REFTYPE_CALL	= REFTYPE_CJMP + 1
    }	REFTYPE;

typedef struct  tagDIS_REF
    {
    DWORD Address;
    CTRL_FLOW_TYPE Type;
    }	DIS_REF;

typedef 
enum tagBB_FLAGS
    {	BB_PARSE_INCOMPLETE	= 0
    }	BB_FLAGS;

typedef struct  tagBASIC_BLOCK
    {
    CTRL_FLOW Flow;
    DWORD Size;
    DWORD Address;
    DWORD EdgesIn;
    int StackAdjustment;
    DWORD Flags;
    }	BASIC_BLOCK;

typedef struct  tagPROCEDURE
    {
    DWORD Address;
    DWORD Size;
    DWORD NumberOfBasicBlocks;
    /* [size_is] */ DWORD __RPC_FAR *BasicBlocks;
    }	PROCEDURE;



extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_s_ifspec;

#ifndef __IDisEnumBASIC_BLOCK_INTERFACE_DEFINED__
#define __IDisEnumBASIC_BLOCK_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IDisEnumBASIC_BLOCK
 * at Sun May 24 09:03:50 1998
 * using MIDL 3.00.44
 ****************************************/
/* [object][uuid] */ 



EXTERN_C const IID IID_IDisEnumBASIC_BLOCK;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IDisEnumBASIC_BLOCK : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            ULONG celt,
            BASIC_BLOCK __RPC_FAR *rgelt,
            ULONG __RPC_FAR *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            IDisEnumBASIC_BLOCK __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDisEnumBASIC_BLOCKVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDisEnumBASIC_BLOCK __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDisEnumBASIC_BLOCK __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDisEnumBASIC_BLOCK __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IDisEnumBASIC_BLOCK __RPC_FAR * This,
            ULONG celt,
            BASIC_BLOCK __RPC_FAR *rgelt,
            ULONG __RPC_FAR *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IDisEnumBASIC_BLOCK __RPC_FAR * This,
            ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IDisEnumBASIC_BLOCK __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IDisEnumBASIC_BLOCK __RPC_FAR * This,
            IDisEnumBASIC_BLOCK __RPC_FAR *__RPC_FAR *ppEnum);
        
        END_INTERFACE
    } IDisEnumBASIC_BLOCKVtbl;

    interface IDisEnumBASIC_BLOCK
    {
        CONST_VTBL struct IDisEnumBASIC_BLOCKVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDisEnumBASIC_BLOCK_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDisEnumBASIC_BLOCK_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDisEnumBASIC_BLOCK_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDisEnumBASIC_BLOCK_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IDisEnumBASIC_BLOCK_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IDisEnumBASIC_BLOCK_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IDisEnumBASIC_BLOCK_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IDisEnumBASIC_BLOCK_Next_Proxy( 
    IDisEnumBASIC_BLOCK __RPC_FAR * This,
    ULONG celt,
    BASIC_BLOCK __RPC_FAR *rgelt,
    ULONG __RPC_FAR *pceltFetched);


void __RPC_STUB IDisEnumBASIC_BLOCK_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisEnumBASIC_BLOCK_Skip_Proxy( 
    IDisEnumBASIC_BLOCK __RPC_FAR * This,
    ULONG celt);


void __RPC_STUB IDisEnumBASIC_BLOCK_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisEnumBASIC_BLOCK_Reset_Proxy( 
    IDisEnumBASIC_BLOCK __RPC_FAR * This);


void __RPC_STUB IDisEnumBASIC_BLOCK_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisEnumBASIC_BLOCK_Clone_Proxy( 
    IDisEnumBASIC_BLOCK __RPC_FAR * This,
    IDisEnumBASIC_BLOCK __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IDisEnumBASIC_BLOCK_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDisEnumBASIC_BLOCK_INTERFACE_DEFINED__ */


#ifndef __IDisCfg_INTERFACE_DEFINED__
#define __IDisCfg_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IDisCfg
 * at Sun May 24 09:03:50 1998
 * using MIDL 3.00.44
 ****************************************/
/* [object][uuid] */ 



EXTERN_C const IID IID_IDisCfg;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IDisCfg : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Attach( 
            /* [in] */ IDisLdr __RPC_FAR *pILdr,
            /* [in] */ IDisDis __RPC_FAR *pIDis,
            /* [in] */ IDisSymMgr __RPC_FAR *pISym) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEdgesIn( 
            /* [in] */ DWORD Address,
            /* [size_is][out] */ DIS_REF __RPC_FAR *Refs,
            /* [out][in] */ int __RPC_FAR *count) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Parse( 
            /* [in] */ DWORD Address) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ParseAllSymbols( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumBasicBlocks( 
            /* [out] */ IDisEnumBASIC_BLOCK __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNextBasicBlock( 
            /* [in] */ DWORD Address,
            /* [out] */ BASIC_BLOCK __RPC_FAR *BasicBlock) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ParseProcedure( 
            /* [in] */ DWORD Address,
            /* [out] */ PROCEDURE __RPC_FAR *Procedure) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDataReferences( 
            /* [in] */ DWORD Address,
            /* [out] */ IEnumInstructions __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDisCfgVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDisCfg __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDisCfg __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDisCfg __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Attach )( 
            IDisCfg __RPC_FAR * This,
            /* [in] */ IDisLdr __RPC_FAR *pILdr,
            /* [in] */ IDisDis __RPC_FAR *pIDis,
            /* [in] */ IDisSymMgr __RPC_FAR *pISym);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEdgesIn )( 
            IDisCfg __RPC_FAR * This,
            /* [in] */ DWORD Address,
            /* [size_is][out] */ DIS_REF __RPC_FAR *Refs,
            /* [out][in] */ int __RPC_FAR *count);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Parse )( 
            IDisCfg __RPC_FAR * This,
            /* [in] */ DWORD Address);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ParseAllSymbols )( 
            IDisCfg __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clear )( 
            IDisCfg __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumBasicBlocks )( 
            IDisCfg __RPC_FAR * This,
            /* [out] */ IDisEnumBASIC_BLOCK __RPC_FAR *__RPC_FAR *ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNextBasicBlock )( 
            IDisCfg __RPC_FAR * This,
            /* [in] */ DWORD Address,
            /* [out] */ BASIC_BLOCK __RPC_FAR *BasicBlock);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ParseProcedure )( 
            IDisCfg __RPC_FAR * This,
            /* [in] */ DWORD Address,
            /* [out] */ PROCEDURE __RPC_FAR *Procedure);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDataReferences )( 
            IDisCfg __RPC_FAR * This,
            /* [in] */ DWORD Address,
            /* [out] */ IEnumInstructions __RPC_FAR *__RPC_FAR *ppEnum);
        
        END_INTERFACE
    } IDisCfgVtbl;

    interface IDisCfg
    {
        CONST_VTBL struct IDisCfgVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDisCfg_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDisCfg_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDisCfg_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDisCfg_Attach(This,pILdr,pIDis,pISym)	\
    (This)->lpVtbl -> Attach(This,pILdr,pIDis,pISym)

#define IDisCfg_GetEdgesIn(This,Address,Refs,count)	\
    (This)->lpVtbl -> GetEdgesIn(This,Address,Refs,count)

#define IDisCfg_Parse(This,Address)	\
    (This)->lpVtbl -> Parse(This,Address)

#define IDisCfg_ParseAllSymbols(This)	\
    (This)->lpVtbl -> ParseAllSymbols(This)

#define IDisCfg_Clear(This)	\
    (This)->lpVtbl -> Clear(This)

#define IDisCfg_EnumBasicBlocks(This,ppEnum)	\
    (This)->lpVtbl -> EnumBasicBlocks(This,ppEnum)

#define IDisCfg_GetNextBasicBlock(This,Address,BasicBlock)	\
    (This)->lpVtbl -> GetNextBasicBlock(This,Address,BasicBlock)

#define IDisCfg_ParseProcedure(This,Address,Procedure)	\
    (This)->lpVtbl -> ParseProcedure(This,Address,Procedure)

#define IDisCfg_GetDataReferences(This,Address,ppEnum)	\
    (This)->lpVtbl -> GetDataReferences(This,Address,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IDisCfg_Attach_Proxy( 
    IDisCfg __RPC_FAR * This,
    /* [in] */ IDisLdr __RPC_FAR *pILdr,
    /* [in] */ IDisDis __RPC_FAR *pIDis,
    /* [in] */ IDisSymMgr __RPC_FAR *pISym);


void __RPC_STUB IDisCfg_Attach_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisCfg_GetEdgesIn_Proxy( 
    IDisCfg __RPC_FAR * This,
    /* [in] */ DWORD Address,
    /* [size_is][out] */ DIS_REF __RPC_FAR *Refs,
    /* [out][in] */ int __RPC_FAR *count);


void __RPC_STUB IDisCfg_GetEdgesIn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisCfg_Parse_Proxy( 
    IDisCfg __RPC_FAR * This,
    /* [in] */ DWORD Address);


void __RPC_STUB IDisCfg_Parse_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisCfg_ParseAllSymbols_Proxy( 
    IDisCfg __RPC_FAR * This);


void __RPC_STUB IDisCfg_ParseAllSymbols_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisCfg_Clear_Proxy( 
    IDisCfg __RPC_FAR * This);


void __RPC_STUB IDisCfg_Clear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisCfg_EnumBasicBlocks_Proxy( 
    IDisCfg __RPC_FAR * This,
    /* [out] */ IDisEnumBASIC_BLOCK __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IDisCfg_EnumBasicBlocks_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisCfg_GetNextBasicBlock_Proxy( 
    IDisCfg __RPC_FAR * This,
    /* [in] */ DWORD Address,
    /* [out] */ BASIC_BLOCK __RPC_FAR *BasicBlock);


void __RPC_STUB IDisCfg_GetNextBasicBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisCfg_ParseProcedure_Proxy( 
    IDisCfg __RPC_FAR * This,
    /* [in] */ DWORD Address,
    /* [out] */ PROCEDURE __RPC_FAR *Procedure);


void __RPC_STUB IDisCfg_ParseProcedure_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisCfg_GetDataReferences_Proxy( 
    IDisCfg __RPC_FAR * This,
    /* [in] */ DWORD Address,
    /* [out] */ IEnumInstructions __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IDisCfg_GetDataReferences_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDisCfg_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
