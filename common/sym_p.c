/* this ALWAYS GENERATED file contains the proxy stub code */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun May 24 08:36:22 1998
 */
/* Compiler settings for sym.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )

#include "rpcproxy.h"
#include "sym.h"

#define TYPE_FORMAT_STRING_SIZE   1915                              
#define PROC_FORMAT_STRING_SIZE   327                               

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


/* Standard interface: __MIDL__intf_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IType, ver. 0.0,
   GUID={0xAFAEAFC0,0xE089,0x11d1,{0xAE,0xB5,0xBE,0xBB,0x53,0x00,0x00,0x00}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")

HRESULT STDMETHODCALLTYPE IType_SetName_Proxy( 
    IType __RPC_FAR * This,
    /* [in] */ BSTR Name)
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
                      3);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&Name,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[24] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&Name,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[24] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[0] );
            
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

void __RPC_STUB IType_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR Name;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_Name;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_Name = &Name;
    MIDL_memset(
               _p_Name,
               0,
               sizeof( BSTR  ));
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[0] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_Name,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[24],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IType *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetName((IType *) ((CStdStubBuffer *)This)->pvServerObject,Name);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&Name,
                            &__MIDL_TypeFormatString.Format[24] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IType_SetDocString_Proxy( 
    IType __RPC_FAR * This,
    /* [in] */ BSTR DocString)
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
            
            _StubMsg.BufferLength = 4U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&DocString,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[34] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&DocString,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[34] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[6] );
            
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

void __RPC_STUB IType_SetDocString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR DocString;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_DocString;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_DocString = &DocString;
    MIDL_memset(
               _p_DocString,
               0,
               sizeof( BSTR  ));
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[6] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_DocString,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[34],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IType *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetDocString((IType *) ((CStdStubBuffer *)This)->pvServerObject,DocString);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&DocString,
                            &__MIDL_TypeFormatString.Format[34] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IType_SetMemberName_Proxy( 
    IType __RPC_FAR * This,
    /* [in] */ int Position,
    /* [in] */ BSTR Name)
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
                      5);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 4U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&Name,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[44] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( int __RPC_FAR * )_StubMsg.Buffer)++ = Position;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&Name,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[44] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[12] );
            
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

void __RPC_STUB IType_SetMemberName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR Name;
    int Position;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_Name;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_Name = &Name;
    MIDL_memset(
               _p_Name,
               0,
               sizeof( BSTR  ));
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[12] );
        
        Position = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_Name,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[44],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IType *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetMemberName(
                 (IType *) ((CStdStubBuffer *)This)->pvServerObject,
                 Position,
                 Name);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&Name,
                            &__MIDL_TypeFormatString.Format[44] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IType_SetMemberType_Proxy( 
    IType __RPC_FAR * This,
    /* [in] */ int Position,
    /* [in] */ HTYPE Type)
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
                      6);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 0U;
            NdrSimpleStructBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)Type,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[58] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( int __RPC_FAR * )_StubMsg.Buffer)++ = Position;
            
            NdrSimpleStructMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)Type,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[58] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[20] );
            
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

void __RPC_STUB IType_SetMemberType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    int Position;
    HTYPE Type;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    Type = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[20] );
        
        Position = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrSimpleStructUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                   (unsigned char __RPC_FAR * __RPC_FAR *)&Type,
                                   (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[58],
                                   (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IType *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetMemberType(
                 (IType *) ((CStdStubBuffer *)This)->pvServerObject,
                 Position,
                 Type);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IType_SetMemberValue_Proxy( 
    IType __RPC_FAR * This,
    /* [in] */ int Position,
    /* [in] */ DWORD Value)
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
                      7);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 4U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( int __RPC_FAR * )_StubMsg.Buffer)++ = Position;
            
            *(( DWORD __RPC_FAR * )_StubMsg.Buffer)++ = Value;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[28] );
            
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

void __RPC_STUB IType_SetMemberValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    int Position;
    DWORD Value;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[28] );
        
        Position = *(( int __RPC_FAR * )_StubMsg.Buffer)++;
        
        Value = *(( DWORD __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IType *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetMemberValue(
                  (IType *) ((CStdStubBuffer *)This)->pvServerObject,
                  Position,
                  Value);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IType_GetTypeInfo_Proxy( 
    IType __RPC_FAR * This,
    /* [out] */ TYPE_INFO __RPC_FAR *__RPC_FAR *TypeInfo)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    *TypeInfo = 0;
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      8);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[34] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&TypeInfo,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[64],
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
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[64],
                         ( void __RPC_FAR * )TypeInfo);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IType_GetTypeInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    TYPE_INFO __RPC_FAR *__RPC_FAR *TypeInfo;
    TYPE_INFO __RPC_FAR *_M0;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    TypeInfo = 0;
    RpcTryFinally
        {
        TypeInfo = &_M0;
        _M0 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IType *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetTypeInfo((IType *) ((CStdStubBuffer *)This)->pvServerObject,TypeInfo);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 11U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)TypeInfo,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[64] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)TypeInfo,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[64] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)TypeInfo,
                        &__MIDL_TypeFormatString.Format[64] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IType_ReleaseTypeInfo_Proxy( 
    IType __RPC_FAR * This,
    /* [in] */ TYPE_INFO __RPC_FAR *TypeInfo)
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
                      9);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrComplexStructBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                        (unsigned char __RPC_FAR *)TypeInfo,
                                        (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[374] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrComplexStructMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                      (unsigned char __RPC_FAR *)TypeInfo,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[374] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[40] );
            
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

void __RPC_STUB IType_ReleaseTypeInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    TYPE_INFO __RPC_FAR *TypeInfo;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    TypeInfo = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[40] );
        
        NdrComplexStructUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                    (unsigned char __RPC_FAR * __RPC_FAR *)&TypeInfo,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[374],
                                    (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IType *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> ReleaseTypeInfo((IType *) ((CStdStubBuffer *)This)->pvServerObject,TypeInfo);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)TypeInfo,
                        &__MIDL_TypeFormatString.Format[398] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

const CINTERFACE_PROXY_VTABLE(10) _ITypeProxyVtbl = 
{
    &IID_IType,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IType_SetName_Proxy ,
    IType_SetDocString_Proxy ,
    IType_SetMemberName_Proxy ,
    IType_SetMemberType_Proxy ,
    IType_SetMemberValue_Proxy ,
    IType_GetTypeInfo_Proxy ,
    IType_ReleaseTypeInfo_Proxy
};


static const PRPC_STUB_FUNCTION IType_table[] =
{
    IType_SetName_Stub,
    IType_SetDocString_Stub,
    IType_SetMemberName_Stub,
    IType_SetMemberType_Stub,
    IType_SetMemberValue_Stub,
    IType_GetTypeInfo_Stub,
    IType_ReleaseTypeInfo_Stub
};

const CInterfaceStubVtbl _ITypeStubVtbl =
{
    &IID_IType,
    0,
    10,
    &IType_table[-3],
    CStdStubBuffer_METHODS
};


/* Object interface: ISymbol, ver. 0.0,
   GUID={0xD8FCD7C0,0xE088,0x11d1,{0xAE,0xB5,0xBE,0xBB,0x53,0x00,0x00,0x00}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")

HRESULT STDMETHODCALLTYPE ISymbol_GetSymbolInfo_Proxy( 
    ISymbol __RPC_FAR * This,
    /* [out] */ SYMBOL_INFO __RPC_FAR *__RPC_FAR *SymbolInfo)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    *SymbolInfo = 0;
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
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[46] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&SymbolInfo,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[402],
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
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[402],
                         ( void __RPC_FAR * )SymbolInfo);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB ISymbol_GetSymbolInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SYMBOL_INFO __RPC_FAR *__RPC_FAR *SymbolInfo;
    SYMBOL_INFO __RPC_FAR *_M1;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    SymbolInfo = 0;
    RpcTryFinally
        {
        SymbolInfo = &_M1;
        _M1 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((ISymbol *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetSymbolInfo((ISymbol *) ((CStdStubBuffer *)This)->pvServerObject,SymbolInfo);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 11U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)SymbolInfo,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[402] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)SymbolInfo,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[402] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)SymbolInfo,
                        &__MIDL_TypeFormatString.Format[402] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE ISymbol_ReleaseSymbolInfo_Proxy( 
    ISymbol __RPC_FAR * This,
    /* [in] */ SYMBOL_INFO __RPC_FAR *SymbolInfo)
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
            NdrComplexStructBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                        (unsigned char __RPC_FAR *)SymbolInfo,
                                        (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[566] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrComplexStructMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                      (unsigned char __RPC_FAR *)SymbolInfo,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[566] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[52] );
            
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

void __RPC_STUB ISymbol_ReleaseSymbolInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SYMBOL_INFO __RPC_FAR *SymbolInfo;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    SymbolInfo = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[52] );
        
        NdrComplexStructUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                    (unsigned char __RPC_FAR * __RPC_FAR *)&SymbolInfo,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[566],
                                    (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((ISymbol *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> ReleaseSymbolInfo((ISymbol *) ((CStdStubBuffer *)This)->pvServerObject,SymbolInfo);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)SymbolInfo,
                        &__MIDL_TypeFormatString.Format[590] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

const CINTERFACE_PROXY_VTABLE(5) _ISymbolProxyVtbl = 
{
    &IID_ISymbol,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    ISymbol_GetSymbolInfo_Proxy ,
    ISymbol_ReleaseSymbolInfo_Proxy
};


static const PRPC_STUB_FUNCTION ISymbol_table[] =
{
    ISymbol_GetSymbolInfo_Stub,
    ISymbol_ReleaseSymbolInfo_Stub
};

const CInterfaceStubVtbl _ISymbolStubVtbl =
{
    &IID_ISymbol,
    0,
    5,
    &ISymbol_table[-3],
    CStdStubBuffer_METHODS
};


/* Object interface: IModule, ver. 0.0,
   GUID={0xA1A6D0F0,0xDE0D,0x11d1,{0xAE,0xB3,0x00,0x00,0xC0,0x86,0x6B,0x0E}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")

HRESULT STDMETHODCALLTYPE IModule_GetModuleInfo_Proxy( 
    IModule __RPC_FAR * This,
    /* [out] */ MODULE_INFO __RPC_FAR *__RPC_FAR *ModuleInfo)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    *ModuleInfo = 0;
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
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[58] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ModuleInfo,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[594],
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
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[594],
                         ( void __RPC_FAR * )ModuleInfo);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IModule_GetModuleInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    MODULE_INFO __RPC_FAR *__RPC_FAR *ModuleInfo;
    MODULE_INFO __RPC_FAR *_M2;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ModuleInfo = 0;
    RpcTryFinally
        {
        ModuleInfo = &_M2;
        _M2 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IModule *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetModuleInfo((IModule *) ((CStdStubBuffer *)This)->pvServerObject,ModuleInfo);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 11U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)ModuleInfo,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[594] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)ModuleInfo,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[594] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ModuleInfo,
                        &__MIDL_TypeFormatString.Format[594] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IModule_ReleaseModuleInfo_Proxy( 
    IModule __RPC_FAR * This,
    /* [in] */ MODULE_INFO __RPC_FAR *ModuleInfo)
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
            NdrComplexStructBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                        (unsigned char __RPC_FAR *)ModuleInfo,
                                        (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[622] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrComplexStructMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                      (unsigned char __RPC_FAR *)ModuleInfo,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[622] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[64] );
            
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

