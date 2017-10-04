/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun May 17 20:59:29 1998
 */
/* Compiler settings for ldr.idl:
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

#ifndef __ldr_h__
#define __ldr_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IEnumImages_FWD_DEFINED__
#define __IEnumImages_FWD_DEFINED__
typedef interface IEnumImages IEnumImages;
#endif 	/* __IEnumImages_FWD_DEFINED__ */


#ifndef __IDisLdr_FWD_DEFINED__
#define __IDisLdr_FWD_DEFINED__
typedef interface IDisLdr IDisLdr;
#endif 	/* __IDisLdr_FWD_DEFINED__ */


#ifndef __IDisEnumImports_FWD_DEFINED__
#define __IDisEnumImports_FWD_DEFINED__
typedef interface IDisEnumImports IDisEnumImports;
#endif 	/* __IDisEnumImports_FWD_DEFINED__ */


#ifndef __IDisEnumExports_FWD_DEFINED__
#define __IDisEnumExports_FWD_DEFINED__
typedef interface IDisEnumExports IDisEnumExports;
#endif 	/* __IDisEnumExports_FWD_DEFINED__ */


#ifndef __IEnumSections_FWD_DEFINED__
#define __IEnumSections_FWD_DEFINED__
typedef interface IEnumSections IEnumSections;
#endif 	/* __IEnumSections_FWD_DEFINED__ */


#ifndef __IDisImg_FWD_DEFINED__
#define __IDisImg_FWD_DEFINED__
typedef interface IDisImg IDisImg;
#endif 	/* __IDisImg_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL__intf_0000
 * at Sun May 17 20:59:29 1998
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 






extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_s_ifspec;

#ifndef __IEnumImages_INTERFACE_DEFINED__
#define __IEnumImages_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumImages
 * at Sun May 17 20:59:29 1998
 * using MIDL 3.00.44
 ****************************************/
/* [object][uuid] */ 



