/* this ALWAYS GENERATED file contains the proxy stub code */


/* File created by MIDL compiler version 3.00.44 */
/* at Mon Apr 13 20:19:06 1998
 */
/* Compiler settings for fmt.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )

#include "rpcproxy.h"
#include "fmt.h"

#define TYPE_FORMAT_STRING_SIZE   421                               
#define PROC_FORMAT_STRING_SIZE   17                                

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDisFmt, ver. 0.0,
   GUID={0x460558A0,0x6496,0x11d1,{0xAE,0x3C,0x00,0x00,0xC0,0x86,0x6B,0x0E}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")

HRESULT STDMETHODCALLTYPE IDisFmt_GetInstructionString_Proxy( 
    IDisFmt __RPC_FAR * This,
    /* [in] */ PINSTRUCTION pInst,
    /* [out] */ BSTR __RPC_FAR *pbStr)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    MIDL_memset(
               pbStr,
               0,
               sizeof( BSTR  ));
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      3);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrComplexStructBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                        (unsigned char __RPC_FAR *)pInst,
                                        (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[334] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrComplexStructMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                      (unsigned char __RPC_FAR *)pInst,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[334] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[0] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pbStr,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[392],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[364],
                         ( void __RPC_FAR * )pbStr);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IDisFmt_GetInstructionString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR _M0;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    PINSTRUCTION pInst;
    BSTR __RPC_FAR *pbStr;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    pInst = 0;
    pbStr = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[0] );
        
        NdrComplexStructUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                    (unsigned char __RPC_FAR * __RPC_FAR *)&pInst,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[334],
                                    (unsigned char)0 );
        
        pbStr = &_M0;
        MIDL_memset(
               pbStr,
               0,
               sizeof( BSTR  ));
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IDisFmt *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetInstructionString(
                        (IDisFmt *) ((CStdStubBuffer *)This)->pvServerObject,
                        pInst,
                        pbStr);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)pbStr,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[392] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)pbStr,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[392] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)pInst,
                        &__MIDL_TypeFormatString.Format[0] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)pbStr,
                        &__MIDL_TypeFormatString.Format[364] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IDisFmt_SetSymbolManager_Proxy( 
    IDisFmt __RPC_FAR * This,
    /* [in] */ IDisSymMgr __RPC_FAR *pISym)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      4);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrInterfacePointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                           (unsigned char __RPC_FAR *)pISym,
                                           (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[402] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrInterfacePointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                         (unsigned char __RPC_FAR *)pISym,
                                         (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[402] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[10] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IDisFmt_SetSymbolManager_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    IDisSymMgr __RPC_FAR *pISym;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    pISym = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[10] );
        
        NdrInterfacePointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR * __RPC_FAR *)&pISym,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[402],
                                       (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IDisFmt *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetSymbolManager((IDisFmt *) ((CStdStubBuffer *)This)->pvServerObject,pISym);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrInterfacePointerFree( &_StubMsg,
                                 (unsigned char __RPC_FAR *)pISym,
                                 &__MIDL_TypeFormatString.Format[402] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[1];

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    0, /* -error bounds_check flag */
    0x20000, /* Ndr library version */
    0,
    0x300002c, /* MIDL Version 3.0.44 */
    0,
    UserMarshalRoutines,
    0,  /* Reserved1 */
    0,  /* Reserved2 */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
    };

const CINTERFACE_PROXY_VTABLE(5) _IDisFmtProxyVtbl = 
{
    &IID_IDisFmt,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IDisFmt_GetInstructionString_Proxy ,
    IDisFmt_SetSymbolManager_Proxy
};


static const PRPC_STUB_FUNCTION IDisFmt_table[] =
{
    IDisFmt_GetInstructionString_Stub,
    IDisFmt_SetSymbolManager_Stub
};

const CInterfaceStubVtbl _IDisFmtStubVtbl =
{
    &IID_IDisFmt,
    0,
    5,
    &IDisFmt_table[-3],
    CStdStubBuffer_METHODS
};

#pragma data_seg(".rdata")

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[1] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            }

        };


