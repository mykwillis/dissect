/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun May 24 08:36:22 1998
 */
/* Compiler settings for sym.idl:
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

#ifndef __sym_h__
#define __sym_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IType_FWD_DEFINED__
#define __IType_FWD_DEFINED__
typedef interface IType IType;
#endif 	/* __IType_FWD_DEFINED__ */


#ifndef __ISymbol_FWD_DEFINED__
#define __ISymbol_FWD_DEFINED__
typedef interface ISymbol ISymbol;
#endif 	/* __ISymbol_FWD_DEFINED__ */


#ifndef __IModule_FWD_DEFINED__
#define __IModule_FWD_DEFINED__
typedef interface IModule IModule;
#endif 	/* __IModule_FWD_DEFINED__ */


#ifndef __IEnumTypes_FWD_DEFINED__
#define __IEnumTypes_FWD_DEFINED__
typedef interface IEnumTypes IEnumTypes;
#endif 	/* __IEnumTypes_FWD_DEFINED__ */


#ifndef __IEnumSymbols_FWD_DEFINED__
#define __IEnumSymbols_FWD_DEFINED__
typedef interface IEnumSymbols IEnumSymbols;
#endif 	/* __IEnumSymbols_FWD_DEFINED__ */


#ifndef __IEnumModules_FWD_DEFINED__
#define __IEnumModules_FWD_DEFINED__
typedef interface IEnumModules IEnumModules;
#endif 	/* __IEnumModules_FWD_DEFINED__ */


#ifndef __IDisSymMgr_FWD_DEFINED__
#define __IDisSymMgr_FWD_DEFINED__
typedef interface IDisSymMgr IDisSymMgr;
#endif 	/* __IDisSymMgr_FWD_DEFINED__ */


#ifndef __IDisSmX_FWD_DEFINED__
#define __IDisSmX_FWD_DEFINED__
typedef interface IDisSmX IDisSmX;
#endif 	/* __IDisSmX_FWD_DEFINED__ */


#ifndef __IDisFunction_FWD_DEFINED__
#define __IDisFunction_FWD_DEFINED__
typedef interface IDisFunction IDisFunction;
#endif 	/* __IDisFunction_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "ldr.h"
#include "sys.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL__intf_0000
 * at Sun May 24 08:36:22 1998
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 











#define STANDARD_HTYPE( vt )  ((HTYPE)( (DWORD)vt | 0x80000000 ))
#define NAMELESS_UNION  
typedef struct  ___tagHTYPE
    {
    DWORD dummy;
    }	___HTYPE;

typedef ___HTYPE __RPC_FAR *HTYPE;

typedef 
enum tagSYMKIND
    {	SKIND_FUNC	= 0,
	SKIND_GLOBAL	= SKIND_FUNC + 1,
	SKIND_LOCAL	= SKIND_GLOBAL + 1,
	SKIND_UNKNOWN	= SKIND_LOCAL + 1
    }	SYMKIND;

typedef struct  tagRECORD_INFO
    {
    int NumberOfMembers;
    /* [size_is] */ HTYPE __RPC_FAR *Types;
    /* [size_is] */ BSTR __RPC_FAR *Names;
    }	RECORD_INFO;

typedef struct  tagENUM_INFO
    {
    int NumberOfMembers;
    /* [size_is] */ DWORD __RPC_FAR *Values;
    /* [size_is] */ BSTR __RPC_FAR *Names;
    }	ENUM_INFO;

typedef struct  tagUNION_INFO
    {
    int NumberOfMembers;
    /* [size_is] */ HTYPE __RPC_FAR *Types;
    /* [size_is] */ BSTR __RPC_FAR *Names;
    }	UNION_INFO;

typedef struct  tagALIAS_INFO
    {
    HTYPE Type;
    }	ALIAS_INFO;

typedef struct  tagTYPE_INFO
    {
    BSTR Name;
    BSTR DocString;
    DWORD Size;
    TYPEKIND TypeKind;
    /* [switch_is] */ /* [switch_type] */ union 
        {
        /* [case()] */ UNION_INFO Union;
        /* [case()] */ RECORD_INFO Record;
        /* [case()] */ ENUM_INFO Enum;
        /* [case()] */ ALIAS_INFO Alias;
        }	NAMELESS_UNION;
    }	TYPE_INFO;

typedef struct  tagFUNCTION_INFO
    {
    FUNCKIND FuncKind;
    INVOKEKIND InvKind;
    CALLCONV CallConv;
    HTYPE ReturnType;
    int NumberOfParams;
    /* [size_is] */ HTYPE __RPC_FAR *Types;
    /* [size_is] */ BSTR __RPC_FAR *Names;
    }	FUNCTION_INFO;

typedef struct  tagGLOBAL_INFO
    {
    HTYPE Type;
    }	GLOBAL_INFO;

typedef struct  tagLOCAL_INFO
    {
    int Dummy;
    }	LOCAL_INFO;

typedef struct  tagSYMBOL_INFO
    {
    BSTR Name;
    BSTR DocString;
    DWORD Address;
    DWORD Size;
    SYMKIND SymKind;
    /* [switch_is] */ /* [switch_type] */ union 
        {
        /* [case()] */ FUNCTION_INFO Function;
        /* [case()] */ GLOBAL_INFO Global;
        /* [case()] */ LOCAL_INFO Local;
        /* [default] */  /* Empty union arm */ 
        }	NAMELESS_UNION;
    }	SYMBOL_INFO;