void __RPC_STUB IModule_ReleaseModuleInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    MODULE_INFO __RPC_FAR *ModuleInfo;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ModuleInfo = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[64] );
        
        NdrComplexStructUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                    (unsigned char __RPC_FAR * __RPC_FAR *)&ModuleInfo,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[622],
                                    (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IModule *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> ReleaseModuleInfo((IModule *) ((CStdStubBuffer *)This)->pvServerObject,ModuleInfo);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ModuleInfo,
                        &__MIDL_TypeFormatString.Format[642] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IModule_AddSymbol_Proxy( 
    IModule __RPC_FAR * This,
    /* [out] */ ISymbol __RPC_FAR *__RPC_FAR *ppISymbol,
    /* [in] */ SYMBOL_INFO __RPC_FAR *SymbolInfo)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    *ppISymbol = 0;
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      5);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrComplexStructBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                        (unsigned char __RPC_FAR *)SymbolInfo,
                                        (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[566] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrComplexStructMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                      (unsigned char __RPC_FAR *)SymbolInfo,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[566] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[70] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ppISymbol,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[646],
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
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[646],
                         ( void __RPC_FAR * )ppISymbol);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IModule_AddSymbol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SYMBOL_INFO __RPC_FAR *SymbolInfo;
    ISymbol __RPC_FAR *_M3;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    ISymbol __RPC_FAR *__RPC_FAR *ppISymbol;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ppISymbol = 0;
    SymbolInfo = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[70] );
        
        NdrComplexStructUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                    (unsigned char __RPC_FAR * __RPC_FAR *)&SymbolInfo,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[566],
                                    (unsigned char)0 );
        
        ppISymbol = &_M3;
        _M3 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IModule *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> AddSymbol(
             (IModule *) ((CStdStubBuffer *)This)->pvServerObject,
             ppISymbol,
             SymbolInfo);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 4U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)ppISymbol,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[646] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)ppISymbol,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[646] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ppISymbol,
                        &__MIDL_TypeFormatString.Format[646] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)SymbolInfo,
                        &__MIDL_TypeFormatString.Format[590] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IModule_GetSymbolByName_Proxy( 
    IModule __RPC_FAR * This,
    /* [out] */ ISymbol __RPC_FAR *__RPC_FAR *ppIUnknown,
    /* [in] */ BSTR Name)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    *ppIUnknown = 0;
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      6);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&Name,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[668] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&Name,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[668] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[80] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ppIUnknown,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[646],
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
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[646],
                         ( void __RPC_FAR * )ppIUnknown);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IModule_GetSymbolByName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR Name;
    ISymbol __RPC_FAR *_M4;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_Name;
    ISymbol __RPC_FAR *__RPC_FAR *ppIUnknown;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ppIUnknown = 0;
    _p_Name = &Name;
    MIDL_memset(
               _p_Name,
               0,
               sizeof( BSTR  ));
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[80] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_Name,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[668],
                                  (unsigned char)0 );
        
        ppIUnknown = &_M4;
        _M4 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IModule *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetSymbolByName(
                   (IModule *) ((CStdStubBuffer *)This)->pvServerObject,
                   ppIUnknown,
                   Name);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 4U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)ppIUnknown,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[646] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)ppIUnknown,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[646] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ppIUnknown,
                        &__MIDL_TypeFormatString.Format[646] );
        
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&Name,
                            &__MIDL_TypeFormatString.Format[668] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IModule_GetSymbolByAddress_Proxy( 
    IModule __RPC_FAR * This,
    /* [out] */ ISymbol __RPC_FAR *__RPC_FAR *ppIUnknown,
    /* [in] */ DWORD Address)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    *ppIUnknown = 0;
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      7);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( DWORD __RPC_FAR * )_StubMsg.Buffer)++ = Address;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[90] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ppIUnknown,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[646],
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
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[646],
                         ( void __RPC_FAR * )ppIUnknown);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IModule_GetSymbolByAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    DWORD Address;
    ISymbol __RPC_FAR *_M5;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    ISymbol __RPC_FAR *__RPC_FAR *ppIUnknown;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ppIUnknown = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[90] );
        
        Address = *(( DWORD __RPC_FAR * )_StubMsg.Buffer)++;
        
        ppIUnknown = &_M5;
        _M5 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IModule *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetSymbolByAddress(
                      (IModule *) ((CStdStubBuffer *)This)->pvServerObject,
                      ppIUnknown,
                      Address);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 4U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)ppIUnknown,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[646] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)ppIUnknown,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[646] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ppIUnknown,
                        &__MIDL_TypeFormatString.Format[646] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IModule_EnumSymbols_Proxy( 
    IModule __RPC_FAR * This,
    /* [out] */ IEnumSymbols __RPC_FAR *__RPC_FAR *ppEnum)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    *ppEnum = 0;
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      8);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[98] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ppEnum,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[678],
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
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[678],
                         ( void __RPC_FAR * )ppEnum);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IModule_EnumSymbols_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    IEnumSymbols __RPC_FAR *_M6;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    IEnumSymbols __RPC_FAR *__RPC_FAR *ppEnum;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ppEnum = 0;
    RpcTryFinally
        {
        ppEnum = &_M6;
        _M6 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IModule *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> EnumSymbols((IModule *) ((CStdStubBuffer *)This)->pvServerObject,ppEnum);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 4U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)ppEnum,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[678] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)ppEnum,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[678] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ppEnum,
                        &__MIDL_TypeFormatString.Format[678] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

const CINTERFACE_PROXY_VTABLE(9) _IModuleProxyVtbl = 
{
    &IID_IModule,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IModule_GetModuleInfo_Proxy ,
    IModule_ReleaseModuleInfo_Proxy ,
    IModule_AddSymbol_Proxy ,
    IModule_GetSymbolByName_Proxy ,
    IModule_GetSymbolByAddress_Proxy ,
    IModule_EnumSymbols_Proxy
};


static const PRPC_STUB_FUNCTION IModule_table[] =
{
    IModule_GetModuleInfo_Stub,
    IModule_ReleaseModuleInfo_Stub,
    IModule_AddSymbol_Stub,
    IModule_GetSymbolByName_Stub,
    IModule_GetSymbolByAddress_Stub,
    IModule_EnumSymbols_Stub
};

const CInterfaceStubVtbl _IModuleStubVtbl =
{
    &IID_IModule,
    0,
    9,
    &IModule_table[-3],
    CStdStubBuffer_METHODS
};


/* Object interface: IEnumTypes, ver. 0.0,
   GUID={0x9C3EC8C0,0xE2A1,0x11d1,{0xAE,0xB8,0x00,0x00,0xC0,0x86,0x6B,0x0E}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")

HRESULT STDMETHODCALLTYPE IEnumTypes_Next_Proxy( 
    IEnumTypes __RPC_FAR * This,
    ULONG celt,
    IType __RPC_FAR *__RPC_FAR *rgelt,
    ULONG __RPC_FAR *pceltFetched)
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
                      3);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 0U + 4U;
            NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)rgelt,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[700] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( ULONG __RPC_FAR * )_StubMsg.Buffer)++ = celt;
            
            NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)rgelt,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[700] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            *(( ULONG __RPC_FAR * )_StubMsg.Buffer)++ = *pceltFetched;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[104] );
            
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

void __RPC_STUB IEnumTypes_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    ULONG celt;
    ULONG __RPC_FAR *pceltFetched;
    IType __RPC_FAR *__RPC_FAR *rgelt;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    rgelt = 0;
    pceltFetched = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[104] );
        
        celt = *(( ULONG __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR * __RPC_FAR *)&rgelt,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[700],
                              (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        pceltFetched = ( ULONG __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( ULONG  );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IEnumTypes *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Next(
        (IEnumTypes *) ((CStdStubBuffer *)This)->pvServerObject,
        celt,
        rgelt,
        pceltFetched);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)rgelt,
                        &__MIDL_TypeFormatString.Format[700] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IEnumTypes_Skip_Proxy( 
    IEnumTypes __RPC_FAR * This,
    ULONG celt)
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
            
            _StubMsg.BufferLength = 4U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( ULONG __RPC_FAR * )_StubMsg.Buffer)++ = celt;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[116] );
            
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

void __RPC_STUB IEnumTypes_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    ULONG celt;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[116] );
        
        celt = *(( ULONG __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IEnumTypes *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Skip((IEnumTypes *) ((CStdStubBuffer *)This)->pvServerObject,celt);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IEnumTypes_Reset_Proxy( 
    IEnumTypes __RPC_FAR * This)
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
                      5);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[120] );
            
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

void __RPC_STUB IEnumTypes_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IEnumTypes *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Reset((IEnumTypes *) ((CStdStubBuffer *)This)->pvServerObject);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IEnumTypes_Clone_Proxy( 
    IEnumTypes __RPC_FAR * This,
    IEnumTypes __RPC_FAR *__RPC_FAR *ppenum)
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
                      6);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)ppenum,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[726] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)ppenum,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[726] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[122] );
            
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

void __RPC_STUB IEnumTypes_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    IEnumTypes __RPC_FAR *__RPC_FAR *ppenum;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ppenum = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[122] );
        
        NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR * __RPC_FAR *)&ppenum,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[726],
                              (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IEnumTypes *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Clone((IEnumTypes *) ((CStdStubBuffer *)This)->pvServerObject,ppenum);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ppenum,
                        &__MIDL_TypeFormatString.Format[726] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

const CINTERFACE_PROXY_VTABLE(7) _IEnumTypesProxyVtbl = 
{
    &IID_IEnumTypes,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IEnumTypes_Next_Proxy ,
    IEnumTypes_Skip_Proxy ,
    IEnumTypes_Reset_Proxy ,
    IEnumTypes_Clone_Proxy
};


static const PRPC_STUB_FUNCTION IEnumTypes_table[] =
{
    IEnumTypes_Next_Stub,
    IEnumTypes_Skip_Stub,
    IEnumTypes_Reset_Stub,
    IEnumTypes_Clone_Stub
};

const CInterfaceStubVtbl _IEnumTypesStubVtbl =
{
    &IID_IEnumTypes,
    0,
    7,
    &IEnumTypes_table[-3],
    CStdStubBuffer_METHODS
};


/* Object interface: IEnumSymbols, ver. 0.0,
   GUID={0xAD8750F0,0xBBAC,0x11d1,{0xAE,0x8F,0xB8,0xBB,0x59,0x00,0x00,0x00}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")

HRESULT STDMETHODCALLTYPE IEnumSymbols_Next_Proxy( 
    IEnumSymbols __RPC_FAR * This,
    ULONG celt,
    ISymbol __RPC_FAR *__RPC_FAR *rgelt,
    ULONG __RPC_FAR *pceltFetched)
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
                      3);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 0U + 4U;
            NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)rgelt,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[748] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( ULONG __RPC_FAR * )_StubMsg.Buffer)++ = celt;
            
            NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)rgelt,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[748] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            *(( ULONG __RPC_FAR * )_StubMsg.Buffer)++ = *pceltFetched;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[128] );
            
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

void __RPC_STUB IEnumSymbols_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    ULONG celt;
    ULONG __RPC_FAR *pceltFetched;
    ISymbol __RPC_FAR *__RPC_FAR *rgelt;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    rgelt = 0;
    pceltFetched = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[128] );
        
        celt = *(( ULONG __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR * __RPC_FAR *)&rgelt,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[748],
                              (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        pceltFetched = ( ULONG __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( ULONG  );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IEnumSymbols *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Next(
        (IEnumSymbols *) ((CStdStubBuffer *)This)->pvServerObject,
        celt,
        rgelt,
        pceltFetched);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)rgelt,
                        &__MIDL_TypeFormatString.Format[748] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IEnumSymbols_Skip_Proxy( 
    IEnumSymbols __RPC_FAR * This,
    ULONG celt)
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
            
            _StubMsg.BufferLength = 4U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( ULONG __RPC_FAR * )_StubMsg.Buffer)++ = celt;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[116] );
            
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

void __RPC_STUB IEnumSymbols_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    ULONG celt;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[116] );
        
        celt = *(( ULONG __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IEnumSymbols *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Skip((IEnumSymbols *) ((CStdStubBuffer *)This)->pvServerObject,celt);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IEnumSymbols_Reset_Proxy( 
    IEnumSymbols __RPC_FAR * This)
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
                      5);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[120] );
            
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

void __RPC_STUB IEnumSymbols_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IEnumSymbols *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Reset((IEnumSymbols *) ((CStdStubBuffer *)This)->pvServerObject);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IEnumSymbols_Clone_Proxy( 
    IEnumSymbols __RPC_FAR * This,
    IEnumSymbols __RPC_FAR *__RPC_FAR *ppenum)
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
                      6);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)ppenum,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[752] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)ppenum,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[752] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[140] );
            
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

void __RPC_STUB IEnumSymbols_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    IEnumSymbols __RPC_FAR *__RPC_FAR *ppenum;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ppenum = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[140] );
        
        NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR * __RPC_FAR *)&ppenum,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[752],
                              (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IEnumSymbols *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Clone((IEnumSymbols *) ((CStdStubBuffer *)This)->pvServerObject,ppenum);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ppenum,
                        &__MIDL_TypeFormatString.Format[752] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

const CINTERFACE_PROXY_VTABLE(7) _IEnumSymbolsProxyVtbl = 
{
    &IID_IEnumSymbols,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IEnumSymbols_Next_Proxy ,
    IEnumSymbols_Skip_Proxy ,
    IEnumSymbols_Reset_Proxy ,
    IEnumSymbols_Clone_Proxy
};


static const PRPC_STUB_FUNCTION IEnumSymbols_table[] =
{
    IEnumSymbols_Next_Stub,
    IEnumSymbols_Skip_Stub,
    IEnumSymbols_Reset_Stub,
    IEnumSymbols_Clone_Stub
};

const CInterfaceStubVtbl _IEnumSymbolsStubVtbl =
{
    &IID_IEnumSymbols,
    0,
    7,
    &IEnumSymbols_table[-3],
    CStdStubBuffer_METHODS
};


/* Object interface: IEnumModules, ver. 0.0,
   GUID={0x9C3EC8C1,0xE2A1,0x11d1,{0xAE,0xB8,0x00,0x00,0xC0,0x86,0x6B,0x0E}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")

HRESULT STDMETHODCALLTYPE IEnumModules_Next_Proxy( 
    IEnumModules __RPC_FAR * This,
    ULONG celt,
    IModule __RPC_FAR *__RPC_FAR *rgelt,
    ULONG __RPC_FAR *pceltFetched)
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
                      3);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 0U + 4U;
            NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)rgelt,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[756] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( ULONG __RPC_FAR * )_StubMsg.Buffer)++ = celt;
            
            NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)rgelt,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[756] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            *(( ULONG __RPC_FAR * )_StubMsg.Buffer)++ = *pceltFetched;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[146] );
            
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

void __RPC_STUB IEnumModules_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    ULONG celt;
    ULONG __RPC_FAR *pceltFetched;
    IModule __RPC_FAR *__RPC_FAR *rgelt;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    rgelt = 0;
    pceltFetched = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[146] );
        
        celt = *(( ULONG __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR * __RPC_FAR *)&rgelt,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[756],
                              (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        pceltFetched = ( ULONG __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( ULONG  );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IEnumModules *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Next(
        (IEnumModules *) ((CStdStubBuffer *)This)->pvServerObject,
        celt,
        rgelt,
        pceltFetched);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)rgelt,
                        &__MIDL_TypeFormatString.Format[756] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IEnumModules_Skip_Proxy( 
    IEnumModules __RPC_FAR * This,
    ULONG celt)
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
            
            _StubMsg.BufferLength = 4U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( ULONG __RPC_FAR * )_StubMsg.Buffer)++ = celt;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[116] );
            
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

void __RPC_STUB IEnumModules_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    ULONG celt;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[116] );
        
        celt = *(( ULONG __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IEnumModules *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Skip((IEnumModules *) ((CStdStubBuffer *)This)->pvServerObject,celt);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IEnumModules_Reset_Proxy( 
    IEnumModules __RPC_FAR * This)
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
                      5);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[120] );
            
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

void __RPC_STUB IEnumModules_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IEnumModules *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Reset((IEnumModules *) ((CStdStubBuffer *)This)->pvServerObject);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IEnumModules_Clone_Proxy( 
    IEnumModules __RPC_FAR * This,
    IEnumModules __RPC_FAR *__RPC_FAR *ppenum)
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
                      6);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)ppenum,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[778] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)ppenum,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[778] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[158] );
            
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

void __RPC_STUB IEnumModules_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    IEnumModules __RPC_FAR *__RPC_FAR *ppenum;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ppenum = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[158] );
        
        NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR * __RPC_FAR *)&ppenum,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[778],
                              (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IEnumModules *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Clone((IEnumModules *) ((CStdStubBuffer *)This)->pvServerObject,ppenum);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ppenum,
                        &__MIDL_TypeFormatString.Format[778] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

const CINTERFACE_PROXY_VTABLE(7) _IEnumModulesProxyVtbl = 
{
    &IID_IEnumModules,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IEnumModules_Next_Proxy ,
    IEnumModules_Skip_Proxy ,
    IEnumModules_Reset_Proxy ,
    IEnumModules_Clone_Proxy
};


static const PRPC_STUB_FUNCTION IEnumModules_table[] =
{
    IEnumModules_Next_Stub,
    IEnumModules_Skip_Stub,
    IEnumModules_Reset_Stub,
    IEnumModules_Clone_Stub
};

const CInterfaceStubVtbl _IEnumModulesStubVtbl =
{
    &IID_IEnumModules,
    0,
    7,
    &IEnumModules_table[-3],
    CStdStubBuffer_METHODS
};


/* Object interface: IDisSymMgr, ver. 0.0,
   GUID={0x215643D0,0xBBA7,0x11d1,{0xAE,0x8F,0xB8,0xBB,0x59,0x00,0x00,0x00}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")

HRESULT STDMETHODCALLTYPE IDisSymMgr_CreateNew_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [in] */ OLECHAR __RPC_FAR *Path)
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
                      3);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 2U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( OLECHAR __RPC_FAR * )_StubMsg.Buffer)++ = *Path;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[164] );
            
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