EXTERN_C const IID IID_IEnumImages;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IEnumImages : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            ULONG celt,
            IDisImg __RPC_FAR *__RPC_FAR *rgelt,
            ULONG __RPC_FAR *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            IEnumImages __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumImagesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEnumImages __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEnumImages __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEnumImages __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IEnumImages __RPC_FAR * This,
            ULONG celt,
            IDisImg __RPC_FAR *__RPC_FAR *rgelt,
            ULONG __RPC_FAR *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IEnumImages __RPC_FAR * This,
            ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IEnumImages __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IEnumImages __RPC_FAR * This,
            IEnumImages __RPC_FAR *__RPC_FAR *ppEnum);
        
        END_INTERFACE
    } IEnumImagesVtbl;

    interface IEnumImages
    {
        CONST_VTBL struct IEnumImagesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumImages_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumImages_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumImages_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumImages_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumImages_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumImages_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumImages_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumImages_Next_Proxy( 
    IEnumImages __RPC_FAR * This,
    ULONG celt,
    IDisImg __RPC_FAR *__RPC_FAR *rgelt,
    ULONG __RPC_FAR *pceltFetched);


void __RPC_STUB IEnumImages_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumImages_Skip_Proxy( 
    IEnumImages __RPC_FAR * This,
    ULONG celt);


void __RPC_STUB IEnumImages_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumImages_Reset_Proxy( 
    IEnumImages __RPC_FAR * This);


void __RPC_STUB IEnumImages_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumImages_Clone_Proxy( 
    IEnumImages __RPC_FAR * This,
    IEnumImages __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IEnumImages_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumImages_INTERFACE_DEFINED__ */


#ifndef __IDisLdr_INTERFACE_DEFINED__
#define __IDisLdr_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IDisLdr
 * at Sun May 17 20:59:29 1998
 * using MIDL 3.00.44
 ****************************************/
/* [object][uuid] */ 



EXTERN_C const IID IID_IDisLdr;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IDisLdr : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ BSTR bstrFile,
            /* [out] */ IDisImg __RPC_FAR *__RPC_FAR *ppImage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumImages( 
            IEnumImages __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConvertVirtualAddressToPtr( 
            /* [in] */ DWORD VirtualAddress,
            /* [out] */ DWORD __RPC_FAR *Pointer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDisLdrVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDisLdr __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDisLdr __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDisLdr __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Load )( 
            IDisLdr __RPC_FAR * This,
            /* [in] */ BSTR bstrFile,
            /* [out] */ IDisImg __RPC_FAR *__RPC_FAR *ppImage);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumImages )( 
            IDisLdr __RPC_FAR * This,
            IEnumImages __RPC_FAR *__RPC_FAR *ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConvertVirtualAddressToPtr )( 
            IDisLdr __RPC_FAR * This,
            /* [in] */ DWORD VirtualAddress,
            /* [out] */ DWORD __RPC_FAR *Pointer);
        
        END_INTERFACE
    } IDisLdrVtbl;

    interface IDisLdr
    {
        CONST_VTBL struct IDisLdrVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDisLdr_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDisLdr_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDisLdr_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDisLdr_Load(This,bstrFile,ppImage)	\
    (This)->lpVtbl -> Load(This,bstrFile,ppImage)

#define IDisLdr_EnumImages(This,ppEnum)	\
    (This)->lpVtbl -> EnumImages(This,ppEnum)

#define IDisLdr_ConvertVirtualAddressToPtr(This,VirtualAddress,Pointer)	\
    (This)->lpVtbl -> ConvertVirtualAddressToPtr(This,VirtualAddress,Pointer)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IDisLdr_Load_Proxy( 
    IDisLdr __RPC_FAR * This,
    /* [in] */ BSTR bstrFile,
    /* [out] */ IDisImg __RPC_FAR *__RPC_FAR *ppImage);


void __RPC_STUB IDisLdr_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisLdr_EnumImages_Proxy( 
    IDisLdr __RPC_FAR * This,
    IEnumImages __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IDisLdr_EnumImages_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisLdr_ConvertVirtualAddressToPtr_Proxy( 
    IDisLdr __RPC_FAR * This,
    /* [in] */ DWORD VirtualAddress,
    /* [out] */ DWORD __RPC_FAR *Pointer);


void __RPC_STUB IDisLdr_ConvertVirtualAddressToPtr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDisLdr_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0137
 * at Sun May 17 20:59:29 1998
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


typedef struct  tagIMG_IMPORT
    {
    BSTR Module;
    BSTR Name;
    int Ordinal;
    DWORD Address;
    }	IMG_IMPORT;

typedef struct  tagIMG_EXPORT
    {
    BSTR Name;
    DWORD Address;
    }	IMG_EXPORT;



extern RPC_IF_HANDLE __MIDL__intf_0137_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0137_v0_0_s_ifspec;

#ifndef __IDisEnumImports_INTERFACE_DEFINED__
#define __IDisEnumImports_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IDisEnumImports
 * at Sun May 17 20:59:29 1998
 * using MIDL 3.00.44
 ****************************************/
/* [object][uuid] */ 



EXTERN_C const IID IID_IDisEnumImports;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IDisEnumImports : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            ULONG celt,
            IMG_IMPORT __RPC_FAR *rgelt,
            ULONG __RPC_FAR *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            IDisEnumImports __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDisEnumImportsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDisEnumImports __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDisEnumImports __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDisEnumImports __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IDisEnumImports __RPC_FAR * This,
            ULONG celt,
            IMG_IMPORT __RPC_FAR *rgelt,
            ULONG __RPC_FAR *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IDisEnumImports __RPC_FAR * This,
            ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IDisEnumImports __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IDisEnumImports __RPC_FAR * This,
            IDisEnumImports __RPC_FAR *__RPC_FAR *ppEnum);
        
        END_INTERFACE
    } IDisEnumImportsVtbl;

    interface IDisEnumImports
    {
        CONST_VTBL struct IDisEnumImportsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDisEnumImports_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDisEnumImports_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDisEnumImports_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDisEnumImports_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IDisEnumImports_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IDisEnumImports_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IDisEnumImports_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IDisEnumImports_Next_Proxy( 
    IDisEnumImports __RPC_FAR * This,
    ULONG celt,
    IMG_IMPORT __RPC_FAR *rgelt,
    ULONG __RPC_FAR *pceltFetched);


void __RPC_STUB IDisEnumImports_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisEnumImports_Skip_Proxy( 
    IDisEnumImports __RPC_FAR * This,
    ULONG celt);


void __RPC_STUB IDisEnumImports_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisEnumImports_Reset_Proxy( 
    IDisEnumImports __RPC_FAR * This);


void __RPC_STUB IDisEnumImports_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisEnumImports_Clone_Proxy( 
    IDisEnumImports __RPC_FAR * This,
    IDisEnumImports __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IDisEnumImports_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDisEnumImports_INTERFACE_DEFINED__ */


#ifndef __IDisEnumExports_INTERFACE_DEFINED__
#define __IDisEnumExports_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IDisEnumExports
 * at Sun May 17 20:59:29 1998
 * using MIDL 3.00.44
 ****************************************/
/* [object][uuid] */ 



EXTERN_C const IID IID_IDisEnumExports;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IDisEnumExports : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            ULONG celt,
            IMG_EXPORT __RPC_FAR *rgelt,
            ULONG __RPC_FAR *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            IDisEnumExports __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDisEnumExportsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDisEnumExports __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDisEnumExports __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDisEnumExports __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IDisEnumExports __RPC_FAR * This,
            ULONG celt,
            IMG_EXPORT __RPC_FAR *rgelt,
            ULONG __RPC_FAR *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IDisEnumExports __RPC_FAR * This,
            ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IDisEnumExports __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IDisEnumExports __RPC_FAR * This,
            IDisEnumExports __RPC_FAR *__RPC_FAR *ppEnum);
        
        END_INTERFACE
    } IDisEnumExportsVtbl;

    interface IDisEnumExports
    {
        CONST_VTBL struct IDisEnumExportsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDisEnumExports_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDisEnumExports_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDisEnumExports_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDisEnumExports_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IDisEnumExports_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IDisEnumExports_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IDisEnumExports_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IDisEnumExports_Next_Proxy( 
    IDisEnumExports __RPC_FAR * This,
    ULONG celt,
    IMG_EXPORT __RPC_FAR *rgelt,
    ULONG __RPC_FAR *pceltFetched);


void __RPC_STUB IDisEnumExports_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisEnumExports_Skip_Proxy( 
    IDisEnumExports __RPC_FAR * This,
    ULONG celt);


void __RPC_STUB IDisEnumExports_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisEnumExports_Reset_Proxy( 
    IDisEnumExports __RPC_FAR * This);


void __RPC_STUB IDisEnumExports_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisEnumExports_Clone_Proxy( 
    IDisEnumExports __RPC_FAR * This,
    IDisEnumExports __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IDisEnumExports_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDisEnumExports_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0139
 * at Sun May 17 20:59:29 1998
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


typedef 
enum tagIMG_SECTION_TYPE
    {	IMG_SECTION_CODE	= 0,
	IMG_SECTION_DATA	= IMG_SECTION_CODE + 1
    }	IMG_SECTION_TYPE;

typedef struct  tagIMG_SECTION
    {
    DWORD Address;
    DWORD Size;
    IMG_SECTION_TYPE Type;
    }	IMG_SECTION;



extern RPC_IF_HANDLE __MIDL__intf_0139_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0139_v0_0_s_ifspec;

#ifndef __IEnumSections_INTERFACE_DEFINED__
#define __IEnumSections_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumSections
 * at Sun May 17 20:59:29 1998
 * using MIDL 3.00.44
 ****************************************/
/* [object][uuid] */ 



EXTERN_C const IID IID_IEnumSections;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IEnumSections : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            ULONG celt,
            IMG_SECTION __RPC_FAR *rgelt,
            ULONG __RPC_FAR *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            IEnumSections __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumSectionsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEnumSections __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEnumSections __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEnumSections __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IEnumSections __RPC_FAR * This,
            ULONG celt,
            IMG_SECTION __RPC_FAR *rgelt,
            ULONG __RPC_FAR *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IEnumSections __RPC_FAR * This,
            ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IEnumSections __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IEnumSections __RPC_FAR * This,
            IEnumSections __RPC_FAR *__RPC_FAR *ppEnum);
        
        END_INTERFACE
    } IEnumSectionsVtbl;

    interface IEnumSections
    {
        CONST_VTBL struct IEnumSectionsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumSections_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumSections_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumSections_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumSections_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumSections_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumSections_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumSections_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumSections_Next_Proxy( 
    IEnumSections __RPC_FAR * This,
    ULONG celt,
    IMG_SECTION __RPC_FAR *rgelt,
    ULONG __RPC_FAR *pceltFetched);


void __RPC_STUB IEnumSections_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumSections_Skip_Proxy( 
    IEnumSections __RPC_FAR * This,
    ULONG celt);


void __RPC_STUB IEnumSections_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumSections_Reset_Proxy( 
    IEnumSections __RPC_FAR * This);


void __RPC_STUB IEnumSections_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumSections_Clone_Proxy( 
    IEnumSections __RPC_FAR * This,
    IEnumSections __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IEnumSections_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumSections_INTERFACE_DEFINED__ */


#ifndef __IDisImg_INTERFACE_DEFINED__
#define __IDisImg_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IDisImg
 * at Sun May 17 20:59:29 1998
 * using MIDL 3.00.44
 ****************************************/
/* [object][uuid] */ 



EXTERN_C const IID IID_IDisImg;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IDisImg : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ BSTR bstrFile) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetImagePath( 
            /* [out] */ BSTR __RPC_FAR *pbsPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConvertRVAToPtr( 
            /* [in] */ DWORD dwRVA,
            /* [out] */ DWORD __RPC_FAR *pdwPtr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConvertVAToPtr( 
            /* [in] */ DWORD dwVA,
            /* [out] */ DWORD __RPC_FAR *pdwPtr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConvertPtrToVA( 
            /* [in] */ DWORD dwPtr,
            /* [out] */ DWORD __RPC_FAR *pdwVA) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEntryPointPtr( 
            /* [out] */ DWORD __RPC_FAR *pdwPtr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPreferredLoadAddress( 
            /* [out] */ DWORD __RPC_FAR *pdwVA) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumImports( 
            IDisEnumImports __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumExports( 
            IDisEnumExports __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumSections( 
            IEnumSections __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDisImgVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDisImg __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDisImg __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDisImg __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Load )( 
            IDisImg __RPC_FAR * This,
            /* [in] */ BSTR bstrFile);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetImagePath )( 
            IDisImg __RPC_FAR * This,
            /* [out] */ BSTR __RPC_FAR *pbsPath);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConvertRVAToPtr )( 
            IDisImg __RPC_FAR * This,
            /* [in] */ DWORD dwRVA,
            /* [out] */ DWORD __RPC_FAR *pdwPtr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConvertVAToPtr )( 
            IDisImg __RPC_FAR * This,
            /* [in] */ DWORD dwVA,
            /* [out] */ DWORD __RPC_FAR *pdwPtr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConvertPtrToVA )( 
            IDisImg __RPC_FAR * This,
            /* [in] */ DWORD dwPtr,
            /* [out] */ DWORD __RPC_FAR *pdwVA);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEntryPointPtr )( 
            IDisImg __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pdwPtr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPreferredLoadAddress )( 
            IDisImg __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pdwVA);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumImports )( 
            IDisImg __RPC_FAR * This,
            IDisEnumImports __RPC_FAR *__RPC_FAR *ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumExports )( 
            IDisImg __RPC_FAR * This,
            IDisEnumExports __RPC_FAR *__RPC_FAR *ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnumSections )( 
            IDisImg __RPC_FAR * This,
            IEnumSections __RPC_FAR *__RPC_FAR *ppEnum);
        
        END_INTERFACE
    } IDisImgVtbl;

    interface IDisImg
    {
        CONST_VTBL struct IDisImgVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDisImg_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDisImg_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDisImg_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDisImg_Load(This,bstrFile)	\
    (This)->lpVtbl -> Load(This,bstrFile)

#define IDisImg_GetImagePath(This,pbsPath)	\
    (This)->lpVtbl -> GetImagePath(This,pbsPath)

#define IDisImg_ConvertRVAToPtr(This,dwRVA,pdwPtr)	\
    (This)->lpVtbl -> ConvertRVAToPtr(This,dwRVA,pdwPtr)

#define IDisImg_ConvertVAToPtr(This,dwVA,pdwPtr)	\
    (This)->lpVtbl -> ConvertVAToPtr(This,dwVA,pdwPtr)

#define IDisImg_ConvertPtrToVA(This,dwPtr,pdwVA)	\
    (This)->lpVtbl -> ConvertPtrToVA(This,dwPtr,pdwVA)

#define IDisImg_GetEntryPointPtr(This,pdwPtr)	\
    (This)->lpVtbl -> GetEntryPointPtr(This,pdwPtr)

#define IDisImg_GetPreferredLoadAddress(This,pdwVA)	\
    (This)->lpVtbl -> GetPreferredLoadAddress(This,pdwVA)

#define IDisImg_EnumImports(This,ppEnum)	\
    (This)->lpVtbl -> EnumImports(This,ppEnum)

#define IDisImg_EnumExports(This,ppEnum)	\
    (This)->lpVtbl -> EnumExports(This,ppEnum)

#define IDisImg_EnumSections(This,ppEnum)	\
    (This)->lpVtbl -> EnumSections(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IDisImg_Load_Proxy( 
    IDisImg __RPC_FAR * This,
    /* [in] */ BSTR bstrFile);


void __RPC_STUB IDisImg_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisImg_GetImagePath_Proxy( 
    IDisImg __RPC_FAR * This,
    /* [out] */ BSTR __RPC_FAR *pbsPath);


void __RPC_STUB IDisImg_GetImagePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisImg_ConvertRVAToPtr_Proxy( 
    IDisImg __RPC_FAR * This,
    /* [in] */ DWORD dwRVA,
    /* [out] */ DWORD __RPC_FAR *pdwPtr);


void __RPC_STUB IDisImg_ConvertRVAToPtr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisImg_ConvertVAToPtr_Proxy( 
    IDisImg __RPC_FAR * This,
    /* [in] */ DWORD dwVA,
    /* [out] */ DWORD __RPC_FAR *pdwPtr);


void __RPC_STUB IDisImg_ConvertVAToPtr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisImg_ConvertPtrToVA_Proxy( 
    IDisImg __RPC_FAR * This,
    /* [in] */ DWORD dwPtr,
    /* [out] */ DWORD __RPC_FAR *pdwVA);


void __RPC_STUB IDisImg_ConvertPtrToVA_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisImg_GetEntryPointPtr_Proxy( 
    IDisImg __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *pdwPtr);


void __RPC_STUB IDisImg_GetEntryPointPtr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisImg_GetPreferredLoadAddress_Proxy( 
    IDisImg __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *pdwVA);


void __RPC_STUB IDisImg_GetPreferredLoadAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisImg_EnumImports_Proxy( 
    IDisImg __RPC_FAR * This,
    IDisEnumImports __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IDisImg_EnumImports_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisImg_EnumExports_Proxy( 
    IDisImg __RPC_FAR * This,
    IDisEnumExports __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IDisImg_EnumExports_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisImg_EnumSections_Proxy( 
    IDisImg __RPC_FAR * This,
    IEnumSections __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IDisImg_EnumSections_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDisImg_INTERFACE_DEFINED__ */


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