typedef struct  tagMODULE_INFO
    {
    BSTR Name;
    BSTR DocString;
    DWORD BaseAddress;
    DWORD Size;
    }	MODULE_INFO;



extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_s_ifspec;

#ifndef __IType_INTERFACE_DEFINED__
#define __IType_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IType
 * at Sun May 24 08:36:22 1998
 * using MIDL 3.00.44
 ****************************************/
/* [object][uuid] */ 



EXTERN_C const IID IID_IType;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IType : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            /* [in] */ BSTR Name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDocString( 
            /* [in] */ BSTR DocString) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMemberName( 
            /* [in] */ int Position,
            /* [in] */ BSTR Name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMemberType( 
            /* [in] */ int Position,
            /* [in] */ HTYPE Type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMemberValue( 
            /* [in] */ int Position,
            /* [in] */ DWORD Value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTypeInfo( 
            /* [out] */ TYPE_INFO __RPC_FAR *__RPC_FAR *TypeInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseTypeInfo( 
            /* [in] */ TYPE_INFO __RPC_FAR *TypeInfo) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITypeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IType __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IType __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IType __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetName )( 
            IType __RPC_FAR * This,
            /* [in] */ BSTR Name);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDocString )( 
            IType __RPC_FAR * This,
            /* [in] */ BSTR DocString);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMemberName )( 
            IType __RPC_FAR * This,
            /* [in] */ int Position,
            /* [in] */ BSTR Name);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMemberType )( 
            IType __RPC_FAR * This,
            /* [in] */ int Position,
            /* [in] */ HTYPE Type);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMemberValue )( 
            IType __RPC_FAR * This,
            /* [in] */ int Position,
            /* [in] */ DWORD Value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IType __RPC_FAR * This,
            /* [out] */ TYPE_INFO __RPC_FAR *__RPC_FAR *TypeInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReleaseTypeInfo )( 
            IType __RPC_FAR * This,
            /* [in] */ TYPE_INFO __RPC_FAR *TypeInfo);
        
        END_INTERFACE
    } ITypeVtbl;

    interface IType
    {
        CONST_VTBL struct ITypeVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IType_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IType_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IType_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IType_SetName(This,Name)	\
    (This)->lpVtbl -> SetName(This,Name)

#define IType_SetDocString(This,DocString)	\
    (This)->lpVtbl -> SetDocString(This,DocString)

#define IType_SetMemberName(This,Position,Name)	\
    (This)->lpVtbl -> SetMemberName(This,Position,Name)

#define IType_SetMemberType(This,Position,Type)	\
    (This)->lpVtbl -> SetMemberType(This,Position,Type)

#define IType_SetMemberValue(This,Position,Value)	\
    (This)->lpVtbl -> SetMemberValue(This,Position,Value)

#define IType_GetTypeInfo(This,TypeInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,TypeInfo)

#define IType_ReleaseTypeInfo(This,TypeInfo)	\
    (This)->lpVtbl -> ReleaseTypeInfo(This,TypeInfo)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IType_SetName_Proxy( 
    IType __RPC_FAR * This,
    /* [in] */ BSTR Name);


void __RPC_STUB IType_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IType_SetDocString_Proxy( 
    IType __RPC_FAR * This,
    /* [in] */ BSTR DocString);


void __RPC_STUB IType_SetDocString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IType_SetMemberName_Proxy( 
    IType __RPC_FAR * This,
    /* [in] */ int Position,
    /* [in] */ BSTR Name);


void __RPC_STUB IType_SetMemberName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IType_SetMemberType_Proxy( 
    IType __RPC_FAR * This,
    /* [in] */ int Position,
    /* [in] */ HTYPE Type);


void __RPC_STUB IType_SetMemberType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IType_SetMemberValue_Proxy( 
    IType __RPC_FAR * This,
    /* [in] */ int Position,
    /* [in] */ DWORD Value);


void __RPC_STUB IType_SetMemberValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IType_GetTypeInfo_Proxy( 
    IType __RPC_FAR * This,
    /* [out] */ TYPE_INFO __RPC_FAR *__RPC_FAR *TypeInfo);


void __RPC_STUB IType_GetTypeInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IType_ReleaseTypeInfo_Proxy( 
    IType __RPC_FAR * This,
    /* [in] */ TYPE_INFO __RPC_FAR *TypeInfo);


void __RPC_STUB IType_ReleaseTypeInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IType_INTERFACE_DEFINED__ */


#ifndef __ISymbol_INTERFACE_DEFINED__
#define __ISymbol_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ISymbol
 * at Sun May 24 08:36:22 1998
 * using MIDL 3.00.44
 ****************************************/
/* [object][uuid] */ 



EXTERN_C const IID IID_ISymbol;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ISymbol : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSymbolInfo( 
            /* [out] */ SYMBOL_INFO __RPC_FAR *__RPC_FAR *SymbolInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseSymbolInfo( 
            /* [in] */ SYMBOL_INFO __RPC_FAR *SymbolInfo) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISymbolVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISymbol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISymbol __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISymbol __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSymbolInfo )( 
            ISymbol __RPC_FAR * This,
            /* [out] */ SYMBOL_INFO __RPC_FAR *__RPC_FAR *SymbolInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReleaseSymbolInfo )( 
            ISymbol __RPC_FAR * This,
            /* [in] */ SYMBOL_INFO __RPC_FAR *SymbolInfo);
        
        END_INTERFACE
    } ISymbolVtbl;

    interface ISymbol
    {
        CONST_VTBL struct ISymbolVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISymbol_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISymbol_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISymbol_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISymbol_GetSymbolInfo(This,SymbolInfo)	\
    (This)->lpVtbl -> GetSymbolInfo(This,SymbolInfo)

#define ISymbol_ReleaseSymbolInfo(This,SymbolInfo)	\
    (This)->lpVtbl -> ReleaseSymbolInfo(This,SymbolInfo)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ISymbol_GetSymbolInfo_Proxy( 
    ISymbol __RPC_FAR * This,
    /* [out] */ SYMBOL_INFO __RPC_FAR *__RPC_FAR *SymbolInfo);


void __RPC_STUB ISymbol_GetSymbolInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISymbol_ReleaseSymbolInfo_Proxy( 
    ISymbol __RPC_FAR * This,
    /* [in] */ SYMBOL_INFO __RPC_FAR *SymbolInfo);


void __RPC_STUB ISymbol_ReleaseSymbolInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISymbol_INTERFACE_DEFINED__ */


#ifndef __IModule_INTERFACE_DEFINED__
#define __IModule_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IModule
 * at Sun May 24 08:36:22 1998
 * using MIDL 3.00.44
 ****************************************/
/* [object][uuid] */ 



EXTERN_C const IID IID_IModule;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IModule : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetModuleInfo( 
            /* [out] */ MODULE_INFO __RPC_FAR *__RPC_FAR *ModuleInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseModuleInfo( 
            /* [in] */ MODULE_INFO __RPC_FAR *ModuleInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddSymbol( 
            /* [out] */ ISymbol __RPC_FAR *__RPC_FAR *ppISymbol,
            /* [in] */ SYMBOL_INFO __RPC_FAR *SymbolInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSymbolByName( 
            /* [out] */ ISymbol __RPC_FAR *__RPC_FAR *ppIUnknown,
            /* [in] */ BSTR Name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSymbolByAddress( 
            /* [out] */ ISymbol __RPC_FAR *__RPC_FAR *ppIUnknown,
            /* [in] */ DWORD Address) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumSymbols( 
            /* [out] */ IEnumSymbols __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IModuleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IModule __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IModule __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IModule __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetModuleInfo )( 
            IModule __RPC_FAR * This,
            /* [out] */ MODULE_INFO __RPC_FAR *__RPC_FAR *ModuleInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReleaseModuleInfo )( 
            IModule __RPC_FAR * This,
            /* [in] */ MODULE_INFO __RPC_FAR *ModuleInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddSymbol )( 
            IModule __RPC_FAR * This,
            /* [out] */ ISymbol __RPC_FAR *__RPC_FAR *ppISymbol,
            /* [in] */ SYMBOL_INFO __RPC_FAR *SymbolInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSymbolByName )( 
            IModule __RPC_FAR * This,
            /* [out] */ ISymbol __RPC_FAR *__RPC_FAR *ppIUnknown,
            /* [in] */ BSTR Name);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSymbolByAddress )( 
            IModule __RPC_FAR * This,
            /* [out] */ ISymbol __RPC_FAR *__RPC_FAR *ppIUnknown,
            /* [in] */ DWORD Address);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumSymbols )( 
            IModule __RPC_FAR * This,
            /* [out] */ IEnumSymbols __RPC_FAR *__RPC_FAR *ppEnum);
        
        END_INTERFACE
    } IModuleVtbl;

    interface IModule
    {
        CONST_VTBL struct IModuleVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IModule_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IModule_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IModule_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IModule_GetModuleInfo(This,ModuleInfo)	\
    (This)->lpVtbl -> GetModuleInfo(This,ModuleInfo)

#define IModule_ReleaseModuleInfo(This,ModuleInfo)	\
    (This)->lpVtbl -> ReleaseModuleInfo(This,ModuleInfo)

#define IModule_AddSymbol(This,ppISymbol,SymbolInfo)	\
    (This)->lpVtbl -> AddSymbol(This,ppISymbol,SymbolInfo)

#define IModule_GetSymbolByName(This,ppIUnknown,Name)	\
    (This)->lpVtbl -> GetSymbolByName(This,ppIUnknown,Name)

#define IModule_GetSymbolByAddress(This,ppIUnknown,Address)	\
    (This)->lpVtbl -> GetSymbolByAddress(This,ppIUnknown,Address)

#define IModule_EnumSymbols(This,ppEnum)	\
    (This)->lpVtbl -> EnumSymbols(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IModule_GetModuleInfo_Proxy( 
    IModule __RPC_FAR * This,
    /* [out] */ MODULE_INFO __RPC_FAR *__RPC_FAR *ModuleInfo);


void __RPC_STUB IModule_GetModuleInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IModule_ReleaseModuleInfo_Proxy( 
    IModule __RPC_FAR * This,
    /* [in] */ MODULE_INFO __RPC_FAR *ModuleInfo);


void __RPC_STUB IModule_ReleaseModuleInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IModule_AddSymbol_Proxy( 
    IModule __RPC_FAR * This,
    /* [out] */ ISymbol __RPC_FAR *__RPC_FAR *ppISymbol,
    /* [in] */ SYMBOL_INFO __RPC_FAR *SymbolInfo);


void __RPC_STUB IModule_AddSymbol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IModule_GetSymbolByName_Proxy( 
    IModule __RPC_FAR * This,
    /* [out] */ ISymbol __RPC_FAR *__RPC_FAR *ppIUnknown,
    /* [in] */ BSTR Name);


void __RPC_STUB IModule_GetSymbolByName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IModule_GetSymbolByAddress_Proxy( 
    IModule __RPC_FAR * This,
    /* [out] */ ISymbol __RPC_FAR *__RPC_FAR *ppIUnknown,
    /* [in] */ DWORD Address);


void __RPC_STUB IModule_GetSymbolByAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IModule_EnumSymbols_Proxy( 
    IModule __RPC_FAR * This,
    /* [out] */ IEnumSymbols __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IModule_EnumSymbols_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IModule_INTERFACE_DEFINED__ */


#ifndef __IEnumTypes_INTERFACE_DEFINED__
#define __IEnumTypes_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumTypes
 * at Sun May 24 08:36:22 1998
 * using MIDL 3.00.44
 ****************************************/
/* [object][uuid] */ 



EXTERN_C const IID IID_IEnumTypes;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IEnumTypes : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            ULONG celt,
            IType __RPC_FAR *__RPC_FAR *rgelt,
            ULONG __RPC_FAR *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            IEnumTypes __RPC_FAR *__RPC_FAR *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumTypesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEnumTypes __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEnumTypes __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEnumTypes __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IEnumTypes __RPC_FAR * This,
            ULONG celt,
            IType __RPC_FAR *__RPC_FAR *rgelt,
            ULONG __RPC_FAR *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IEnumTypes __RPC_FAR * This,
            ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IEnumTypes __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IEnumTypes __RPC_FAR * This,
            IEnumTypes __RPC_FAR *__RPC_FAR *ppenum);
        
        END_INTERFACE
    } IEnumTypesVtbl;

    interface IEnumTypes
    {
        CONST_VTBL struct IEnumTypesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumTypes_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumTypes_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumTypes_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumTypes_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumTypes_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumTypes_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumTypes_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumTypes_Next_Proxy( 
    IEnumTypes __RPC_FAR * This,
    ULONG celt,
    IType __RPC_FAR *__RPC_FAR *rgelt,
    ULONG __RPC_FAR *pceltFetched);


void __RPC_STUB IEnumTypes_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumTypes_Skip_Proxy( 
    IEnumTypes __RPC_FAR * This,
    ULONG celt);


void __RPC_STUB IEnumTypes_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumTypes_Reset_Proxy( 
    IEnumTypes __RPC_FAR * This);


void __RPC_STUB IEnumTypes_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumTypes_Clone_Proxy( 
    IEnumTypes __RPC_FAR * This,
    IEnumTypes __RPC_FAR *__RPC_FAR *ppenum);


void __RPC_STUB IEnumTypes_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumTypes_INTERFACE_DEFINED__ */


#ifndef __IEnumSymbols_INTERFACE_DEFINED__
#define __IEnumSymbols_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumSymbols
 * at Sun May 24 08:36:22 1998
 * using MIDL 3.00.44
 ****************************************/
/* [object][uuid] */ 



EXTERN_C const IID IID_IEnumSymbols;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IEnumSymbols : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            ULONG celt,
            ISymbol __RPC_FAR *__RPC_FAR *rgelt,
            ULONG __RPC_FAR *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            IEnumSymbols __RPC_FAR *__RPC_FAR *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumSymbolsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEnumSymbols __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEnumSymbols __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEnumSymbols __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IEnumSymbols __RPC_FAR * This,
            ULONG celt,
            ISymbol __RPC_FAR *__RPC_FAR *rgelt,
            ULONG __RPC_FAR *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IEnumSymbols __RPC_FAR * This,
            ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IEnumSymbols __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IEnumSymbols __RPC_FAR * This,
            IEnumSymbols __RPC_FAR *__RPC_FAR *ppenum);
        
        END_INTERFACE
    } IEnumSymbolsVtbl;

    interface IEnumSymbols
    {
        CONST_VTBL struct IEnumSymbolsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumSymbols_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumSymbols_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumSymbols_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumSymbols_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumSymbols_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumSymbols_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumSymbols_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumSymbols_Next_Proxy( 
    IEnumSymbols __RPC_FAR * This,
    ULONG celt,
    ISymbol __RPC_FAR *__RPC_FAR *rgelt,
    ULONG __RPC_FAR *pceltFetched);


void __RPC_STUB IEnumSymbols_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumSymbols_Skip_Proxy( 
    IEnumSymbols __RPC_FAR * This,
    ULONG celt);


void __RPC_STUB IEnumSymbols_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumSymbols_Reset_Proxy( 
    IEnumSymbols __RPC_FAR * This);


void __RPC_STUB IEnumSymbols_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumSymbols_Clone_Proxy( 
    IEnumSymbols __RPC_FAR * This,
    IEnumSymbols __RPC_FAR *__RPC_FAR *ppenum);


void __RPC_STUB IEnumSymbols_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumSymbols_INTERFACE_DEFINED__ */


#ifndef __IEnumModules_INTERFACE_DEFINED__
#define __IEnumModules_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumModules
 * at Sun May 24 08:36:22 1998
 * using MIDL 3.00.44
 ****************************************/
/* [object][uuid] */ 



EXTERN_C const IID IID_IEnumModules;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IEnumModules : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            ULONG celt,
            IModule __RPC_FAR *__RPC_FAR *rgelt,
            ULONG __RPC_FAR *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            IEnumModules __RPC_FAR *__RPC_FAR *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumModulesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEnumModules __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEnumModules __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEnumModules __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IEnumModules __RPC_FAR * This,
            ULONG celt,
            IModule __RPC_FAR *__RPC_FAR *rgelt,
            ULONG __RPC_FAR *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IEnumModules __RPC_FAR * This,
            ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IEnumModules __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IEnumModules __RPC_FAR * This,
            IEnumModules __RPC_FAR *__RPC_FAR *ppenum);
        
        END_INTERFACE
    } IEnumModulesVtbl;

    interface IEnumModules
    {
        CONST_VTBL struct IEnumModulesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumModules_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumModules_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumModules_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumModules_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumModules_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumModules_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumModules_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumModules_Next_Proxy( 
    IEnumModules __RPC_FAR * This,
    ULONG celt,
    IModule __RPC_FAR *__RPC_FAR *rgelt,
    ULONG __RPC_FAR *pceltFetched);


void __RPC_STUB IEnumModules_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumModules_Skip_Proxy( 
    IEnumModules __RPC_FAR * This,
    ULONG celt);


void __RPC_STUB IEnumModules_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumModules_Reset_Proxy( 
    IEnumModules __RPC_FAR * This);


void __RPC_STUB IEnumModules_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumModules_Clone_Proxy( 
    IEnumModules __RPC_FAR * This,
    IEnumModules __RPC_FAR *__RPC_FAR *ppenum);


void __RPC_STUB IEnumModules_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumModules_INTERFACE_DEFINED__ */


#ifndef __IDisSymMgr_INTERFACE_DEFINED__
#define __IDisSymMgr_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IDisSymMgr
 * at Sun May 24 08:36:22 1998
 * using MIDL 3.00.44
 ****************************************/
/* [object][uuid] */ 



EXTERN_C const IID IID_IDisSymMgr;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IDisSymMgr : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateNew( 
            /* [in] */ OLECHAR __RPC_FAR *Path) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OpenExisting( 
            /* [in] */ OLECHAR __RPC_FAR *Path) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Extract( 
            /* [in] */ IDisImg __RPC_FAR *Image) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddType( 
            /* [out] */ IType __RPC_FAR *__RPC_FAR *ppType,
            /* [in] */ TYPE_INFO __RPC_FAR *TypeInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTypeByName( 
            /* [out] */ IType __RPC_FAR *__RPC_FAR *ppType,
            /* [in] */ BSTR Name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTypeByHandle( 
            /* [out] */ IType __RPC_FAR *__RPC_FAR *pIType,
            /* [in] */ HTYPE Type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTypeHandle( 
            /* [out] */ HTYPE __RPC_FAR *Handle,
            /* [in] */ IType __RPC_FAR *pIType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CloseTypeHandle( 
            /* [in] */ HTYPE Handle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumTypes( 
            /* [out] */ IEnumTypes __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddSymbol( 
            /* [out] */ ISymbol __RPC_FAR *__RPC_FAR *ppISymbol,
            /* [in] */ SYMBOL_INFO __RPC_FAR *SymbolInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSymbolByName( 
            /* [out] */ ISymbol __RPC_FAR *__RPC_FAR *ppIUnknown,
            /* [in] */ BSTR Name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSymbolByAddress( 
            /* [out] */ ISymbol __RPC_FAR *__RPC_FAR *ppIUnknown,
            /* [in] */ DWORD Address) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumSymbols( 
            /* [out] */ IEnumSymbols __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddModule( 
            /* [out] */ IModule __RPC_FAR *__RPC_FAR *ppIModule,
            /* [in] */ MODULE_INFO __RPC_FAR *ModuleInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetModuleByName( 
            /* [out] */ IModule __RPC_FAR *__RPC_FAR *ppIModule,
            /* [in] */ BSTR Name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetModuleByAddress( 
            /* [out] */ IModule __RPC_FAR *__RPC_FAR *ppIModule,
            /* [in] */ DWORD Address) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumModules( 
            /* [out] */ IEnumModules __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDisSymMgrVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDisSymMgr __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDisSymMgr __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDisSymMgr __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateNew )( 
            IDisSymMgr __RPC_FAR * This,
            /* [in] */ OLECHAR __RPC_FAR *Path);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenExisting )( 
            IDisSymMgr __RPC_FAR * This,
            /* [in] */ OLECHAR __RPC_FAR *Path);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Extract )( 
            IDisSymMgr __RPC_FAR * This,
            /* [in] */ IDisImg __RPC_FAR *Image);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddType )( 
            IDisSymMgr __RPC_FAR * This,
            /* [out] */ IType __RPC_FAR *__RPC_FAR *ppType,
            /* [in] */ TYPE_INFO __RPC_FAR *TypeInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeByName )( 
            IDisSymMgr __RPC_FAR * This,
            /* [out] */ IType __RPC_FAR *__RPC_FAR *ppType,
            /* [in] */ BSTR Name);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeByHandle )( 
            IDisSymMgr __RPC_FAR * This,
            /* [out] */ IType __RPC_FAR *__RPC_FAR *pIType,
            /* [in] */ HTYPE Type);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeHandle )( 
            IDisSymMgr __RPC_FAR * This,
            /* [out] */ HTYPE __RPC_FAR *Handle,
            /* [in] */ IType __RPC_FAR *pIType);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CloseTypeHandle )( 
            IDisSymMgr __RPC_FAR * This,
            /* [in] */ HTYPE Handle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumTypes )( 
            IDisSymMgr __RPC_FAR * This,
            /* [out] */ IEnumTypes __RPC_FAR *__RPC_FAR *ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddSymbol )( 
            IDisSymMgr __RPC_FAR * This,
            /* [out] */ ISymbol __RPC_FAR *__RPC_FAR *ppISymbol,
            /* [in] */ SYMBOL_INFO __RPC_FAR *SymbolInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSymbolByName )( 
            IDisSymMgr __RPC_FAR * This,
            /* [out] */ ISymbol __RPC_FAR *__RPC_FAR *ppIUnknown,
            /* [in] */ BSTR Name);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSymbolByAddress )( 
            IDisSymMgr __RPC_FAR * This,
            /* [out] */ ISymbol __RPC_FAR *__RPC_FAR *ppIUnknown,
            /* [in] */ DWORD Address);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumSymbols )( 
            IDisSymMgr __RPC_FAR * This,
            /* [out] */ IEnumSymbols __RPC_FAR *__RPC_FAR *ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddModule )( 
            IDisSymMgr __RPC_FAR * This,
            /* [out] */ IModule __RPC_FAR *__RPC_FAR *ppIModule,
            /* [in] */ MODULE_INFO __RPC_FAR *ModuleInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetModuleByName )( 
            IDisSymMgr __RPC_FAR * This,
            /* [out] */ IModule __RPC_FAR *__RPC_FAR *ppIModule,
            /* [in] */ BSTR Name);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetModuleByAddress )( 
            IDisSymMgr __RPC_FAR * This,
            /* [out] */ IModule __RPC_FAR *__RPC_FAR *ppIModule,
            /* [in] */ DWORD Address);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumModules )( 
            IDisSymMgr __RPC_FAR * This,
            /* [out] */ IEnumModules __RPC_FAR *__RPC_FAR *ppEnum);
        
        END_INTERFACE
    } IDisSymMgrVtbl;

    interface IDisSymMgr
    {
        CONST_VTBL struct IDisSymMgrVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDisSymMgr_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDisSymMgr_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDisSymMgr_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDisSymMgr_CreateNew(This,Path)	\
    (This)->lpVtbl -> CreateNew(This,Path)

#define IDisSymMgr_OpenExisting(This,Path)	\
    (This)->lpVtbl -> OpenExisting(This,Path)

#define IDisSymMgr_Extract(This,Image)	\
    (This)->lpVtbl -> Extract(This,Image)

#define IDisSymMgr_AddType(This,ppType,TypeInfo)	\
    (This)->lpVtbl -> AddType(This,ppType,TypeInfo)

#define IDisSymMgr_GetTypeByName(This,ppType,Name)	\
    (This)->lpVtbl -> GetTypeByName(This,ppType,Name)

#define IDisSymMgr_GetTypeByHandle(This,pIType,Type)	\
    (This)->lpVtbl -> GetTypeByHandle(This,pIType,Type)

#define IDisSymMgr_GetTypeHandle(This,Handle,pIType)	\
    (This)->lpVtbl -> GetTypeHandle(This,Handle,pIType)

#define IDisSymMgr_CloseTypeHandle(This,Handle)	\
    (This)->lpVtbl -> CloseTypeHandle(This,Handle)

#define IDisSymMgr_EnumTypes(This,ppEnum)	\
    (This)->lpVtbl -> EnumTypes(This,ppEnum)

#define IDisSymMgr_AddSymbol(This,ppISymbol,SymbolInfo)	\
    (This)->lpVtbl -> AddSymbol(This,ppISymbol,SymbolInfo)

#define IDisSymMgr_GetSymbolByName(This,ppIUnknown,Name)	\
    (This)->lpVtbl -> GetSymbolByName(This,ppIUnknown,Name)

#define IDisSymMgr_GetSymbolByAddress(This,ppIUnknown,Address)	\
    (This)->lpVtbl -> GetSymbolByAddress(This,ppIUnknown,Address)

#define IDisSymMgr_EnumSymbols(This,ppEnum)	\
    (This)->lpVtbl -> EnumSymbols(This,ppEnum)

#define IDisSymMgr_AddModule(This,ppIModule,ModuleInfo)	\
    (This)->lpVtbl -> AddModule(This,ppIModule,ModuleInfo)

#define IDisSymMgr_GetModuleByName(This,ppIModule,Name)	\
    (This)->lpVtbl -> GetModuleByName(This,ppIModule,Name)

#define IDisSymMgr_GetModuleByAddress(This,ppIModule,Address)	\
    (This)->lpVtbl -> GetModuleByAddress(This,ppIModule,Address)

#define IDisSymMgr_EnumModules(This,ppEnum)	\
    (This)->lpVtbl -> EnumModules(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IDisSymMgr_CreateNew_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [in] */ OLECHAR __RPC_FAR *Path);


void __RPC_STUB IDisSymMgr_CreateNew_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisSymMgr_OpenExisting_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [in] */ OLECHAR __RPC_FAR *Path);


void __RPC_STUB IDisSymMgr_OpenExisting_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisSymMgr_Extract_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [in] */ IDisImg __RPC_FAR *Image);


void __RPC_STUB IDisSymMgr_Extract_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisSymMgr_AddType_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [out] */ IType __RPC_FAR *__RPC_FAR *ppType,
    /* [in] */ TYPE_INFO __RPC_FAR *TypeInfo);