void __RPC_STUB IDisSymMgr_CreateNew_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    OLECHAR __RPC_FAR *Path;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    Path = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[164] );
        
        Path = ( OLECHAR __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( OLECHAR  );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> CreateNew((IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject,Path);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IDisSymMgr_OpenExisting_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [in] */ OLECHAR __RPC_FAR *Path)
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
            
            _StubMsg.BufferLength = 2U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( OLECHAR __RPC_FAR * )_StubMsg.Buffer)++ = *Path;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[164] );
            
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

void __RPC_STUB IDisSymMgr_OpenExisting_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    OLECHAR __RPC_FAR *Path;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    Path = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[164] );
        
        Path = ( OLECHAR __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( OLECHAR  );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> OpenExisting((IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject,Path);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IDisSymMgr_Extract_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [in] */ IDisImg __RPC_FAR *Image)
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
                      5);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrInterfacePointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                           (unsigned char __RPC_FAR *)Image,
                                           (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[804] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrInterfacePointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                         (unsigned char __RPC_FAR *)Image,
                                         (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[804] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[170] );
            
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

void __RPC_STUB IDisSymMgr_Extract_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    IDisImg __RPC_FAR *Image;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    Image = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[170] );
        
        NdrInterfacePointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR * __RPC_FAR *)&Image,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[804],
                                       (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Extract((IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject,Image);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrInterfacePointerFree( &_StubMsg,
                                 (unsigned char __RPC_FAR *)Image,
                                 &__MIDL_TypeFormatString.Format[804] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IDisSymMgr_AddType_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [out] */ IType __RPC_FAR *__RPC_FAR *ppType,
    /* [in] */ TYPE_INFO __RPC_FAR *TypeInfo)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    *ppType = 0;
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      6);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrComplexStructBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                        (unsigned char __RPC_FAR *)TypeInfo,
                                        (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[374] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrComplexStructMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                      (unsigned char __RPC_FAR *)TypeInfo,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[374] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[176] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ppType,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[822],
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
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[822],
                         ( void __RPC_FAR * )ppType);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IDisSymMgr_AddType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    TYPE_INFO __RPC_FAR *TypeInfo;
    IType __RPC_FAR *_M7;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    IType __RPC_FAR *__RPC_FAR *ppType;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ppType = 0;
    TypeInfo = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[176] );
        
        NdrComplexStructUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                    (unsigned char __RPC_FAR * __RPC_FAR *)&TypeInfo,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[374],
                                    (unsigned char)0 );
        
        ppType = &_M7;
        _M7 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> AddType(
           (IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject,
           ppType,
           TypeInfo);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 4U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)ppType,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[822] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)ppType,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[822] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ppType,
                        &__MIDL_TypeFormatString.Format[822] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)TypeInfo,
                        &__MIDL_TypeFormatString.Format[398] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IDisSymMgr_GetTypeByName_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [out] */ IType __RPC_FAR *__RPC_FAR *ppType,
    /* [in] */ BSTR Name)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    *ppType = 0;
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      7);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&Name,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[826] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&Name,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[826] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[186] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ppType,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[822],
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
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[822],
                         ( void __RPC_FAR * )ppType);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IDisSymMgr_GetTypeByName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR Name;
    IType __RPC_FAR *_M8;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_Name;
    IType __RPC_FAR *__RPC_FAR *ppType;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ppType = 0;
    _p_Name = &Name;
    MIDL_memset(
               _p_Name,
               0,
               sizeof( BSTR  ));
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[186] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_Name,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[826],
                                  (unsigned char)0 );
        
        ppType = &_M8;
        _M8 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetTypeByName(
                 (IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject,
                 ppType,
                 Name);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 4U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)ppType,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[822] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)ppType,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[822] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ppType,
                        &__MIDL_TypeFormatString.Format[822] );
        
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&Name,
                            &__MIDL_TypeFormatString.Format[826] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IDisSymMgr_GetTypeByHandle_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [out] */ IType __RPC_FAR *__RPC_FAR *pIType,
    /* [in] */ HTYPE Type)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    *pIType = 0;
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      8);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrSimpleStructBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)Type,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[58] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrSimpleStructMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)Type,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[58] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[196] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&pIType,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[822],
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
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[822],
                         ( void __RPC_FAR * )pIType);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IDisSymMgr_GetTypeByHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HTYPE Type;
    IType __RPC_FAR *_M9;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    IType __RPC_FAR *__RPC_FAR *pIType;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    pIType = 0;
    Type = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[196] );
        
        NdrSimpleStructUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                   (unsigned char __RPC_FAR * __RPC_FAR *)&Type,
                                   (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[58],
                                   (unsigned char)0 );
        
        pIType = &_M9;
        _M9 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetTypeByHandle(
                   (IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject,
                   pIType,
                   Type);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 4U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)pIType,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[822] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)pIType,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[822] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)pIType,
                        &__MIDL_TypeFormatString.Format[822] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IDisSymMgr_GetTypeHandle_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [out] */ HTYPE __RPC_FAR *Handle,
    /* [in] */ IType __RPC_FAR *pIType)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    *Handle = 0;
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      9);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrInterfacePointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                           (unsigned char __RPC_FAR *)pIType,
                                           (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[704] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrInterfacePointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                         (unsigned char __RPC_FAR *)pIType,
                                         (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[704] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[206] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Handle,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[836],
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
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[836],
                         ( void __RPC_FAR * )Handle);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IDisSymMgr_GetTypeHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HTYPE __RPC_FAR *Handle;
    HTYPE _M10;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    IType __RPC_FAR *pIType;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    Handle = 0;
    pIType = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[206] );
        
        NdrInterfacePointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR * __RPC_FAR *)&pIType,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[704],
                                       (unsigned char)0 );
        
        Handle = &_M10;
        _M10 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetTypeHandle(
                 (IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject,
                 Handle,
                 pIType);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 11U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)Handle,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[836] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)Handle,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[836] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Handle,
                        &__MIDL_TypeFormatString.Format[836] );
        
        NdrInterfacePointerFree( &_StubMsg,
                                 (unsigned char __RPC_FAR *)pIType,
                                 &__MIDL_TypeFormatString.Format[704] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IDisSymMgr_CloseTypeHandle_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [in] */ HTYPE Handle)
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
                      10);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrSimpleStructBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR *)Handle,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[58] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrSimpleStructMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                     (unsigned char __RPC_FAR *)Handle,
                                     (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[58] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[216] );
            
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