#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT40_OR_LATER)
#error You need a Windows NT 4.0 or later to run this stub
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {
			
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/*  2 */	NdrFcShort( 0x0 ),	/* Type Offset=0 */
/*  4 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/*  6 */	NdrFcShort( 0x16c ),	/* Type Offset=364 */
/*  8 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 10 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 12 */	NdrFcShort( 0x192 ),	/* Type Offset=402 */
/* 14 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			0x11, 0x0,	/* FC_RP */
/*  2 */	NdrFcShort( 0x14c ),	/* Offset= 332 (334) */
/*  4 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/*  6 */	NdrFcShort( 0x10 ),	/* 16 */
/*  8 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 10 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 12 */	NdrFcShort( 0x20 ),	/* 32 */
/* 14 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 16 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0xd,		/* FC_ENUM16 */
/* 18 */	0x6,		/* 6 */
			0x0,		/*  */
/* 20 */	NdrFcShort( 0xfffffff8 ),	/* -8 */
/* 22 */	NdrFcShort( 0x2 ),	/* Offset= 2 (24) */
/* 24 */	NdrFcShort( 0x38 ),	/* 56 */
/* 26 */	NdrFcShort( 0x6 ),	/* 6 */
/* 28 */	NdrFcLong( 0x3 ),	/* 3 */
/* 32 */	NdrFcShort( 0x5c ),	/* Offset= 92 (124) */
/* 34 */	NdrFcLong( 0x1 ),	/* 1 */
/* 38 */	NdrFcShort( 0x1c ),	/* Offset= 28 (66) */
/* 40 */	NdrFcLong( 0x2 ),	/* 2 */
/* 44 */	NdrFcShort( 0x72 ),	/* Offset= 114 (158) */
/* 46 */	NdrFcLong( 0x4 ),	/* 4 */
/* 50 */	NdrFcShort( 0x7e ),	/* Offset= 126 (176) */
/* 52 */	NdrFcLong( 0x5 ),	/* 5 */
/* 56 */	NdrFcShort( 0xa4 ),	/* Offset= 164 (220) */
/* 58 */	NdrFcLong( 0x6 ),	/* 6 */
/* 62 */	NdrFcShort( 0xda ),	/* Offset= 218 (280) */
/* 64 */	NdrFcShort( 0x0 ),	/* Offset= 0 (64) */
/* 66 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x1,		/* 1 */
/* 68 */	NdrFcShort( 0x8 ),	/* 8 */
/* 70 */	NdrFcShort( 0x0 ),	/* 0 */
/* 72 */	NdrFcShort( 0x0 ),	/* Offset= 0 (72) */
/* 74 */	0xd,		/* FC_ENUM16 */
			0xd,		/* FC_ENUM16 */
/* 76 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 78 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0xd,		/* FC_ENUM16 */
/* 80 */	0x6,		/* 6 */
			0x0,		/*  */
/* 82 */	NdrFcShort( 0xffffffdc ),	/* -36 */
/* 84 */	NdrFcShort( 0x2 ),	/* Offset= 2 (86) */
/* 86 */	NdrFcShort( 0x8 ),	/* 8 */
/* 88 */	NdrFcShort( 0x4 ),	/* 4 */
/* 90 */	NdrFcLong( 0x8 ),	/* 8 */
/* 94 */	NdrFcShort( 0xffff8002 ),	/* Offset= -32766 (-32672) */
/* 96 */	NdrFcLong( 0x10 ),	/* 16 */
/* 100 */	NdrFcShort( 0xffff8006 ),	/* Offset= -32762 (-32662) */
/* 102 */	NdrFcLong( 0x20 ),	/* 32 */
/* 106 */	NdrFcShort( 0xffff8008 ),	/* Offset= -32760 (-32654) */
/* 108 */	NdrFcLong( 0x40 ),	/* 64 */
/* 112 */	NdrFcShort( 0x4 ),	/* Offset= 4 (116) */
/* 114 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (113) */
/* 116 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 118 */	NdrFcShort( 0x8 ),	/* 8 */
/* 120 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 122 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 124 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 126 */	NdrFcShort( 0x38 ),	/* 56 */
/* 128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0x0 ),	/* Offset= 0 (130) */
/* 132 */	0xd,		/* FC_ENUM16 */
			0xd,		/* FC_ENUM16 */
/* 134 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 136 */	NdrFcShort( 0xffffffba ),	/* Offset= -70 (66) */
/* 138 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 140 */	NdrFcShort( 0xffffffb6 ),	/* Offset= -74 (66) */
/* 142 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 144 */	NdrFcShort( 0xffffffb2 ),	/* Offset= -78 (66) */
/* 146 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 148 */	0x0,		/* 0 */
			NdrFcShort( 0xffffffb9 ),	/* Offset= -71 (78) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 152 */	0x0,		/* 0 */
			NdrFcShort( 0xffffffa9 ),	/* Offset= -87 (66) */
			0x8,		/* FC_LONG */
/* 156 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 158 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x1,		/* 1 */
/* 160 */	NdrFcShort( 0x2 ),	/* 2 */
/* 162 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 166 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 170 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 172 */	NdrFcShort( 0xffffff96 ),	/* Offset= -106 (66) */
/* 174 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 176 */	
			0x15,		/* FC_STRUCT */
			0x1,		/* 1 */
/* 178 */	NdrFcShort( 0x2 ),	/* 2 */
/* 180 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 182 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0xd,		/* FC_ENUM16 */
/* 184 */	0x6,		/* 6 */
			0x0,		/*  */
/* 186 */	NdrFcShort( 0xfffffffc ),	/* -4 */
/* 188 */	NdrFcShort( 0x2 ),	/* Offset= 2 (190) */
/* 190 */	NdrFcShort( 0x8 ),	/* 8 */
/* 192 */	NdrFcShort( 0x4 ),	/* 4 */
/* 194 */	NdrFcLong( 0x8 ),	/* 8 */
/* 198 */	NdrFcShort( 0xffff8002 ),	/* Offset= -32766 (-32568) */
/* 200 */	NdrFcLong( 0x10 ),	/* 16 */
/* 204 */	NdrFcShort( 0xffff8006 ),	/* Offset= -32762 (-32558) */
/* 206 */	NdrFcLong( 0x20 ),	/* 32 */
/* 210 */	NdrFcShort( 0xffff8008 ),	/* Offset= -32760 (-32550) */
/* 212 */	NdrFcLong( 0x40 ),	/* 64 */
/* 216 */	NdrFcShort( 0xffffff9c ),	/* Offset= -100 (116) */
/* 218 */	NdrFcShort( 0x0 ),	/* Offset= 0 (218) */
/* 220 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 222 */	NdrFcShort( 0xc ),	/* 12 */
/* 224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 226 */	NdrFcShort( 0x0 ),	/* Offset= 0 (226) */
/* 228 */	0xd,		/* FC_ENUM16 */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 230 */	0x0,		/* 0 */
			NdrFcShort( 0xffffffcf ),	/* Offset= -49 (182) */
			0x5b,		/* FC_END */
/* 234 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0xd,		/* FC_ENUM16 */
/* 236 */	0x6,		/* 6 */
			0x0,		/*  */
/* 238 */	NdrFcShort( 0xfffffffc ),	/* -4 */
/* 240 */	NdrFcShort( 0x2 ),	/* Offset= 2 (242) */
/* 242 */	NdrFcShort( 0x8 ),	/* 8 */
/* 244 */	NdrFcShort( 0x4 ),	/* 4 */
/* 246 */	NdrFcLong( 0x10 ),	/* 16 */
/* 250 */	NdrFcShort( 0xffff8006 ),	/* Offset= -32762 (-32512) */
/* 252 */	NdrFcLong( 0x20 ),	/* 32 */
/* 256 */	NdrFcShort( 0xffff8008 ),	/* Offset= -32760 (-32504) */
/* 258 */	NdrFcLong( 0x30 ),	/* 48 */
/* 262 */	NdrFcShort( 0xa ),	/* Offset= 10 (272) */
/* 264 */	NdrFcLong( 0x40 ),	/* 64 */
/* 268 */	NdrFcShort( 0xffffff68 ),	/* Offset= -152 (116) */
/* 270 */	NdrFcShort( 0x0 ),	/* Offset= 0 (270) */
/* 272 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 274 */	NdrFcShort( 0x8 ),	/* 8 */
/* 276 */	0x6,		/* FC_SHORT */
			0x38,		/* FC_ALIGNM4 */
/* 278 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 280 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 282 */	NdrFcShort( 0xc ),	/* 12 */
/* 284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 286 */	NdrFcShort( 0x0 ),	/* Offset= 0 (286) */
/* 288 */	0xd,		/* FC_ENUM16 */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 290 */	0x0,		/* 0 */
			NdrFcShort( 0xffffffc7 ),	/* Offset= -57 (234) */
			0x5b,		/* FC_END */
/* 294 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 296 */	NdrFcShort( 0x40 ),	/* 64 */
/* 298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 300 */	NdrFcShort( 0x0 ),	/* Offset= 0 (300) */
/* 302 */	0xd,		/* FC_ENUM16 */
			0x8,		/* FC_LONG */
/* 304 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 306 */	NdrFcShort( 0xfffffede ),	/* Offset= -290 (16) */
/* 308 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 310 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 312 */	NdrFcShort( 0x3 ),	/* 3 */
/* 314 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 318 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 322 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 324 */	NdrFcShort( 0xffffffe2 ),	/* Offset= -30 (294) */
/* 326 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 328 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 330 */	NdrFcShort( 0x4 ),	/* 4 */
/* 332 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 334 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 336 */	NdrFcShort( 0x100 ),	/* 256 */
/* 338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 340 */	NdrFcShort( 0x14 ),	/* Offset= 20 (360) */
/* 342 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 344 */	0x0,		/* 0 */
			NdrFcShort( 0xfffffeab ),	/* Offset= -341 (4) */
			0x8,		/* FC_LONG */
/* 348 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 350 */	0x0,		/* 0 */
			NdrFcShort( 0xfffffeab ),	/* Offset= -341 (10) */
			0x8,		/* FC_LONG */
/* 354 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 356 */	NdrFcShort( 0xffffffd2 ),	/* Offset= -46 (310) */
/* 358 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 360 */	
			0x12, 0x0,	/* FC_UP */
/* 362 */	NdrFcShort( 0xffffffde ),	/* Offset= -34 (328) */
/* 364 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 366 */	NdrFcShort( 0x1a ),	/* Offset= 26 (392) */
/* 368 */	
			0x13, 0x0,	/* FC_OP */
/* 370 */	NdrFcShort( 0xc ),	/* Offset= 12 (382) */
/* 372 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 374 */	NdrFcShort( 0x2 ),	/* 2 */
/* 376 */	0x9,		/* 9 */
			0x0,		/*  */
/* 378 */	NdrFcShort( 0xfffffffc ),	/* -4 */
/* 380 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 382 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 384 */	NdrFcShort( 0x8 ),	/* 8 */
/* 386 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (372) */
/* 388 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 390 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 392 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 396 */	NdrFcShort( 0x4 ),	/* 4 */
/* 398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 400 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (368) */
/* 402 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 404 */	NdrFcLong( 0x215643d0 ),	/* 559301584 */
/* 408 */	NdrFcShort( 0xffffbba7 ),	/* -17497 */
/* 410 */	NdrFcShort( 0x11d1 ),	/* 4561 */
/* 412 */	0xae,		/* 174 */
			0x8f,		/* 143 */
/* 414 */	0xb8,		/* 184 */
			0xbb,		/* 187 */
/* 416 */	0x59,		/* 89 */
			0x0,		/* 0 */
/* 418 */	0x0,		/* 0 */
			0x0,		/* 0 */

			0x0
        }
    };

const CInterfaceProxyVtbl * _fmt_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IDisFmtProxyVtbl,
    0
};

const CInterfaceStubVtbl * _fmt_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IDisFmtStubVtbl,
    0
};

PCInterfaceName const _fmt_InterfaceNamesList[] = 
{
    "IDisFmt",
    0
};


#define _fmt_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _fmt, pIID, n)

int __stdcall _fmt_IID_Lookup( const IID * pIID, int * pIndex )
{
    
    if(!_fmt_CHECK_IID(0))
        {
        *pIndex = 0;
        return 1;
        }

    return 0;
}

const ExtendedProxyFileInfo fmt_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _fmt_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _fmt_StubVtblList,
    (const PCInterfaceName * ) & _fmt_InterfaceNamesList,
    0, // no delegation
    & _fmt_IID_Lookup, 
    1,
    1
};