void __RPC_STUB IDisSymMgr_AddType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisSymMgr_GetTypeByName_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [out] */ IType __RPC_FAR *__RPC_FAR *ppType,
    /* [in] */ BSTR Name);


void __RPC_STUB IDisSymMgr_GetTypeByName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisSymMgr_GetTypeByHandle_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [out] */ IType __RPC_FAR *__RPC_FAR *pIType,
    /* [in] */ HTYPE Type);


void __RPC_STUB IDisSymMgr_GetTypeByHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisSymMgr_GetTypeHandle_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [out] */ HTYPE __RPC_FAR *Handle,
    /* [in] */ IType __RPC_FAR *pIType);


void __RPC_STUB IDisSymMgr_GetTypeHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisSymMgr_CloseTypeHandle_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [in] */ HTYPE Handle);


void __RPC_STUB IDisSymMgr_CloseTypeHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisSymMgr_EnumTypes_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [out] */ IEnumTypes __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IDisSymMgr_EnumTypes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisSymMgr_AddSymbol_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [out] */ ISymbol __RPC_FAR *__RPC_FAR *ppISymbol,
    /* [in] */ SYMBOL_INFO __RPC_FAR *SymbolInfo);


void __RPC_STUB IDisSymMgr_AddSymbol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisSymMgr_GetSymbolByName_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [out] */ ISymbol __RPC_FAR *__RPC_FAR *ppIUnknown,
    /* [in] */ BSTR Name);