void __RPC_STUB IDisSymMgr_CloseTypeHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HTYPE Handle;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    Handle = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[216] );
        
        NdrSimpleStructUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                   (unsigned char __RPC_FAR * __RPC_FAR *)&Handle,
                                   (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[58],
                                   (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> CloseTypeHandle((IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject,Handle);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IDisSymMgr_EnumTypes_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [out] */ IEnumTypes __RPC_FAR *__RPC_FAR *ppEnum)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    *ppEnum = 0;
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      11);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[222] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ppEnum,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[844],
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
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[844],
                         ( void __RPC_FAR * )ppEnum);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IDisSymMgr_EnumTypes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    IEnumTypes __RPC_FAR *_M11;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    IEnumTypes __RPC_FAR *__RPC_FAR *ppEnum;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ppEnum = 0;
    RpcTryFinally
        {
        ppEnum = &_M11;
        _M11 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> EnumTypes((IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject,ppEnum);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 4U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)ppEnum,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[844] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)ppEnum,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[844] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ppEnum,
                        &__MIDL_TypeFormatString.Format[844] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IDisSymMgr_AddSymbol_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [out] */ ISymbol __RPC_FAR *__RPC_FAR *ppISymbol,
    /* [in] */ SYMBOL_INFO __RPC_FAR *SymbolInfo)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    *ppISymbol = 0;
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      12);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrComplexStructBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                        (unsigned char __RPC_FAR *)SymbolInfo,
                                        (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[566] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrComplexStructMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                      (unsigned char __RPC_FAR *)SymbolInfo,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[566] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[70] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ppISymbol,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[646],
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
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[646],
                         ( void __RPC_FAR * )ppISymbol);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IDisSymMgr_AddSymbol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SYMBOL_INFO __RPC_FAR *SymbolInfo;
    ISymbol __RPC_FAR *_M12;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    ISymbol __RPC_FAR *__RPC_FAR *ppISymbol;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ppISymbol = 0;
    SymbolInfo = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[70] );
        
        NdrComplexStructUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                    (unsigned char __RPC_FAR * __RPC_FAR *)&SymbolInfo,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[566],
                                    (unsigned char)0 );
        
        ppISymbol = &_M12;
        _M12 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> AddSymbol(
             (IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject,
             ppISymbol,
             SymbolInfo);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 4U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)ppISymbol,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[646] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)ppISymbol,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[646] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ppISymbol,
                        &__MIDL_TypeFormatString.Format[646] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)SymbolInfo,
                        &__MIDL_TypeFormatString.Format[590] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IDisSymMgr_GetSymbolByName_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [out] */ ISymbol __RPC_FAR *__RPC_FAR *ppIUnknown,
    /* [in] */ BSTR Name)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    *ppIUnknown = 0;
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      13);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&Name,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[848] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&Name,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[848] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[228] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ppIUnknown,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[646],
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
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[646],
                         ( void __RPC_FAR * )ppIUnknown);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IDisSymMgr_GetSymbolByName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR Name;
    ISymbol __RPC_FAR *_M13;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_Name;
    ISymbol __RPC_FAR *__RPC_FAR *ppIUnknown;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ppIUnknown = 0;
    _p_Name = &Name;
    MIDL_memset(
               _p_Name,
               0,
               sizeof( BSTR  ));
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[228] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_Name,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[848],
                                  (unsigned char)0 );
        
        ppIUnknown = &_M13;
        _M13 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetSymbolByName(
                   (IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject,
                   ppIUnknown,
                   Name);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 4U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)ppIUnknown,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[646] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)ppIUnknown,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[646] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ppIUnknown,
                        &__MIDL_TypeFormatString.Format[646] );
        
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&Name,
                            &__MIDL_TypeFormatString.Format[848] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IDisSymMgr_GetSymbolByAddress_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [out] */ ISymbol __RPC_FAR *__RPC_FAR *ppIUnknown,
    /* [in] */ DWORD Address)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    *ppIUnknown = 0;
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      14);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( DWORD __RPC_FAR * )_StubMsg.Buffer)++ = Address;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[90] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ppIUnknown,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[646],
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
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[646],
                         ( void __RPC_FAR * )ppIUnknown);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IDisSymMgr_GetSymbolByAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    DWORD Address;
    ISymbol __RPC_FAR *_M14;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    ISymbol __RPC_FAR *__RPC_FAR *ppIUnknown;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ppIUnknown = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[90] );
        
        Address = *(( DWORD __RPC_FAR * )_StubMsg.Buffer)++;
        
        ppIUnknown = &_M14;
        _M14 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetSymbolByAddress(
                      (IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject,
                      ppIUnknown,
                      Address);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 4U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)ppIUnknown,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[646] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)ppIUnknown,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[646] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ppIUnknown,
                        &__MIDL_TypeFormatString.Format[646] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IDisSymMgr_EnumSymbols_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [out] */ IEnumSymbols __RPC_FAR *__RPC_FAR *ppEnum)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    *ppEnum = 0;
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      15);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[98] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ppEnum,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[678],
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
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[678],
                         ( void __RPC_FAR * )ppEnum);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IDisSymMgr_EnumSymbols_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    IEnumSymbols __RPC_FAR *_M15;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    IEnumSymbols __RPC_FAR *__RPC_FAR *ppEnum;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ppEnum = 0;
    RpcTryFinally
        {
        ppEnum = &_M15;
        _M15 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> EnumSymbols((IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject,ppEnum);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 4U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)ppEnum,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[678] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)ppEnum,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[678] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ppEnum,
                        &__MIDL_TypeFormatString.Format[678] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IDisSymMgr_AddModule_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [out] */ IModule __RPC_FAR *__RPC_FAR *ppIModule,
    /* [in] */ MODULE_INFO __RPC_FAR *ModuleInfo)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    *ppIModule = 0;
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      16);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrComplexStructBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                        (unsigned char __RPC_FAR *)ModuleInfo,
                                        (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[622] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrComplexStructMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                      (unsigned char __RPC_FAR *)ModuleInfo,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[622] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[238] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ppIModule,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[858],
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
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[858],
                         ( void __RPC_FAR * )ppIModule);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IDisSymMgr_AddModule_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    MODULE_INFO __RPC_FAR *ModuleInfo;
    IModule __RPC_FAR *_M16;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    IModule __RPC_FAR *__RPC_FAR *ppIModule;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ppIModule = 0;
    ModuleInfo = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[238] );
        
        NdrComplexStructUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                    (unsigned char __RPC_FAR * __RPC_FAR *)&ModuleInfo,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[622],
                                    (unsigned char)0 );
        
        ppIModule = &_M16;
        _M16 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> AddModule(
             (IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject,
             ppIModule,
             ModuleInfo);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 4U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)ppIModule,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[858] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)ppIModule,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[858] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ppIModule,
                        &__MIDL_TypeFormatString.Format[858] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ModuleInfo,
                        &__MIDL_TypeFormatString.Format[642] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IDisSymMgr_GetModuleByName_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [out] */ IModule __RPC_FAR *__RPC_FAR *ppIModule,
    /* [in] */ BSTR Name)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    *ppIModule = 0;
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      17);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&Name,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[862] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&Name,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[862] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[248] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ppIModule,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[858],
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
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[858],
                         ( void __RPC_FAR * )ppIModule);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IDisSymMgr_GetModuleByName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR Name;
    IModule __RPC_FAR *_M17;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_Name;
    IModule __RPC_FAR *__RPC_FAR *ppIModule;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ppIModule = 0;
    _p_Name = &Name;
    MIDL_memset(
               _p_Name,
               0,
               sizeof( BSTR  ));
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[248] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_Name,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[862],
                                  (unsigned char)0 );
        
        ppIModule = &_M17;
        _M17 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetModuleByName(
                   (IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject,
                   ppIModule,
                   Name);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 4U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)ppIModule,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[858] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)ppIModule,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[858] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ppIModule,
                        &__MIDL_TypeFormatString.Format[858] );
        
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&Name,
                            &__MIDL_TypeFormatString.Format[862] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IDisSymMgr_GetModuleByAddress_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [out] */ IModule __RPC_FAR *__RPC_FAR *ppIModule,
    /* [in] */ DWORD Address)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    *ppIModule = 0;
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      18);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( DWORD __RPC_FAR * )_StubMsg.Buffer)++ = Address;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[258] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ppIModule,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[858],
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
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[858],
                         ( void __RPC_FAR * )ppIModule);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IDisSymMgr_GetModuleByAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    DWORD Address;
    IModule __RPC_FAR *_M18;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    IModule __RPC_FAR *__RPC_FAR *ppIModule;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ppIModule = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[258] );
        
        Address = *(( DWORD __RPC_FAR * )_StubMsg.Buffer)++;
        
        ppIModule = &_M18;
        _M18 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetModuleByAddress(
                      (IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject,
                      ppIModule,
                      Address);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 4U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)ppIModule,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[858] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)ppIModule,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[858] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ppIModule,
                        &__MIDL_TypeFormatString.Format[858] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IDisSymMgr_EnumModules_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [out] */ IEnumModules __RPC_FAR *__RPC_FAR *ppEnum)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    *ppEnum = 0;
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      19);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[266] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ppEnum,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[872],
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
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[872],
                         ( void __RPC_FAR * )ppEnum);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IDisSymMgr_EnumModules_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    IEnumModules __RPC_FAR *_M19;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    IEnumModules __RPC_FAR *__RPC_FAR *ppEnum;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ppEnum = 0;
    RpcTryFinally
        {
        ppEnum = &_M19;
        _M19 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> EnumModules((IDisSymMgr *) ((CStdStubBuffer *)This)->pvServerObject,ppEnum);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 4U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)ppEnum,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[872] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)ppEnum,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[872] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ppEnum,
                        &__MIDL_TypeFormatString.Format[872] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

const CINTERFACE_PROXY_VTABLE(20) _IDisSymMgrProxyVtbl = 
{
    &IID_IDisSymMgr,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IDisSymMgr_CreateNew_Proxy ,
    IDisSymMgr_OpenExisting_Proxy ,
    IDisSymMgr_Extract_Proxy ,
    IDisSymMgr_AddType_Proxy ,
    IDisSymMgr_GetTypeByName_Proxy ,
    IDisSymMgr_GetTypeByHandle_Proxy ,
    IDisSymMgr_GetTypeHandle_Proxy ,
    IDisSymMgr_CloseTypeHandle_Proxy ,
    IDisSymMgr_EnumTypes_Proxy ,
    IDisSymMgr_AddSymbol_Proxy ,
    IDisSymMgr_GetSymbolByName_Proxy ,
    IDisSymMgr_GetSymbolByAddress_Proxy ,
    IDisSymMgr_EnumSymbols_Proxy ,
    IDisSymMgr_AddModule_Proxy ,
    IDisSymMgr_GetModuleByName_Proxy ,
    IDisSymMgr_GetModuleByAddress_Proxy ,
    IDisSymMgr_EnumModules_Proxy
};


static const PRPC_STUB_FUNCTION IDisSymMgr_table[] =
{
    IDisSymMgr_CreateNew_Stub,
    IDisSymMgr_OpenExisting_Stub,
    IDisSymMgr_Extract_Stub,
    IDisSymMgr_AddType_Stub,
    IDisSymMgr_GetTypeByName_Stub,
    IDisSymMgr_GetTypeByHandle_Stub,
    IDisSymMgr_GetTypeHandle_Stub,
    IDisSymMgr_CloseTypeHandle_Stub,
    IDisSymMgr_EnumTypes_Stub,
    IDisSymMgr_AddSymbol_Stub,
    IDisSymMgr_GetSymbolByName_Stub,
    IDisSymMgr_GetSymbolByAddress_Stub,
    IDisSymMgr_EnumSymbols_Stub,
    IDisSymMgr_AddModule_Stub,
    IDisSymMgr_GetModuleByName_Stub,
    IDisSymMgr_GetModuleByAddress_Stub,
    IDisSymMgr_EnumModules_Stub
};

const CInterfaceStubVtbl _IDisSymMgrStubVtbl =
{
    &IID_IDisSymMgr,
    0,
    20,
    &IDisSymMgr_table[-3],
    CStdStubBuffer_METHODS
};


/* Object interface: IDisSmX, ver. 0.0,
   GUID={0x0F715AB0,0xBBA9,0x11d1,{0xAE,0x8F,0xB8,0xBB,0x59,0x00,0x00,0x00}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")

HRESULT STDMETHODCALLTYPE IDisSmX_Extract_Proxy( 
    IDisSmX __RPC_FAR * This,
    IDisImg __RPC_FAR *Image,
    IDisSymMgr __RPC_FAR *SymbolManager)
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
                      3);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U + 0U;
            NdrInterfacePointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                           (unsigned char __RPC_FAR *)Image,
                                           (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[804] );
            
            NdrInterfacePointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                           (unsigned char __RPC_FAR *)SymbolManager,
                                           (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[876] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrInterfacePointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                         (unsigned char __RPC_FAR *)Image,
                                         (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[804] );
            
            NdrInterfacePointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                         (unsigned char __RPC_FAR *)SymbolManager,
                                         (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[876] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[272] );
            
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

void __RPC_STUB IDisSmX_Extract_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    IDisImg __RPC_FAR *Image;
    IDisSymMgr __RPC_FAR *SymbolManager;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    Image = 0;
    SymbolManager = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[272] );
        
        NdrInterfacePointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR * __RPC_FAR *)&Image,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[804],
                                       (unsigned char)0 );
        
        NdrInterfacePointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR * __RPC_FAR *)&SymbolManager,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[876],
                                       (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IDisSmX *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Extract(
           (IDisSmX *) ((CStdStubBuffer *)This)->pvServerObject,
           Image,
           SymbolManager);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrInterfacePointerFree( &_StubMsg,
                                 (unsigned char __RPC_FAR *)Image,
                                 &__MIDL_TypeFormatString.Format[804] );
        
        NdrInterfacePointerFree( &_StubMsg,
                                 (unsigned char __RPC_FAR *)SymbolManager,
                                 &__MIDL_TypeFormatString.Format[876] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

const CINTERFACE_PROXY_VTABLE(4) _IDisSmXProxyVtbl = 
{
    &IID_IDisSmX,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IDisSmX_Extract_Proxy
};


static const PRPC_STUB_FUNCTION IDisSmX_table[] =
{
    IDisSmX_Extract_Stub
};

const CInterfaceStubVtbl _IDisSmXStubVtbl =
{
    &IID_IDisSmX,
    0,
    4,
    &IDisSmX_table[-3],
    CStdStubBuffer_METHODS
};


/* Standard interface: __MIDL__intf_0155, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IDisFunction, ver. 0.0,
   GUID={0x28C36830,0xBBC0,0x11d1,{0xAE,0x8F,0xB8,0xBB,0x59,0x00,0x00,0x00}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")

HRESULT STDMETHODCALLTYPE IDisFunction_GetBasicInfo_Proxy( 
    IDisFunction __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbsName,
    /* [out] */ DWORD __RPC_FAR *pdwAddr,
    /* [out] */ DWORD __RPC_FAR *pdwLen)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    MIDL_memset(
               pbsName,
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
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[282] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pbsName,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[898],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            *pdwAddr = *(( DWORD __RPC_FAR * )_StubMsg.Buffer)++;
            
            *pdwLen = *(( DWORD __RPC_FAR * )_StubMsg.Buffer)++;
            
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
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[894],
                         ( void __RPC_FAR * )pbsName);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[908],
                         ( void __RPC_FAR * )pdwAddr);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[908],
                         ( void __RPC_FAR * )pdwLen);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IDisFunction_GetBasicInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR _M20;
    DWORD _M21;
    DWORD _M22;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    BSTR __RPC_FAR *pbsName;
    DWORD __RPC_FAR *pdwAddr;
    DWORD __RPC_FAR *pdwLen;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    pbsName = 0;
    pdwAddr = 0;
    pdwLen = 0;
    RpcTryFinally
        {
        pbsName = &_M20;
        MIDL_memset(
               pbsName,
               0,
               sizeof( BSTR  ));
        pdwAddr = &_M21;
        pdwLen = &_M22;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IDisFunction *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetBasicInfo(
                (IDisFunction *) ((CStdStubBuffer *)This)->pvServerObject,
                pbsName,
                pdwAddr,
                pdwLen);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 11U + 7U + 7U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)pbsName,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[898] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)pbsName,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[898] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( DWORD __RPC_FAR * )_StubMsg.Buffer)++ = *pdwAddr;
        
        *(( DWORD __RPC_FAR * )_StubMsg.Buffer)++ = *pdwLen;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)pbsName,
                        &__MIDL_TypeFormatString.Format[894] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IDisFunction_GetFUNCDESC_Proxy( 
    IDisFunction __RPC_FAR * This,
    /* [out] */ FUNCDESC __RPC_FAR *pFd,
    /* [out] */ FUNCDESC_FIELDS __RPC_FAR *pValidFields)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    MIDL_memset(
               pFd,
               0,
               sizeof( FUNCDESC  ));
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
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[296] );
            
            NdrComplexStructUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                        (unsigned char __RPC_FAR * __RPC_FAR *)&pFd,
                                        (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1872],
                                        (unsigned char)0 );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&pValidFields,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1906],
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
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[912],
                         ( void __RPC_FAR * )pFd);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1906],
                         ( void __RPC_FAR * )pValidFields);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IDisFunction_GetFUNCDESC_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    FUNCDESC_FIELDS _M23;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    FUNCDESC _pFdM;
    FUNCDESC __RPC_FAR *pFd;
    FUNCDESC_FIELDS __RPC_FAR *pValidFields;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    pFd = 0;
    pValidFields = 0;
    RpcTryFinally
        {
        pFd = &_pFdM;
        pFd -> lprgscode = 0;
        pFd -> lprgelemdescParam = 0;
        pValidFields = &_M23;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IDisFunction *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetFUNCDESC(
               (IDisFunction *) ((CStdStubBuffer *)This)->pvServerObject,
               pFd,
               pValidFields);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 5U + 10U;
        NdrComplexStructBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                    (unsigned char __RPC_FAR *)pFd,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1872] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrComplexStructMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                  (unsigned char __RPC_FAR *)pFd,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1872] );
        
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)pValidFields,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1906] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)pFd,
                        &__MIDL_TypeFormatString.Format[912] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IDisFunction_ReleaseFUNCDESC_Proxy( 
    IDisFunction __RPC_FAR * This,
    /* [in] */ FUNCDESC __RPC_FAR *pFd)
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
                      5);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrComplexStructBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                        (unsigned char __RPC_FAR *)pFd,
                                        (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1872] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrComplexStructMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                      (unsigned char __RPC_FAR *)pFd,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1872] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[306] );
            
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

void __RPC_STUB IDisFunction_ReleaseFUNCDESC_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    FUNCDESC __RPC_FAR *pFd;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    pFd = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[306] );
        
        NdrComplexStructUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                    (unsigned char __RPC_FAR * __RPC_FAR *)&pFd,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1872],
                                    (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IDisFunction *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> ReleaseFUNCDESC((IDisFunction *) ((CStdStubBuffer *)This)->pvServerObject,pFd);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)pFd,
                        &__MIDL_TypeFormatString.Format[1910] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IDisFunction_GetConfidence_Proxy( 
    IDisFunction __RPC_FAR * This,
    /* [in] */ FUNCDESC_FIELDS SingleField,
    /* [out] */ CONFIDENCE __RPC_FAR *pConfidence)
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
                      6);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 2U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrSimpleTypeMarshall(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( unsigned char __RPC_FAR * )&SingleField,
                         13);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[312] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&pConfidence,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1906],
                                  (unsigned char)0 );
            
            _StubMsg.Buffer += 2;
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
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1906],
                         ( void __RPC_FAR * )pConfidence);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IDisFunction_GetConfidence_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    FUNCDESC_FIELDS SingleField;
    CONFIDENCE _M24;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    CONFIDENCE __RPC_FAR *pConfidence;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    pConfidence = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[312] );
        
        NdrSimpleTypeUnmarshall(
                           ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                           ( unsigned char __RPC_FAR * )&SingleField,
                           13);
        pConfidence = &_M24;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IDisFunction *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetConfidence(
                 (IDisFunction *) ((CStdStubBuffer *)This)->pvServerObject,
                 SingleField,
                 pConfidence);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 2U + 6U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)pConfidence,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1906] );
        
        _StubMsg.Buffer += 2;
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


HRESULT STDMETHODCALLTYPE IDisFunction_SetConfidence_Proxy( 
    IDisFunction __RPC_FAR * This,
    /* [in] */ FUNCDESC_FIELDS FieldList,
    /* [in] */ CONFIDENCE NewConfidence)
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
                      7);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 2U + 2U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrSimpleTypeMarshall(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( unsigned char __RPC_FAR * )&FieldList,
                         13);
            NdrSimpleTypeMarshall(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( unsigned char __RPC_FAR * )&NewConfidence,
                         13);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[320] );
            
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

void __RPC_STUB IDisFunction_SetConfidence_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    FUNCDESC_FIELDS FieldList;
    CONFIDENCE NewConfidence;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[320] );
        
        NdrSimpleTypeUnmarshall(
                           ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                           ( unsigned char __RPC_FAR * )&FieldList,
                           13);
        NdrSimpleTypeUnmarshall(
                           ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                           ( unsigned char __RPC_FAR * )&NewConfidence,
                           13);
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IDisFunction *) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetConfidence(
                 (IDisFunction *) ((CStdStubBuffer *)This)->pvServerObject,
                 FieldList,
                 NewConfidence);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[2];

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

const CINTERFACE_PROXY_VTABLE(8) _IDisFunctionProxyVtbl = 
{
    &IID_IDisFunction,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IDisFunction_GetBasicInfo_Proxy ,
    IDisFunction_GetFUNCDESC_Proxy ,
    IDisFunction_ReleaseFUNCDESC_Proxy ,
    IDisFunction_GetConfidence_Proxy ,
    IDisFunction_SetConfidence_Proxy
};


static const PRPC_STUB_FUNCTION IDisFunction_table[] =
{
    IDisFunction_GetBasicInfo_Stub,
    IDisFunction_GetFUNCDESC_Stub,
    IDisFunction_ReleaseFUNCDESC_Stub,
    IDisFunction_GetConfidence_Stub,
    IDisFunction_SetConfidence_Stub
};

const CInterfaceStubVtbl _IDisFunctionStubVtbl =
{
    &IID_IDisFunction,
    0,
    8,
    &IDisFunction_table[-3],
    CStdStubBuffer_METHODS
};

#pragma data_seg(".rdata")

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[2] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            },
            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
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
/*  2 */	NdrFcShort( 0x18 ),	/* Type Offset=24 */
/*  4 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/*  6 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/*  8 */	NdrFcShort( 0x22 ),	/* Type Offset=34 */
/* 10 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 12 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 14 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 16 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */
/* 18 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 20 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 22 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 24 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */
/* 26 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 28 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 30 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 32 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 34 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 36 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */
/* 38 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 40 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 42 */	NdrFcShort( 0x18e ),	/* Type Offset=398 */
/* 44 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 46 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 48 */	NdrFcShort( 0x192 ),	/* Type Offset=402 */
/* 50 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 52 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 54 */	NdrFcShort( 0x24e ),	/* Type Offset=590 */
/* 56 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 58 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 60 */	NdrFcShort( 0x252 ),	/* Type Offset=594 */
/* 62 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 64 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 66 */	NdrFcShort( 0x282 ),	/* Type Offset=642 */
/* 68 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 70 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 72 */	NdrFcShort( 0x286 ),	/* Type Offset=646 */
/* 74 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 76 */	NdrFcShort( 0x24e ),	/* Type Offset=590 */
/* 78 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 80 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 82 */	NdrFcShort( 0x286 ),	/* Type Offset=646 */
/* 84 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 86 */	NdrFcShort( 0x29c ),	/* Type Offset=668 */
/* 88 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 90 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 92 */	NdrFcShort( 0x286 ),	/* Type Offset=646 */
/* 94 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 96 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 98 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 100 */	NdrFcShort( 0x2a6 ),	/* Type Offset=678 */
/* 102 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 104 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 106 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 108 */	NdrFcShort( 0x2bc ),	/* Type Offset=700 */
/* 110 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 112 */	NdrFcShort( 0x2d2 ),	/* Type Offset=722 */
/* 114 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 116 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 118 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 120 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 122 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 124 */	NdrFcShort( 0x2d6 ),	/* Type Offset=726 */
/* 126 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 128 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 130 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 132 */	NdrFcShort( 0x2ec ),	/* Type Offset=748 */
/* 134 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 136 */	NdrFcShort( 0x2d2 ),	/* Type Offset=722 */
/* 138 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 140 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 142 */	NdrFcShort( 0x2f0 ),	/* Type Offset=752 */
/* 144 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 146 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 148 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 150 */	NdrFcShort( 0x2f4 ),	/* Type Offset=756 */
/* 152 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 154 */	NdrFcShort( 0x2d2 ),	/* Type Offset=722 */
/* 156 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 158 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 160 */	NdrFcShort( 0x30a ),	/* Type Offset=778 */
/* 162 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 164 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 166 */	NdrFcShort( 0x320 ),	/* Type Offset=800 */
/* 168 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 170 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 172 */	NdrFcShort( 0x324 ),	/* Type Offset=804 */
/* 174 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 176 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 178 */	NdrFcShort( 0x336 ),	/* Type Offset=822 */
/* 180 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 182 */	NdrFcShort( 0x18e ),	/* Type Offset=398 */
/* 184 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 186 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 188 */	NdrFcShort( 0x336 ),	/* Type Offset=822 */
/* 190 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 192 */	NdrFcShort( 0x33a ),	/* Type Offset=826 */
/* 194 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 196 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 198 */	NdrFcShort( 0x336 ),	/* Type Offset=822 */
/* 200 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 202 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */
/* 204 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 206 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 208 */	NdrFcShort( 0x344 ),	/* Type Offset=836 */
/* 210 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 212 */	NdrFcShort( 0x2c0 ),	/* Type Offset=704 */
/* 214 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 216 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 218 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */
/* 220 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 222 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 224 */	NdrFcShort( 0x34c ),	/* Type Offset=844 */
/* 226 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 228 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 230 */	NdrFcShort( 0x286 ),	/* Type Offset=646 */
/* 232 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 234 */	NdrFcShort( 0x350 ),	/* Type Offset=848 */
/* 236 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 238 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 240 */	NdrFcShort( 0x35a ),	/* Type Offset=858 */
/* 242 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 244 */	NdrFcShort( 0x282 ),	/* Type Offset=642 */
/* 246 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 248 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 250 */	NdrFcShort( 0x35a ),	/* Type Offset=858 */
/* 252 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 254 */	NdrFcShort( 0x35e ),	/* Type Offset=862 */
/* 256 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 258 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 260 */	NdrFcShort( 0x35a ),	/* Type Offset=858 */
/* 262 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 264 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 266 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 268 */	NdrFcShort( 0x368 ),	/* Type Offset=872 */
/* 270 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 272 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 274 */	NdrFcShort( 0x324 ),	/* Type Offset=804 */
/* 276 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 278 */	NdrFcShort( 0x36c ),	/* Type Offset=876 */
/* 280 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 282 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 284 */	NdrFcShort( 0x37e ),	/* Type Offset=894 */
/* 286 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 288 */	NdrFcShort( 0x38c ),	/* Type Offset=908 */
/* 290 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 292 */	NdrFcShort( 0x38c ),	/* Type Offset=908 */
/* 294 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 296 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 298 */	NdrFcShort( 0x390 ),	/* Type Offset=912 */
/* 300 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 302 */	NdrFcShort( 0x772 ),	/* Type Offset=1906 */
/* 304 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 306 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 308 */	NdrFcShort( 0x776 ),	/* Type Offset=1910 */
/* 310 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 312 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0xd,		/* FC_ENUM16 */
/* 314 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 316 */	NdrFcShort( 0x772 ),	/* Type Offset=1906 */
/* 318 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 320 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0xd,		/* FC_ENUM16 */
/* 322 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0xd,		/* FC_ENUM16 */
/* 324 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			0x12, 0x0,	/* FC_UP */
/*  2 */	NdrFcShort( 0xc ),	/* Offset= 12 (14) */
/*  4 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/*  6 */	NdrFcShort( 0x2 ),	/* 2 */
/*  8 */	0x9,		/* 9 */
			0x0,		/*  */
/* 10 */	NdrFcShort( 0xfffffffc ),	/* -4 */
/* 12 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 14 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 16 */	NdrFcShort( 0x8 ),	/* 8 */
/* 18 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (4) */
/* 20 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 22 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 24 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 26 */	NdrFcShort( 0x0 ),	/* 0 */
/* 28 */	NdrFcShort( 0x4 ),	/* 4 */
/* 30 */	NdrFcShort( 0x0 ),	/* 0 */
/* 32 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (0) */
/* 34 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 36 */	NdrFcShort( 0x0 ),	/* 0 */
/* 38 */	NdrFcShort( 0x4 ),	/* 4 */
/* 40 */	NdrFcShort( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0xffffffd6 ),	/* Offset= -42 (0) */
/* 44 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 46 */	NdrFcShort( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x4 ),	/* 4 */
/* 50 */	NdrFcShort( 0x0 ),	/* 0 */
/* 52 */	NdrFcShort( 0xffffffcc ),	/* Offset= -52 (0) */
/* 54 */	
			0x11, 0x0,	/* FC_RP */
/* 56 */	NdrFcShort( 0x2 ),	/* Offset= 2 (58) */
/* 58 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 60 */	NdrFcShort( 0x4 ),	/* 4 */
/* 62 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 64 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] */
/* 66 */	NdrFcShort( 0x2 ),	/* Offset= 2 (68) */
/* 68 */	
			0x13, 0x0,	/* FC_OP */
/* 70 */	NdrFcShort( 0x130 ),	/* Offset= 304 (374) */
/* 72 */	
			0x13, 0x0,	/* FC_OP */
/* 74 */	NdrFcShort( 0xffffffc4 ),	/* Offset= -60 (14) */
/* 76 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 78 */	NdrFcShort( 0x0 ),	/* 0 */
/* 80 */	NdrFcShort( 0x4 ),	/* 4 */
/* 82 */	NdrFcShort( 0x0 ),	/* 0 */
/* 84 */	NdrFcShort( 0xfffffff4 ),	/* Offset= -12 (72) */
/* 86 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 88 */	NdrFcShort( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0x4 ),	/* 4 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0xffffffea ),	/* Offset= -22 (72) */
/* 96 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x8,		/* FC_LONG */
/* 98 */	0x8,		/* 8 */
			0x0,		/*  */