void __RPC_STUB IDisSymMgr_GetSymbolByName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisSymMgr_GetSymbolByAddress_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [out] */ ISymbol __RPC_FAR *__RPC_FAR *ppIUnknown,
    /* [in] */ DWORD Address);


void __RPC_STUB IDisSymMgr_GetSymbolByAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisSymMgr_EnumSymbols_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [out] */ IEnumSymbols __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IDisSymMgr_EnumSymbols_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisSymMgr_AddModule_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [out] */ IModule __RPC_FAR *__RPC_FAR *ppIModule,
    /* [in] */ MODULE_INFO __RPC_FAR *ModuleInfo);


void __RPC_STUB IDisSymMgr_AddModule_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisSymMgr_GetModuleByName_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [out] */ IModule __RPC_FAR *__RPC_FAR *ppIModule,
    /* [in] */ BSTR Name);


void __RPC_STUB IDisSymMgr_GetModuleByName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisSymMgr_GetModuleByAddress_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [out] */ IModule __RPC_FAR *__RPC_FAR *ppIModule,
    /* [in] */ DWORD Address);


void __RPC_STUB IDisSymMgr_GetModuleByAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisSymMgr_EnumModules_Proxy( 
    IDisSymMgr __RPC_FAR * This,
    /* [out] */ IEnumModules __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IDisSymMgr_EnumModules_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDisSymMgr_INTERFACE_DEFINED__ */


#ifndef __IDisSmX_INTERFACE_DEFINED__
#define __IDisSmX_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IDisSmX
 * at Sun May 24 08:36:22 1998
 * using MIDL 3.00.44
 ****************************************/
/* [object][uuid] */ 



EXTERN_C const IID IID_IDisSmX;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IDisSmX : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Extract( 
            IDisImg __RPC_FAR *Image,
            IDisSymMgr __RPC_FAR *SymbolManager) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDisSmXVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDisSmX __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDisSmX __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDisSmX __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Extract )( 
            IDisSmX __RPC_FAR * This,
            IDisImg __RPC_FAR *Image,
            IDisSymMgr __RPC_FAR *SymbolManager);
        
        END_INTERFACE
    } IDisSmXVtbl;

    interface IDisSmX
    {
        CONST_VTBL struct IDisSmXVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDisSmX_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDisSmX_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDisSmX_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDisSmX_Extract(This,Image,SymbolManager)	\
    (This)->lpVtbl -> Extract(This,Image,SymbolManager)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IDisSmX_Extract_Proxy( 
    IDisSmX __RPC_FAR * This,
    IDisImg __RPC_FAR *Image,
    IDisSymMgr __RPC_FAR *SymbolManager);


void __RPC_STUB IDisSmX_Extract_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDisSmX_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0155
 * at Sun May 24 08:36:22 1998
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


typedef 
enum tagFUNCDESC_FIELDS
    {	FUNCDESC_FIELD_MEMID	= 0x1,
	FUNCDESC_FIELD_LPRGSCODE	= 0x2,
	FUNCDESC_FIELD_LPRGELEMDESCPARAM	= 0x4,
	FUNCDESC_FIELD_FUNCKIND	= 0x8,
	FUNCDESC_FIELD_INVKIND	= 0x10,
	FUNCDESC_FIELD_CALLCONV	= 0x20,
	FUNCDESC_FIELD_PARAMS	= 0x40,
	FUNCDESC_FIELD_PARAMSOPT	= 0x80,
	FUNCDESC_FIELD_OVFT	= 0x100,
	FUNCDESC_FIELD_SCODES	= 0x200,
	FUNCDESC_FIELD_ELEMDESCFUNC	= 0x400,
	FUNCDESC_FIELD_FUNCFLAGS	= 0x800
    }	FUNCDESC_FIELDS;



extern RPC_IF_HANDLE __MIDL__intf_0155_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0155_v0_0_s_ifspec;

#ifndef __IDisFunction_INTERFACE_DEFINED__
#define __IDisFunction_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IDisFunction
 * at Sun May 24 08:36:22 1998
 * using MIDL 3.00.44
 ****************************************/
/* [object][uuid] */ 



EXTERN_C const IID IID_IDisFunction;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IDisFunction : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetBasicInfo( 
            /* [out] */ BSTR __RPC_FAR *pbsName,
            /* [out] */ DWORD __RPC_FAR *pdwAddr,
            /* [out] */ DWORD __RPC_FAR *pdwLen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFUNCDESC( 
            /* [out] */ FUNCDESC __RPC_FAR *pFd,
            /* [out] */ FUNCDESC_FIELDS __RPC_FAR *pValidFields) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseFUNCDESC( 
            /* [in] */ FUNCDESC __RPC_FAR *pFd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConfidence( 
            /* [in] */ FUNCDESC_FIELDS SingleField,
            /* [out] */ CONFIDENCE __RPC_FAR *pConfidence) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetConfidence( 
            /* [in] */ FUNCDESC_FIELDS FieldList,
            /* [in] */ CONFIDENCE NewConfidence) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDisFunctionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDisFunction __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDisFunction __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDisFunction __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBasicInfo )( 
            IDisFunction __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbsName,
            /* [out] */ DWORD __RPC_FAR *pdwAddr,
            /* [out] */ DWORD __RPC_FAR *pdwLen);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFUNCDESC )( 
            IDisFunction __RPC_FAR * This,
            /* [out] */ FUNCDESC __RPC_FAR *pFd,
            /* [out] */ FUNCDESC_FIELDS __RPC_FAR *pValidFields);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReleaseFUNCDESC )( 
            IDisFunction __RPC_FAR * This,
            /* [in] */ FUNCDESC __RPC_FAR *pFd);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetConfidence )( 
            IDisFunction __RPC_FAR * This,
            /* [in] */ FUNCDESC_FIELDS SingleField,
            /* [out] */ CONFIDENCE __RPC_FAR *pConfidence);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetConfidence )( 
            IDisFunction __RPC_FAR * This,
            /* [in] */ FUNCDESC_FIELDS FieldList,
            /* [in] */ CONFIDENCE NewConfidence);
        
        END_INTERFACE
    } IDisFunctionVtbl;

    interface IDisFunction
    {
        CONST_VTBL struct IDisFunctionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDisFunction_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDisFunction_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDisFunction_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDisFunction_GetBasicInfo(This,pbsName,pdwAddr,pdwLen)	\
    (This)->lpVtbl -> GetBasicInfo(This,pbsName,pdwAddr,pdwLen)

#define IDisFunction_GetFUNCDESC(This,pFd,pValidFields)	\
    (This)->lpVtbl -> GetFUNCDESC(This,pFd,pValidFields)

#define IDisFunction_ReleaseFUNCDESC(This,pFd)	\
    (This)->lpVtbl -> ReleaseFUNCDESC(This,pFd)

#define IDisFunction_GetConfidence(This,SingleField,pConfidence)	\
    (This)->lpVtbl -> GetConfidence(This,SingleField,pConfidence)

#define IDisFunction_SetConfidence(This,FieldList,NewConfidence)	\
    (This)->lpVtbl -> SetConfidence(This,FieldList,NewConfidence)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IDisFunction_GetBasicInfo_Proxy( 
    IDisFunction __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbsName,
    /* [out] */ DWORD __RPC_FAR *pdwAddr,
    /* [out] */ DWORD __RPC_FAR *pdwLen);


void __RPC_STUB IDisFunction_GetBasicInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisFunction_GetFUNCDESC_Proxy( 
    IDisFunction __RPC_FAR * This,
    /* [out] */ FUNCDESC __RPC_FAR *pFd,
    /* [out] */ FUNCDESC_FIELDS __RPC_FAR *pValidFields);


void __RPC_STUB IDisFunction_GetFUNCDESC_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisFunction_ReleaseFUNCDESC_Proxy( 
    IDisFunction __RPC_FAR * This,
    /* [in] */ FUNCDESC __RPC_FAR *pFd);


void __RPC_STUB IDisFunction_ReleaseFUNCDESC_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisFunction_GetConfidence_Proxy( 
    IDisFunction __RPC_FAR * This,
    /* [in] */ FUNCDESC_FIELDS SingleField,
    /* [out] */ CONFIDENCE __RPC_FAR *pConfidence);


void __RPC_STUB IDisFunction_GetConfidence_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisFunction_SetConfidence_Proxy( 
    IDisFunction __RPC_FAR * This,
    /* [in] */ FUNCDESC_FIELDS FieldList,
    /* [in] */ CONFIDENCE NewConfidence);


void __RPC_STUB IDisFunction_SetConfidence_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDisFunction_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long __RPC_FAR *, unsigned long            , VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long __RPC_FAR *, VARIANT __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