/* 100 */	NdrFcShort( 0xfffffffc ),	/* -4 */
/* 102 */	NdrFcShort( 0x2 ),	/* Offset= 2 (104) */
/* 104 */	NdrFcShort( 0xc ),	/* 12 */
/* 106 */	NdrFcShort( 0x4 ),	/* 4 */
/* 108 */	NdrFcLong( 0x7 ),	/* 7 */
/* 112 */	NdrFcShort( 0x50 ),	/* Offset= 80 (192) */
/* 114 */	NdrFcLong( 0x1 ),	/* 1 */
/* 118 */	NdrFcShort( 0x86 ),	/* Offset= 134 (252) */
/* 120 */	NdrFcLong( 0x0 ),	/* 0 */
/* 124 */	NdrFcShort( 0xc6 ),	/* Offset= 198 (322) */
/* 126 */	NdrFcLong( 0x6 ),	/* 6 */
/* 130 */	NdrFcShort( 0xe0 ),	/* Offset= 224 (354) */
/* 132 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (131) */
/* 134 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 136 */	NdrFcShort( 0x4 ),	/* 4 */
/* 138 */	0x18,		/* 24 */
			0x0,		/*  */
/* 140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 142 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 144 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 146 */	NdrFcShort( 0x4 ),	/* 4 */
/* 148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 150 */	NdrFcShort( 0x1 ),	/* 1 */
/* 152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 156 */	0x13, 0x0,	/* FC_OP */
/* 158 */	NdrFcShort( 0xffffff9c ),	/* Offset= -100 (58) */
/* 160 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 162 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 164 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 168 */	NdrFcShort( 0x4 ),	/* 4 */
/* 170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 172 */	NdrFcShort( 0xffffff9c ),	/* Offset= -100 (72) */
/* 174 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 178 */	0x18,		/* 24 */
			0x0,		/*  */
/* 180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 182 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 186 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 188 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (164) */
/* 190 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 192 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 194 */	NdrFcShort( 0xc ),	/* 12 */
/* 196 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 198 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 200 */	NdrFcShort( 0x4 ),	/* 4 */
/* 202 */	NdrFcShort( 0x4 ),	/* 4 */
/* 204 */	0x13, 0x0,	/* FC_OP */
/* 206 */	NdrFcShort( 0xffffffb8 ),	/* Offset= -72 (134) */
/* 208 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 210 */	NdrFcShort( 0x8 ),	/* 8 */
/* 212 */	NdrFcShort( 0x8 ),	/* 8 */
/* 214 */	0x13, 0x0,	/* FC_OP */
/* 216 */	NdrFcShort( 0xffffffd6 ),	/* Offset= -42 (174) */
/* 218 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 220 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 222 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 224 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 228 */	NdrFcShort( 0x4 ),	/* 4 */
/* 230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 232 */	NdrFcShort( 0xffffff60 ),	/* Offset= -160 (72) */
/* 234 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 238 */	0x18,		/* 24 */
			0x0,		/*  */
/* 240 */	NdrFcShort( 0x0 ),	/* 0 */
/* 242 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 246 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 248 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (224) */
/* 250 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 252 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 254 */	NdrFcShort( 0xc ),	/* 12 */
/* 256 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 258 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 260 */	NdrFcShort( 0x4 ),	/* 4 */
/* 262 */	NdrFcShort( 0x4 ),	/* 4 */
/* 264 */	0x13, 0x0,	/* FC_OP */
/* 266 */	NdrFcShort( 0xffffff7c ),	/* Offset= -132 (134) */
/* 268 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 270 */	NdrFcShort( 0x8 ),	/* 8 */
/* 272 */	NdrFcShort( 0x8 ),	/* 8 */
/* 274 */	0x13, 0x0,	/* FC_OP */
/* 276 */	NdrFcShort( 0xffffffd6 ),	/* Offset= -42 (234) */
/* 278 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 280 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 282 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 284 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 286 */	NdrFcShort( 0x4 ),	/* 4 */
/* 288 */	0x18,		/* 24 */
			0x0,		/*  */
/* 290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 292 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 294 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 298 */	NdrFcShort( 0x4 ),	/* 4 */
/* 300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 302 */	NdrFcShort( 0xffffff1a ),	/* Offset= -230 (72) */
/* 304 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 308 */	0x18,		/* 24 */
			0x0,		/*  */
/* 310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 312 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 316 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 318 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (294) */
/* 320 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 322 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 324 */	NdrFcShort( 0xc ),	/* 12 */
/* 326 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 328 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 330 */	NdrFcShort( 0x4 ),	/* 4 */
/* 332 */	NdrFcShort( 0x4 ),	/* 4 */
/* 334 */	0x13, 0x0,	/* FC_OP */
/* 336 */	NdrFcShort( 0xffffffcc ),	/* Offset= -52 (284) */
/* 338 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 340 */	NdrFcShort( 0x8 ),	/* 8 */
/* 342 */	NdrFcShort( 0x8 ),	/* 8 */
/* 344 */	0x13, 0x0,	/* FC_OP */
/* 346 */	NdrFcShort( 0xffffffd6 ),	/* Offset= -42 (304) */
/* 348 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 350 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 352 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 354 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 356 */	NdrFcShort( 0x4 ),	/* 4 */
/* 358 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 360 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 366 */	0x13, 0x0,	/* FC_OP */
/* 368 */	NdrFcShort( 0xfffffeca ),	/* Offset= -310 (58) */
/* 370 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 372 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 374 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 376 */	NdrFcShort( 0x1c ),	/* 28 */
/* 378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 380 */	NdrFcShort( 0x0 ),	/* Offset= 0 (380) */
/* 382 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 384 */	NdrFcShort( 0xfffffecc ),	/* Offset= -308 (76) */
/* 386 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 388 */	NdrFcShort( 0xfffffed2 ),	/* Offset= -302 (86) */
/* 390 */	0x8,		/* FC_LONG */
			0xe,		/* FC_ENUM32 */
/* 392 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 394 */	NdrFcShort( 0xfffffed6 ),	/* Offset= -298 (96) */
/* 396 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 398 */	
			0x11, 0x0,	/* FC_RP */
/* 400 */	NdrFcShort( 0xffffffe6 ),	/* Offset= -26 (374) */
/* 402 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] */
/* 404 */	NdrFcShort( 0x2 ),	/* Offset= 2 (406) */
/* 406 */	
			0x13, 0x0,	/* FC_OP */
/* 408 */	NdrFcShort( 0x9e ),	/* Offset= 158 (566) */
/* 410 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 414 */	NdrFcShort( 0x4 ),	/* 4 */
/* 416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 418 */	NdrFcShort( 0xfffffea6 ),	/* Offset= -346 (72) */
/* 420 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 424 */	NdrFcShort( 0x4 ),	/* 4 */
/* 426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 428 */	NdrFcShort( 0xfffffe9c ),	/* Offset= -356 (72) */
/* 430 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0xd,		/* FC_ENUM16 */
/* 432 */	0x6,		/* 6 */
			0x0,		/*  */
/* 434 */	NdrFcShort( 0xfffffffc ),	/* -4 */
/* 436 */	NdrFcShort( 0x2 ),	/* Offset= 2 (438) */
/* 438 */	NdrFcShort( 0x1c ),	/* 28 */
/* 440 */	NdrFcShort( 0x3 ),	/* 3 */
/* 442 */	NdrFcLong( 0x0 ),	/* 0 */
/* 446 */	NdrFcShort( 0x4a ),	/* Offset= 74 (520) */
/* 448 */	NdrFcLong( 0x1 ),	/* 1 */
/* 452 */	NdrFcShort( 0xffffff9e ),	/* Offset= -98 (354) */
/* 454 */	NdrFcLong( 0x2 ),	/* 2 */
/* 458 */	NdrFcShort( 0xfffffe70 ),	/* Offset= -400 (58) */
/* 460 */	NdrFcShort( 0x0 ),	/* Offset= 0 (460) */
/* 462 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 464 */	NdrFcShort( 0x4 ),	/* 4 */
/* 466 */	0x18,		/* 24 */
			0x0,		/*  */
/* 468 */	NdrFcShort( 0x10 ),	/* 16 */
/* 470 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 472 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 474 */	NdrFcShort( 0x4 ),	/* 4 */
/* 476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 478 */	NdrFcShort( 0x1 ),	/* 1 */
/* 480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 482 */	NdrFcShort( 0x0 ),	/* 0 */
/* 484 */	0x13, 0x0,	/* FC_OP */
/* 486 */	NdrFcShort( 0xfffffe54 ),	/* Offset= -428 (58) */
/* 488 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 490 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 492 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 496 */	NdrFcShort( 0x4 ),	/* 4 */
/* 498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 500 */	NdrFcShort( 0xfffffe54 ),	/* Offset= -428 (72) */
/* 502 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 506 */	0x18,		/* 24 */
			0x0,		/*  */
/* 508 */	NdrFcShort( 0x10 ),	/* 16 */
/* 510 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 514 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 516 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (492) */
/* 518 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 520 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 522 */	NdrFcShort( 0x1c ),	/* 28 */
/* 524 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 526 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 528 */	NdrFcShort( 0xc ),	/* 12 */
/* 530 */	NdrFcShort( 0xc ),	/* 12 */
/* 532 */	0x13, 0x0,	/* FC_OP */
/* 534 */	NdrFcShort( 0xfffffe24 ),	/* Offset= -476 (58) */
/* 536 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 538 */	NdrFcShort( 0x14 ),	/* 20 */
/* 540 */	NdrFcShort( 0x14 ),	/* 20 */
/* 542 */	0x13, 0x0,	/* FC_OP */
/* 544 */	NdrFcShort( 0xffffffae ),	/* Offset= -82 (462) */
/* 546 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 548 */	NdrFcShort( 0x18 ),	/* 24 */
/* 550 */	NdrFcShort( 0x18 ),	/* 24 */
/* 552 */	0x13, 0x0,	/* FC_OP */
/* 554 */	NdrFcShort( 0xffffffcc ),	/* Offset= -52 (502) */
/* 556 */	
			0x5b,		/* FC_END */

			0xe,		/* FC_ENUM32 */
/* 558 */	0xe,		/* FC_ENUM32 */
			0xe,		/* FC_ENUM32 */
/* 560 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 562 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 564 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 566 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 568 */	NdrFcShort( 0x30 ),	/* 48 */
/* 570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 572 */	NdrFcShort( 0x0 ),	/* Offset= 0 (572) */
/* 574 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 576 */	NdrFcShort( 0xffffff5a ),	/* Offset= -166 (410) */
/* 578 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 580 */	NdrFcShort( 0xffffff60 ),	/* Offset= -160 (420) */
/* 582 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 584 */	0xd,		/* FC_ENUM16 */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 586 */	0x0,		/* 0 */
			NdrFcShort( 0xffffff63 ),	/* Offset= -157 (430) */
			0x5b,		/* FC_END */
/* 590 */	
			0x11, 0x0,	/* FC_RP */
/* 592 */	NdrFcShort( 0xffffffe6 ),	/* Offset= -26 (566) */
/* 594 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] */
/* 596 */	NdrFcShort( 0x2 ),	/* Offset= 2 (598) */
/* 598 */	
			0x13, 0x0,	/* FC_OP */
/* 600 */	NdrFcShort( 0x16 ),	/* Offset= 22 (622) */
/* 602 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 606 */	NdrFcShort( 0x4 ),	/* 4 */
/* 608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 610 */	NdrFcShort( 0xfffffde6 ),	/* Offset= -538 (72) */
/* 612 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 616 */	NdrFcShort( 0x4 ),	/* 4 */
/* 618 */	NdrFcShort( 0x0 ),	/* 0 */
/* 620 */	NdrFcShort( 0xfffffddc ),	/* Offset= -548 (72) */
/* 622 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 624 */	NdrFcShort( 0x10 ),	/* 16 */
/* 626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 628 */	NdrFcShort( 0x0 ),	/* Offset= 0 (628) */
/* 630 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 632 */	NdrFcShort( 0xffffffe2 ),	/* Offset= -30 (602) */
/* 634 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 636 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (612) */
/* 638 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 640 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 642 */	
			0x11, 0x0,	/* FC_RP */
/* 644 */	NdrFcShort( 0xffffffea ),	/* Offset= -22 (622) */
/* 646 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] */
/* 648 */	NdrFcShort( 0x2 ),	/* Offset= 2 (650) */
/* 650 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 652 */	NdrFcLong( 0xd8fcd7c0 ),	/* -654518336 */
/* 656 */	NdrFcShort( 0xffffe088 ),	/* -8056 */
/* 658 */	NdrFcShort( 0x11d1 ),	/* 4561 */
/* 660 */	0xae,		/* 174 */
			0xb5,		/* 181 */
/* 662 */	0xbe,		/* 190 */
			0xbb,		/* 187 */
/* 664 */	0x53,		/* 83 */
			0x0,		/* 0 */
/* 666 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 668 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 672 */	NdrFcShort( 0x4 ),	/* 4 */
/* 674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 676 */	NdrFcShort( 0xfffffd5c ),	/* Offset= -676 (0) */
/* 678 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] */
/* 680 */	NdrFcShort( 0x2 ),	/* Offset= 2 (682) */
/* 682 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 684 */	NdrFcLong( 0xad8750f0 ),	/* -1383640848 */
/* 688 */	NdrFcShort( 0xffffbbac ),	/* -17492 */
/* 690 */	NdrFcShort( 0x11d1 ),	/* 4561 */
/* 692 */	0xae,		/* 174 */
			0x8f,		/* 143 */
/* 694 */	0xb8,		/* 184 */
			0xbb,		/* 187 */
/* 696 */	0x59,		/* 89 */
			0x0,		/* 0 */
/* 698 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 700 */	
			0x11, 0x10,	/* FC_RP */
/* 702 */	NdrFcShort( 0x2 ),	/* Offset= 2 (704) */
/* 704 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 706 */	NdrFcLong( 0xafaeafc0 ),	/* -1347506240 */
/* 710 */	NdrFcShort( 0xffffe089 ),	/* -8055 */
/* 712 */	NdrFcShort( 0x11d1 ),	/* 4561 */
/* 714 */	0xae,		/* 174 */
			0xb5,		/* 181 */
/* 716 */	0xbe,		/* 190 */
			0xbb,		/* 187 */
/* 718 */	0x53,		/* 83 */
			0x0,		/* 0 */
/* 720 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 722 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 724 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 726 */	
			0x11, 0x10,	/* FC_RP */
/* 728 */	NdrFcShort( 0x2 ),	/* Offset= 2 (730) */
/* 730 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 732 */	NdrFcLong( 0x9c3ec8c0 ),	/* -1673606976 */
/* 736 */	NdrFcShort( 0xffffe2a1 ),	/* -7519 */
/* 738 */	NdrFcShort( 0x11d1 ),	/* 4561 */
/* 740 */	0xae,		/* 174 */
			0xb8,		/* 184 */
/* 742 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 744 */	0xc0,		/* 192 */
			0x86,		/* 134 */
/* 746 */	0x6b,		/* 107 */
			0xe,		/* 14 */
/* 748 */	
			0x11, 0x10,	/* FC_RP */
/* 750 */	NdrFcShort( 0xffffff9c ),	/* Offset= -100 (650) */
/* 752 */	
			0x11, 0x10,	/* FC_RP */
/* 754 */	NdrFcShort( 0xffffffb8 ),	/* Offset= -72 (682) */
/* 756 */	
			0x11, 0x10,	/* FC_RP */
/* 758 */	NdrFcShort( 0x2 ),	/* Offset= 2 (760) */
/* 760 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 762 */	NdrFcLong( 0xa1a6d0f0 ),	/* -1582903056 */
/* 766 */	NdrFcShort( 0xffffde0d ),	/* -8691 */
/* 768 */	NdrFcShort( 0x11d1 ),	/* 4561 */
/* 770 */	0xae,		/* 174 */
			0xb3,		/* 179 */
/* 772 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 774 */	0xc0,		/* 192 */
			0x86,		/* 134 */
/* 776 */	0x6b,		/* 107 */
			0xe,		/* 14 */
/* 778 */	
			0x11, 0x10,	/* FC_RP */
/* 780 */	NdrFcShort( 0x2 ),	/* Offset= 2 (782) */
/* 782 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 784 */	NdrFcLong( 0x9c3ec8c1 ),	/* -1673606975 */
/* 788 */	NdrFcShort( 0xffffe2a1 ),	/* -7519 */
/* 790 */	NdrFcShort( 0x11d1 ),	/* 4561 */
/* 792 */	0xae,		/* 174 */
			0xb8,		/* 184 */
/* 794 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 796 */	0xc0,		/* 192 */
			0x86,		/* 134 */
/* 798 */	0x6b,		/* 107 */
			0xe,		/* 14 */
/* 800 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 802 */	0x5,		/* FC_WCHAR */
			0x5c,		/* FC_PAD */
/* 804 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 806 */	NdrFcLong( 0xf4edd6b0 ),	/* -185739600 */
/* 810 */	NdrFcShort( 0xffffbc4d ),	/* -17331 */
/* 812 */	NdrFcShort( 0x11d1 ),	/* 4561 */
/* 814 */	0xae,		/* 174 */
			0x8f,		/* 143 */
/* 816 */	0xb8,		/* 184 */
			0xbb,		/* 187 */
/* 818 */	0x59,		/* 89 */
			0x0,		/* 0 */
/* 820 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 822 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] */
/* 824 */	NdrFcShort( 0xffffff88 ),	/* Offset= -120 (704) */
/* 826 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 830 */	NdrFcShort( 0x4 ),	/* 4 */
/* 832 */	NdrFcShort( 0x0 ),	/* 0 */
/* 834 */	NdrFcShort( 0xfffffcbe ),	/* Offset= -834 (0) */
/* 836 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] */
/* 838 */	NdrFcShort( 0x2 ),	/* Offset= 2 (840) */
/* 840 */	
			0x13, 0x0,	/* FC_OP */
/* 842 */	NdrFcShort( 0xfffffcf0 ),	/* Offset= -784 (58) */
/* 844 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] */
/* 846 */	NdrFcShort( 0xffffff8c ),	/* Offset= -116 (730) */
/* 848 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 850 */	NdrFcShort( 0x0 ),	/* 0 */
/* 852 */	NdrFcShort( 0x4 ),	/* 4 */
/* 854 */	NdrFcShort( 0x0 ),	/* 0 */
/* 856 */	NdrFcShort( 0xfffffca8 ),	/* Offset= -856 (0) */
/* 858 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] */
/* 860 */	NdrFcShort( 0xffffff9c ),	/* Offset= -100 (760) */
/* 862 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 864 */	NdrFcShort( 0x0 ),	/* 0 */
/* 866 */	NdrFcShort( 0x4 ),	/* 4 */
/* 868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 870 */	NdrFcShort( 0xfffffc9a ),	/* Offset= -870 (0) */
/* 872 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] */
/* 874 */	NdrFcShort( 0xffffffa4 ),	/* Offset= -92 (782) */
/* 876 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 878 */	NdrFcLong( 0x215643d0 ),	/* 559301584 */
/* 882 */	NdrFcShort( 0xffffbba7 ),	/* -17497 */
/* 884 */	NdrFcShort( 0x11d1 ),	/* 4561 */
/* 886 */	0xae,		/* 174 */
			0x8f,		/* 143 */
/* 888 */	0xb8,		/* 184 */
			0xbb,		/* 187 */
/* 890 */	0x59,		/* 89 */
			0x0,		/* 0 */
/* 892 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 894 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 896 */	NdrFcShort( 0x2 ),	/* Offset= 2 (898) */
/* 898 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 900 */	NdrFcShort( 0x0 ),	/* 0 */
/* 902 */	NdrFcShort( 0x4 ),	/* 4 */
/* 904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 906 */	NdrFcShort( 0xfffffcbe ),	/* Offset= -834 (72) */
/* 908 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 910 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 912 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 914 */	NdrFcShort( 0x3be ),	/* Offset= 958 (1872) */
/* 916 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x6,		/* FC_SHORT */
/* 918 */	0x6,		/* 6 */
			0x0,		/*  */
/* 920 */	NdrFcShort( 0x4 ),	/* 4 */
/* 922 */	NdrFcShort( 0x2 ),	/* Offset= 2 (924) */
/* 924 */	NdrFcShort( 0x4 ),	/* 4 */
/* 926 */	NdrFcShort( 0x4 ),	/* 4 */
/* 928 */	NdrFcLong( 0x1a ),	/* 26 */
/* 932 */	NdrFcShort( 0x16 ),	/* Offset= 22 (954) */
/* 934 */	NdrFcLong( 0x1b ),	/* 27 */
/* 938 */	NdrFcShort( 0x10 ),	/* Offset= 16 (954) */
/* 940 */	NdrFcLong( 0x1c ),	/* 28 */
/* 944 */	NdrFcShort( 0xe ),	/* Offset= 14 (958) */
/* 946 */	NdrFcLong( 0x1d ),	/* 29 */
/* 950 */	NdrFcShort( 0xffff8008 ),	/* Offset= -32760 (-31810) */
/* 952 */	NdrFcShort( 0x0 ),	/* Offset= 0 (952) */
/* 954 */	
			0x13, 0x0,	/* FC_OP */
/* 956 */	NdrFcShort( 0x2c ),	/* Offset= 44 (1000) */
/* 958 */	
			0x13, 0x0,	/* FC_OP */
/* 960 */	NdrFcShort( 0x18 ),	/* Offset= 24 (984) */
/* 962 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 964 */	NdrFcShort( 0x8 ),	/* 8 */
/* 966 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 968 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 970 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 972 */	NdrFcShort( 0x8 ),	/* 8 */
/* 974 */	0x6,		/* 6 */
			0x0,		/*  */
/* 976 */	NdrFcShort( 0xfffffffc ),	/* -4 */
/* 978 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 980 */	NdrFcShort( 0xffffffee ),	/* Offset= -18 (962) */
/* 982 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 984 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 986 */	NdrFcShort( 0x4 ),	/* 4 */
/* 988 */	NdrFcShort( 0xffffffee ),	/* Offset= -18 (970) */
/* 990 */	NdrFcShort( 0x0 ),	/* Offset= 0 (990) */
/* 992 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 994 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1000) */
/* 996 */	0x6,		/* FC_SHORT */
			0x3e,		/* FC_STRUCTPAD2 */
/* 998 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1000 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1002 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1006 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1006) */
/* 1008 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1010 */	NdrFcShort( 0xffffffa2 ),	/* Offset= -94 (916) */
/* 1012 */	0x6,		/* FC_SHORT */
			0x3e,		/* FC_STRUCTPAD2 */
/* 1014 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1016 */	
			0x13, 0x0,	/* FC_OP */
/* 1018 */	NdrFcShort( 0x2ec ),	/* Offset= 748 (1766) */
/* 1020 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x6,		/* FC_SHORT */
/* 1022 */	0x6,		/* 6 */
			0x0,		/*  */
/* 1024 */	NdrFcShort( 0xfffffff8 ),	/* -8 */
/* 1026 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1028) */
/* 1028 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1030 */	NdrFcShort( 0x29 ),	/* 41 */
/* 1032 */	NdrFcLong( 0x3 ),	/* 3 */
/* 1036 */	NdrFcShort( 0xffff8008 ),	/* Offset= -32760 (-31724) */
/* 1038 */	NdrFcLong( 0x11 ),	/* 17 */
/* 1042 */	NdrFcShort( 0xffff8002 ),	/* Offset= -32766 (-31724) */
/* 1044 */	NdrFcLong( 0x2 ),	/* 2 */
/* 1048 */	NdrFcShort( 0xffff8006 ),	/* Offset= -32762 (-31714) */
/* 1050 */	NdrFcLong( 0x4 ),	/* 4 */
/* 1054 */	NdrFcShort( 0xffff800a ),	/* Offset= -32758 (-31704) */
/* 1056 */	NdrFcLong( 0x5 ),	/* 5 */
/* 1060 */	NdrFcShort( 0xffff800c ),	/* Offset= -32756 (-31696) */
/* 1062 */	NdrFcLong( 0xb ),	/* 11 */
/* 1066 */	NdrFcShort( 0xffff8006 ),	/* Offset= -32762 (-31696) */
/* 1068 */	NdrFcLong( 0xa ),	/* 10 */
/* 1072 */	NdrFcShort( 0xffff8008 ),	/* Offset= -32760 (-31688) */
/* 1074 */	NdrFcLong( 0x6 ),	/* 6 */
/* 1078 */	NdrFcShort( 0xca ),	/* Offset= 202 (1280) */
/* 1080 */	NdrFcLong( 0x7 ),	/* 7 */
/* 1084 */	NdrFcShort( 0xffff800c ),	/* Offset= -32756 (-31672) */
/* 1086 */	NdrFcLong( 0x8 ),	/* 8 */
/* 1090 */	NdrFcShort( 0xfffffc06 ),	/* Offset= -1018 (72) */
/* 1092 */	NdrFcLong( 0xd ),	/* 13 */
/* 1096 */	NdrFcShort( 0xbe ),	/* Offset= 190 (1286) */
/* 1098 */	NdrFcLong( 0x9 ),	/* 9 */
/* 1102 */	NdrFcShort( 0xca ),	/* Offset= 202 (1304) */
/* 1104 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 1108 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (1322) */
/* 1110 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 1114 */	NdrFcShort( 0x24c ),	/* Offset= 588 (1702) */
/* 1116 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 1120 */	NdrFcShort( 0x24a ),	/* Offset= 586 (1706) */
/* 1122 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 1126 */	NdrFcShort( 0x248 ),	/* Offset= 584 (1710) */
/* 1128 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 1132 */	NdrFcShort( 0x246 ),	/* Offset= 582 (1714) */
/* 1134 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 1138 */	NdrFcShort( 0x244 ),	/* Offset= 580 (1718) */
/* 1140 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 1144 */	NdrFcShort( 0x232 ),	/* Offset= 562 (1706) */
/* 1146 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 1150 */	NdrFcShort( 0x230 ),	/* Offset= 560 (1710) */
/* 1152 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 1156 */	NdrFcShort( 0x236 ),	/* Offset= 566 (1722) */
/* 1158 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 1162 */	NdrFcShort( 0x22c ),	/* Offset= 556 (1718) */
/* 1164 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 1168 */	NdrFcShort( 0x22e ),	/* Offset= 558 (1726) */
/* 1170 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 1174 */	NdrFcShort( 0x22c ),	/* Offset= 556 (1730) */
/* 1176 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 1180 */	NdrFcShort( 0x22a ),	/* Offset= 554 (1734) */
/* 1182 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 1186 */	NdrFcShort( 0x228 ),	/* Offset= 552 (1738) */
/* 1188 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 1192 */	NdrFcShort( 0x226 ),	/* Offset= 550 (1742) */
/* 1194 */	NdrFcLong( 0x10 ),	/* 16 */
/* 1198 */	NdrFcShort( 0xffff8002 ),	/* Offset= -32766 (-31568) */
/* 1200 */	NdrFcLong( 0x12 ),	/* 18 */
/* 1204 */	NdrFcShort( 0xffff8006 ),	/* Offset= -32762 (-31558) */
/* 1206 */	NdrFcLong( 0x13 ),	/* 19 */
/* 1210 */	NdrFcShort( 0xffff8008 ),	/* Offset= -32760 (-31550) */
/* 1212 */	NdrFcLong( 0x16 ),	/* 22 */
/* 1216 */	NdrFcShort( 0xffff8008 ),	/* Offset= -32760 (-31544) */
/* 1218 */	NdrFcLong( 0x17 ),	/* 23 */
/* 1222 */	NdrFcShort( 0xffff8008 ),	/* Offset= -32760 (-31538) */
/* 1224 */	NdrFcLong( 0xe ),	/* 14 */
/* 1228 */	NdrFcShort( 0x20a ),	/* Offset= 522 (1750) */
/* 1230 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 1234 */	NdrFcShort( 0x210 ),	/* Offset= 528 (1762) */
/* 1236 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 1240 */	NdrFcShort( 0x1ce ),	/* Offset= 462 (1702) */
/* 1242 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 1246 */	NdrFcShort( 0x1cc ),	/* Offset= 460 (1706) */
/* 1248 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 1252 */	NdrFcShort( 0x1ca ),	/* Offset= 458 (1710) */
/* 1254 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 1258 */	NdrFcShort( 0x1c4 ),	/* Offset= 452 (1710) */
/* 1260 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 1264 */	NdrFcShort( 0x1be ),	/* Offset= 446 (1710) */
/* 1266 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1270 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1270) */
/* 1272 */	NdrFcLong( 0x1 ),	/* 1 */
/* 1276 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1276) */
/* 1278 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (1277) */
/* 1280 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 1282 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1284 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1286 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1288 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1296 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 1298 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1300 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1302 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1304 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1306 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 1310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1314 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 1316 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1318 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1320 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1322 */	
			0x13, 0x0,	/* FC_OP */
/* 1324 */	NdrFcShort( 0x168 ),	/* Offset= 360 (1684) */
/* 1326 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x48,		/* 72 */
/* 1328 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1330 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1332 */	NdrFcLong( 0x8 ),	/* 8 */
/* 1336 */	NdrFcShort( 0x4c ),	/* Offset= 76 (1412) */
/* 1338 */	NdrFcLong( 0xd ),	/* 13 */
/* 1342 */	NdrFcShort( 0x6c ),	/* Offset= 108 (1450) */
/* 1344 */	NdrFcLong( 0x9 ),	/* 9 */
/* 1348 */	NdrFcShort( 0x88 ),	/* Offset= 136 (1484) */
/* 1350 */	NdrFcLong( 0xc ),	/* 12 */
/* 1354 */	NdrFcShort( 0xb0 ),	/* Offset= 176 (1530) */
/* 1356 */	NdrFcLong( 0x10 ),	/* 16 */
/* 1360 */	NdrFcShort( 0xc8 ),	/* Offset= 200 (1560) */
/* 1362 */	NdrFcLong( 0x2 ),	/* 2 */
/* 1366 */	NdrFcShort( 0xe0 ),	/* Offset= 224 (1590) */
/* 1368 */	NdrFcLong( 0x3 ),	/* 3 */
/* 1372 */	NdrFcShort( 0xf8 ),	/* Offset= 248 (1620) */
/* 1374 */	NdrFcLong( 0x14 ),	/* 20 */
/* 1378 */	NdrFcShort( 0x110 ),	/* Offset= 272 (1650) */
/* 1380 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1380) */
/* 1382 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1384 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1386 */	0x18,		/* 24 */
			0x0,		/*  */
/* 1388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1390 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1392 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 1394 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1398 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1404 */	0x13, 0x0,	/* FC_OP */
/* 1406 */	NdrFcShort( 0xfffffa90 ),	/* Offset= -1392 (14) */
/* 1408 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1410 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1412 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1414 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1416 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1418 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1420 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1422 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1424 */	0x11, 0x0,	/* FC_RP */
/* 1426 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (1382) */
/* 1428 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1430 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1432 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1436 */	0x18,		/* 24 */
			0x0,		/*  */
/* 1438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1440 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1444 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1446 */	NdrFcShort( 0xffffff60 ),	/* Offset= -160 (1286) */
/* 1448 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1450 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1452 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1456 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1462) */
/* 1458 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 1460 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1462 */	
			0x11, 0x0,	/* FC_RP */
/* 1464 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (1432) */
/* 1466 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1470 */	0x18,		/* 24 */
			0x0,		/*  */
/* 1472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1474 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1478 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1480 */	NdrFcShort( 0xffffff50 ),	/* Offset= -176 (1304) */
/* 1482 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1484 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1486 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1490 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1496) */
/* 1492 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 1494 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1496 */	
			0x11, 0x0,	/* FC_RP */
/* 1498 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (1466) */
/* 1500 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1502 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1504 */	0x18,		/* 24 */
			0x0,		/*  */
/* 1506 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1508 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1510 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 1512 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1516 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1522 */	0x13, 0x0,	/* FC_OP */
/* 1524 */	NdrFcShort( 0xf2 ),	/* Offset= 242 (1766) */
/* 1526 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1528 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1530 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1532 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1534 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1536 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1538 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1540 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1542 */	0x11, 0x0,	/* FC_RP */
/* 1544 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (1500) */
/* 1546 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1548 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1550 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 1552 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1554 */	0x19,		/* 25 */
			0x0,		/*  */
/* 1556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1558 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 1560 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1562 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1564 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1566 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1568 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1570 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1572 */	0x13, 0x0,	/* FC_OP */
/* 1574 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (1550) */
/* 1576 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1578 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1580 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 1582 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1584 */	0x19,		/* 25 */
			0x0,		/*  */
/* 1586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1588 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 1590 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1592 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1594 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1596 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1598 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1600 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1602 */	0x13, 0x0,	/* FC_OP */
/* 1604 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (1580) */
/* 1606 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1608 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1610 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1612 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1614 */	0x19,		/* 25 */
			0x0,		/*  */
/* 1616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1618 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1620 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1622 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1624 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1626 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1628 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1630 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1632 */	0x13, 0x0,	/* FC_OP */
/* 1634 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (1610) */
/* 1636 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1638 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1640 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 1642 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1644 */	0x19,		/* 25 */
			0x0,		/*  */
/* 1646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1648 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1650 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1652 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1654 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1656 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1658 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1660 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1662 */	0x13, 0x0,	/* FC_OP */
/* 1664 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (1640) */
/* 1666 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1668 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1670 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1672 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1674 */	0x6,		/* 6 */
			0x0,		/*  */
/* 1676 */	NdrFcShort( 0xffffffe8 ),	/* -24 */
/* 1678 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1680 */	NdrFcShort( 0xfffffd32 ),	/* Offset= -718 (962) */
/* 1682 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1684 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1686 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1688 */	NdrFcShort( 0xffffffee ),	/* Offset= -18 (1670) */
/* 1690 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1690) */
/* 1692 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1694 */	0x38,		/* FC_ALIGNM4 */
			0x8,		/* FC_LONG */
/* 1696 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1698 */	0x0,		/* 0 */
			NdrFcShort( 0xfffffe8b ),	/* Offset= -373 (1326) */
			0x5b,		/* FC_END */
/* 1702 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1704 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 1706 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1708 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 1710 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1712 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1714 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1716 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 1718 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1720 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 1722 */	
			0x13, 0x0,	/* FC_OP */
/* 1724 */	NdrFcShort( 0xfffffe44 ),	/* Offset= -444 (1280) */
/* 1726 */	
			0x13, 0x10,	/* FC_OP */
/* 1728 */	NdrFcShort( 0xfffff988 ),	/* Offset= -1656 (72) */
/* 1730 */	
			0x13, 0x10,	/* FC_OP */
/* 1732 */	NdrFcShort( 0xfffffe42 ),	/* Offset= -446 (1286) */
/* 1734 */	
			0x13, 0x10,	/* FC_OP */
/* 1736 */	NdrFcShort( 0xfffffe50 ),	/* Offset= -432 (1304) */
/* 1738 */	
			0x13, 0x10,	/* FC_OP */
/* 1740 */	NdrFcShort( 0xfffffe5e ),	/* Offset= -418 (1322) */
/* 1742 */	
			0x13, 0x10,	/* FC_OP */
/* 1744 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1746) */
/* 1746 */	
			0x13, 0x0,	/* FC_OP */
/* 1748 */	NdrFcShort( 0xfffff92c ),	/* Offset= -1748 (0) */
/* 1750 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 1752 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1754 */	0x6,		/* FC_SHORT */
			0x2,		/* FC_CHAR */
/* 1756 */	0x2,		/* FC_CHAR */
			0x38,		/* FC_ALIGNM4 */
/* 1758 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 1760 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1762 */	
			0x13, 0x0,	/* FC_OP */
/* 1764 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (1750) */
/* 1766 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1768 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1770 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1772 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1772) */
/* 1774 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1776 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1778 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1780 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1782 */	NdrFcShort( 0xfffffd06 ),	/* Offset= -762 (1020) */
/* 1784 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1786 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1788 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1790 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1794 */	NdrFcShort( 0xfffffcf6 ),	/* Offset= -778 (1016) */
/* 1796 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1798 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1802 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1802) */
/* 1804 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1806 */	0x4,		/* 4 */
			NdrFcShort( 0xffffffeb ),	/* Offset= -21 (1786) */
			0x5b,		/* FC_END */
/* 1810 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1812 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1814 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1816 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1822) */
/* 1818 */	0x36,		/* FC_POINTER */
			0x6,		/* FC_SHORT */
/* 1820 */	0x3e,		/* FC_STRUCTPAD2 */
			0x5b,		/* FC_END */
/* 1822 */	
			0x13, 0x0,	/* FC_OP */
/* 1824 */	NdrFcShort( 0xffffffe4 ),	/* Offset= -28 (1796) */
/* 1826 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1828 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1832 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1832) */
/* 1834 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1836 */	NdrFcShort( 0xfffffcbc ),	/* Offset= -836 (1000) */
/* 1838 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1840 */	NdrFcShort( 0xffffffe2 ),	/* Offset= -30 (1810) */
/* 1842 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1844 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1846 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1848 */	0x16,		/* 22 */
			0x0,		/*  */
/* 1850 */	NdrFcShort( 0x1e ),	/* 30 */
/* 1852 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1854 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1858 */	0x16,		/* 22 */
			0x0,		/*  */
/* 1860 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1862 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1866 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1868 */	NdrFcShort( 0xffffffd6 ),	/* Offset= -42 (1826) */
/* 1870 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1872 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1874 */	NdrFcShort( 0x34 ),	/* 52 */
/* 1876 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1878 */	NdrFcShort( 0x14 ),	/* Offset= 20 (1898) */
/* 1880 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 1882 */	0x36,		/* FC_POINTER */
			0xe,		/* FC_ENUM32 */
/* 1884 */	0xe,		/* FC_ENUM32 */
			0xe,		/* FC_ENUM32 */
/* 1886 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1888 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1890 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1892 */	NdrFcShort( 0xffffffbe ),	/* Offset= -66 (1826) */
/* 1894 */	0x6,		/* FC_SHORT */
			0x3e,		/* FC_STRUCTPAD2 */
/* 1896 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1898 */	
			0x13, 0x0,	/* FC_OP */
/* 1900 */	NdrFcShort( 0xffffffc8 ),	/* Offset= -56 (1844) */
/* 1902 */	
			0x13, 0x0,	/* FC_OP */
/* 1904 */	NdrFcShort( 0xffffffce ),	/* Offset= -50 (1854) */
/* 1906 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1908 */	0xd,		/* FC_ENUM16 */
			0x5c,		/* FC_PAD */
/* 1910 */	
			0x11, 0x0,	/* FC_RP */
/* 1912 */	NdrFcShort( 0xffffffd8 ),	/* Offset= -40 (1872) */

			0x0
        }
    };

const CInterfaceProxyVtbl * _sym_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IDisFunctionProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IDisSmXProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ITypeProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IEnumTypesProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ISymbolProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IEnumModulesProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IDisSymMgrProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IEnumSymbolsProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IModuleProxyVtbl,
    0
};

const CInterfaceStubVtbl * _sym_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IDisFunctionStubVtbl,
    ( CInterfaceStubVtbl *) &_IDisSmXStubVtbl,
    ( CInterfaceStubVtbl *) &_ITypeStubVtbl,
    ( CInterfaceStubVtbl *) &_IEnumTypesStubVtbl,
    ( CInterfaceStubVtbl *) &_ISymbolStubVtbl,
    ( CInterfaceStubVtbl *) &_IEnumModulesStubVtbl,
    ( CInterfaceStubVtbl *) &_IDisSymMgrStubVtbl,
    ( CInterfaceStubVtbl *) &_IEnumSymbolsStubVtbl,
    ( CInterfaceStubVtbl *) &_IModuleStubVtbl,
    0
};

PCInterfaceName const _sym_InterfaceNamesList[] = 
{
    "IDisFunction",
    "IDisSmX",
    "IType",
    "IEnumTypes",
    "ISymbol",
    "IEnumModules",
    "IDisSymMgr",
    "IEnumSymbols",
    "IModule",
    0
};


#define _sym_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _sym, pIID, n)

int __stdcall _sym_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _sym, 9, 8 )
    IID_BS_LOOKUP_NEXT_TEST( _sym, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _sym, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _sym, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _sym, 9, *pIndex )
    
}

const ExtendedProxyFileInfo sym_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _sym_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _sym_StubVtblList,
    (const PCInterfaceName * ) & _sym_InterfaceNamesList,
    0, // no delegation
    & _sym_IID_Lookup, 
    9,
    1
};
