/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun May 24 08:36:18 1998
 */
/* Compiler settings for dis.idl:
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

#ifndef __dis_h__
#define __dis_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IDisDis_FWD_DEFINED__
#define __IDisDis_FWD_DEFINED__
typedef interface IDisDis IDisDis;
#endif 	/* __IDisDis_FWD_DEFINED__ */


#ifndef __IDisInstruction_FWD_DEFINED__
#define __IDisInstruction_FWD_DEFINED__
typedef interface IDisInstruction IDisInstruction;
#endif 	/* __IDisInstruction_FWD_DEFINED__ */


#ifndef __IEnumInstructions_FWD_DEFINED__
#define __IEnumInstructions_FWD_DEFINED__
typedef interface IEnumInstructions IEnumInstructions;
#endif 	/* __IEnumInstructions_FWD_DEFINED__ */


/* header files for imported files */
#include "dissect.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL__intf_0000
 * at Sun May 24 08:36:18 1998
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


typedef /* [public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public] */ struct  __MIDL___MIDL__intf_0000_0001
    {
    DWORD hi;
    DWORD lo;
    }	QWORD;

typedef /* [public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public][public] */ struct  __MIDL___MIDL__intf_0000_0002
    {
    WORD wHi;
    DWORD dwLo;
    }	TWORD;

typedef struct  __HOPCODE_CLASS
    {
    int dummy;
    }	__RPC_FAR *HOPCODE_CLASS;

#define NAMELESS_UNION
typedef 
enum tagSIZE_ATTRIBUTE
    {	SIZE_8	= 8,
	SIZE_BYTE	= SIZE_8,
	SIZE_16	= 16,
	SIZE_WORD	= SIZE_16,
	SIZE_32	= 32,
	SIZE_DWORD	= SIZE_32,
	SIZE_48	= 48,
	SIZE_DESC	= SIZE_48,
	SIZE_TWORD	= SIZE_48,
	SIZE_64	= 64,
	SIZE_QWORD	= SIZE_64,
	SIZE_LAST	= SIZE_QWORD + 1
    }	SIZE_ATTRIBUTE;

typedef 
enum tagOPERAND_CLASS
    {	OPERAND_CLASS_NONE	= 0,
	OPERAND_CLASS_REG	= OPERAND_CLASS_NONE + 1,
	OPERAND_CLASS_REGPAIR	= OPERAND_CLASS_REG + 1,
	OPERAND_CLASS_MEM	= OPERAND_CLASS_REGPAIR + 1,
	OPERAND_CLASS_PORT	= OPERAND_CLASS_MEM + 1,
	OPERAND_CLASS_IMM	= OPERAND_CLASS_PORT + 1,
	OPERAND_CLASS_DIRECT	= OPERAND_CLASS_IMM + 1,
	OPERAND_CLASS_MAX	= OPERAND_CLASS_DIRECT + 1
    }	OPERAND_CLASS;

typedef 
enum tagREG_TYPE
    {	REGTYPE_NONE	= 0,
	REGTYPE_GEN_BYTE	= REGTYPE_NONE + 1,
	REGTYPE_GEN_WORD	= REGTYPE_GEN_BYTE + 1,
	REGTYPE_GEN_DWORD	= REGTYPE_GEN_WORD + 1,
	REGTYPE_GEN_QWORD	= REGTYPE_GEN_DWORD + 1,
	REGTYPE_MMX	= REGTYPE_GEN_QWORD + 1,
	REGTYPE_CONTROL	= REGTYPE_MMX + 1,
	REGTYPE_TEST	= REGTYPE_CONTROL + 1,
	REGTYPE_DEBUG	= REGTYPE_TEST + 1,
	REGTYPE_SEG	= REGTYPE_DEBUG + 1,
	REGTYPE_FLAGS	= REGTYPE_SEG + 1,
	REGTYPE_SYSTEM	= REGTYPE_FLAGS + 1,
	REGTYPE_MAX	= REGTYPE_SYSTEM + 1
    }	REGTYPE;

typedef REGTYPE REG_TYPE;

typedef 
enum tagREG_NUM
    {	REG_NUM_AX	= 0,
	REG_NUM_AL	= 0,
	REG_NUM_ES	= 0,
	REG_NUM_CX	= 1,
	REG_NUM_CL	= 1,
	REG_NUM_CS	= 1,
	REG_NUM_DX	= 2,
	REG_NUM_DL	= 2,
	REG_NUM_SS	= 2,
	REG_NUM_BX	= 3,
	REG_NUM_BL	= 3,
	REG_NUM_DS	= 3,
	REG_NUM_SP	= 4,
	REG_NUM_AH	= 4,
	REG_NUM_FS	= 4,
	REG_NUM_BP	= 5,
	REG_NUM_CH	= 5,
	REG_NUM_GS	= 5,
	REG_NUM_SI	= 6,
	REG_NUM_DH	= 6,
	REG_NUM_DI	= 7,
	REG_NUM_BH	= 7,
	REG_MAX	= REG_NUM_BH + 1
    }	REG_NUM;

typedef struct  tagREG
    {
    REG_TYPE type;
    REG_NUM num;
    }	REG;

typedef BYTE FLAG;

typedef 
enum tagMEMPTR_USE_FLAGS
    {	MEMPTR_USE_SEG	= 0x1,
	MEMPTR_USE_BASE	= 0x2,
	MEMPTR_USE_IDX	= 0x4,
	MEMPTR_USE_SCALE	= 0x8,
	MEMPTR_USE_DISP	= 0x10,
	MEMPTR_USE_DISP8	= 0x10,
	MEMPTR_USE_DISP16	= 0x20,
	MEMPTR_USE_DISP32	= 0x40,
	MEMPTR_USE_DISP64	= 0x80,
	MEMPTR_USE_RES1	= 0x100
    }	MEMPTR_USE_FLAGS;

typedef struct  tagMEMPTR
    {
    SIZE_ATTRIBUTE address_size;
    SIZE_ATTRIBUTE operand_size;
    REG seg;
    REG base;
    REG idx;
    int scale;
    /* [switch_is][switch_type] */ union 
        {
        /* [case()] */ BYTE disp8;
        /* [case()] */ WORD disp16;
        /* [case()] */ DWORD disp32;
        /* [case()] */ QWORD disp64;
        }	NAMELESS_UNION;
    REG res1;
    DWORD mask;
    }	MEMPTR;

typedef struct  tagIOPORT
    {
    WORD port;
    }	IOPORT;

typedef struct  tagIMM
    {
    SIZE_ATTRIBUTE size;
    /* [switch_is] */ /* [switch_type] */ union 
        {
        /* [case()] */ BYTE imm8;
        /* [case()] */ WORD imm16;
        /* [case()] */ DWORD imm32;
        /* [case()] */ QWORD imm64;
        /* [default] */  /* Empty union arm */ 
        }	NAMELESS_UNION;
    }	IMM;

typedef struct  tagDIRECT
    {
    SIZE_ATTRIBUTE size;
    /* [switch_is] */ /* [switch_type] */ union 
        {
        /* [case()] */ WORD direct16;
        /* [case()] */ DWORD direct32;
        /* [case()] */ TWORD direct48;
        /* [case()] */ QWORD direct64;
        /* [default] */  /* Empty union arm */ 
        }	NAMELESS_UNION;
    }	DIRECT;

typedef struct  tagOPERAND
    {
    OPERAND_CLASS cls;
    DWORD flags;
    /* [switch_is][switch_type] */ union 
        {
        /* [case()] */ MEMPTR mem;
        /* [case()] */ REG reg;
        /* [case()] */ REG regpair[ 2 ];
        /* [case()] */ IOPORT port;
        /* [case()] */ IMM imm;
        /* [case()] */ DIRECT direct;
        /* [default] */  /* Empty union arm */ 
        }	NAMELESS_UNION;
    }	OPERAND;

typedef struct  tagINSTRUCTION
    {
    HOPCODE_CLASS hoc;
    unsigned char AnsiName[ 16 ];
    DWORD dwLen;
    DWORD dwVirtualAddress;
    BYTE bytes[ 32 ];
    int cOperands;
    OPERAND op[ 3 ];
    }	INSTRUCTION;

typedef INSTRUCTION __RPC_FAR *PINSTRUCTION;



extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_s_ifspec;

#ifndef __IDisDis_INTERFACE_DEFINED__
#define __IDisDis_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IDisDis
 * at Sun May 24 08:36:18 1998
 * using MIDL 3.00.44
 ****************************************/
/* [object][uuid] */ 



EXTERN_C const IID IID_IDisDis;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IDisDis : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Disasm( 
            /* [in] */ DWORD dwPtr,
            /* [in] */ DWORD dwVA,
            /* [out] */ PINSTRUCTION pInst) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDisDisVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDisDis __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDisDis __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDisDis __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Disasm )( 
            IDisDis __RPC_FAR * This,
            /* [in] */ DWORD dwPtr,
            /* [in] */ DWORD dwVA,
            /* [out] */ PINSTRUCTION pInst);
        
        END_INTERFACE
    } IDisDisVtbl;

    interface IDisDis
    {
        CONST_VTBL struct IDisDisVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDisDis_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDisDis_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDisDis_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDisDis_Disasm(This,dwPtr,dwVA,pInst)	\
    (This)->lpVtbl -> Disasm(This,dwPtr,dwVA,pInst)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IDisDis_Disasm_Proxy( 
    IDisDis __RPC_FAR * This,
    /* [in] */ DWORD dwPtr,
    /* [in] */ DWORD dwVA,
    /* [out] */ PINSTRUCTION pInst);


void __RPC_STUB IDisDis_Disasm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDisDis_INTERFACE_DEFINED__ */


#ifndef __IDisInstruction_INTERFACE_DEFINED__
#define __IDisInstruction_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IDisInstruction
 * at Sun May 24 08:36:18 1998
 * using MIDL 3.00.44
 ****************************************/
/* [object][uuid] */ 



EXTERN_C const IID IID_IDisInstruction;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IDisInstruction : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetINSTRUCTION( 
            /* [out] */ INSTRUCTION __RPC_FAR *pInst) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAnsiClassName( 
            /* [in] */ unsigned char __RPC_FAR *pName,
            /* [in] */ ULONG ulLen) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDisInstructionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDisInstruction __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDisInstruction __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDisInstruction __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetINSTRUCTION )( 
            IDisInstruction __RPC_FAR * This,
            /* [out] */ INSTRUCTION __RPC_FAR *pInst);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAnsiClassName )( 
            IDisInstruction __RPC_FAR * This,
            /* [in] */ unsigned char __RPC_FAR *pName,
            /* [in] */ ULONG ulLen);
        
        END_INTERFACE
    } IDisInstructionVtbl;

    interface IDisInstruction
    {
        CONST_VTBL struct IDisInstructionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDisInstruction_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDisInstruction_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDisInstruction_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDisInstruction_GetINSTRUCTION(This,pInst)	\
    (This)->lpVtbl -> GetINSTRUCTION(This,pInst)

#define IDisInstruction_GetAnsiClassName(This,pName,ulLen)	\
    (This)->lpVtbl -> GetAnsiClassName(This,pName,ulLen)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IDisInstruction_GetINSTRUCTION_Proxy( 
    IDisInstruction __RPC_FAR * This,
    /* [out] */ INSTRUCTION __RPC_FAR *pInst);


void __RPC_STUB IDisInstruction_GetINSTRUCTION_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDisInstruction_GetAnsiClassName_Proxy( 
    IDisInstruction __RPC_FAR * This,
    /* [in] */ unsigned char __RPC_FAR *pName,
    /* [in] */ ULONG ulLen);


void __RPC_STUB IDisInstruction_GetAnsiClassName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDisInstruction_INTERFACE_DEFINED__ */


#ifndef __IEnumInstructions_INTERFACE_DEFINED__
#define __IEnumInstructions_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumInstructions
 * at Sun May 24 08:36:18 1998
 * using MIDL 3.00.44
 ****************************************/
/* [object][uuid] */ 



EXTERN_C const IID IID_IEnumInstructions;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IEnumInstructions : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            ULONG celt,
            INSTRUCTION __RPC_FAR *rgelt,
            ULONG __RPC_FAR *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            IEnumInstructions __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumInstructionsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEnumInstructions __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEnumInstructions __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEnumInstructions __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next )( 
            IEnumInstructions __RPC_FAR * This,
            ULONG celt,
            INSTRUCTION __RPC_FAR *rgelt,
            ULONG __RPC_FAR *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Skip )( 
            IEnumInstructions __RPC_FAR * This,
            ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IEnumInstructions __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clone )( 
            IEnumInstructions __RPC_FAR * This,
            IEnumInstructions __RPC_FAR *__RPC_FAR *ppEnum);
        
        END_INTERFACE
    } IEnumInstructionsVtbl;

    interface IEnumInstructions
    {
        CONST_VTBL struct IEnumInstructionsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumInstructions_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumInstructions_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumInstructions_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumInstructions_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumInstructions_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumInstructions_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumInstructions_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumInstructions_Next_Proxy( 
    IEnumInstructions __RPC_FAR * This,
    ULONG celt,
    INSTRUCTION __RPC_FAR *rgelt,
    ULONG __RPC_FAR *pceltFetched);


void __RPC_STUB IEnumInstructions_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumInstructions_Skip_Proxy( 
    IEnumInstructions __RPC_FAR * This,
    ULONG celt);


void __RPC_STUB IEnumInstructions_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumInstructions_Reset_Proxy( 
    IEnumInstructions __RPC_FAR * This);


void __RPC_STUB IEnumInstructions_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumInstructions_Clone_Proxy( 
    IEnumInstructions __RPC_FAR * This,
    IEnumInstructions __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB IEnumInstructions_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumInstructions_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0141
 * at Sun May 24 08:36:18 1998
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


typedef 
enum tagCTRL_FLOW_TYPE
    {	CTRL_UJMP	= 0,
	CTRL_CJMP	= CTRL_UJMP + 1,
	CTRL_IJMP	= CTRL_CJMP + 1,
	CTRL_CALL	= CTRL_IJMP + 1,
	CTRL_FALL	= CTRL_CALL + 1,
	CTRL_RET	= CTRL_FALL + 1
    }	CTRL_FLOW_TYPE;

typedef struct  tagCTRL_FLOW
    {
    CTRL_FLOW_TYPE Type;
    /* [switch_is] */ /* [switch_type] */ union 
        {
        /* [case()] */ struct  
            {
            DWORD Target;
            }	ujmp;
        /* [case()] */ struct  
            {
            DWORD TrueTarget;
            DWORD FalseTarget;
            FLAG ConditionFlag;
            }	cjmp;
        /* [case()] */ struct  
            {
            DWORD dwReserved;
            }	ijmp;
        /* [case()] */ struct  
            {
            DWORD CallTarget;
            DWORD FallTarget;
            }	call;
        /* [case()] */ struct  
            {
            DWORD FallTarget;
            }	fall;
        /* [case()] */ struct  
            {
            DWORD dwReserved;
            }	ret;
        /* [default] */  /* Empty union arm */ 
        }	NAMELESS_UNION;
    }	CTRL_FLOW;

typedef 
enum tagOPERATION
    {	OP_BEGIN_UNARY	= 0,
	OP_SHL	= OP_BEGIN_UNARY + 1,
	OP_SHR	= OP_SHL + 1,
	OP_END_UNARY	= OP_SHR + 1,
	OP_BEGIN_BINARY	= OP_END_UNARY + 1,
	OP_ADD	= OP_BEGIN_BINARY + 1,
	OP_SUB	= OP_ADD + 1,
	OP_MUL	= OP_SUB + 1,
	OP_DIV	= OP_MUL + 1,
	OP_MOD	= OP_DIV + 1,
	OP_END_BINARY	= OP_MOD + 1,
	OP_COPY	= OP_END_BINARY + 1
    }	OPERATION;

typedef struct  tagUNARY_EXPRESSION
    {
    struct tagEXPRESSION __RPC_FAR *Operand;
    OPERATION Operation;
    }	UNARY_EXPRESSION;

typedef struct  tagBINARY_EXPRESSION
    {
    struct tagEXPRESSION __RPC_FAR *Operand1;
    struct tagEXPRESSION __RPC_FAR *Operand2;
    OPERATION Operation;
    }	BINARY_EXPRESSION;

typedef 
enum tagEXPR_TYPE
    {	EXPR_NULL	= 0,
	EXPR_OPERAND	= EXPR_NULL + 1,
	EXPR_UNARY	= EXPR_OPERAND + 1,
	EXPR_BINARY	= EXPR_UNARY + 1
    }	EXPR_TYPE;

typedef struct  tagEXPRESSION
    {
    EXPR_TYPE Type;
    /* [switch_is] */ /* [switch_type] */ union 
        {
        /* [case()] */ OPERAND Operand;
        /* [case()] */ UNARY_EXPRESSION UnaryExpression;
        /* [case()] */ BINARY_EXPRESSION BinaryExpression;
        /* [default] */  /* Empty union arm */ 
        }	NAMELESS_UNION;
    }	EXPRESSION;

typedef struct  tagASSIGNMENT
    {
    OPERAND Target;
    struct tagEXPRESSION __RPC_FAR *Source;
    }	ASSIGNMENT;

typedef 
enum tagSTATEMENT_TYPE
    {	STATEMENT_TYPE_ASSIGNMENT	= 0,
	STATEMENT_TYPE_CTRL	= STATEMENT_TYPE_ASSIGNMENT + 1,
	STATEMENT_TYPE_COMPOUND	= STATEMENT_TYPE_CTRL + 1
    }	STATEMENT_TYPE;

typedef 
enum tagCOMPOUND_STATEMENT_TYPE
    {	COMPOUND_STATEMENT_TYPE_WHILE	= 0,
	COMPOUND_STATEMENT_TYPE_IF	= COMPOUND_STATEMENT_TYPE_WHILE + 1
    }	COMPOUND_STATEMENT_TYPE;

typedef struct  tagSTATEMENT_LIST
    {
    DWORD NumberOfStatements;
    /* [size_is] */ struct tagSTATEMENT __RPC_FAR *Statements;
    }	STATEMENT_LIST;

typedef struct  tagCOMPOUND_STATEMENT_WHILE
    {
    struct tagEXPRESSION __RPC_FAR *Expr;
    STATEMENT_LIST StatementList;
    }	COMPOUND_STATEMENT_WHILE;

typedef struct  tagCOMPOUND_STATEMENT_IF
    {
    struct tagEXPRESSION __RPC_FAR *Expr;
    STATEMENT_LIST StatementList;
    }	COMPOUND_STATEMENT_IF;

typedef struct  tagCOMPOUND_STATEMENT
    {
    COMPOUND_STATEMENT_TYPE Type;
    /* [switch_is] */ /* [switch_type] */ union 
        {
        /* [case()] */ COMPOUND_STATEMENT_WHILE While;
        /* [case()] */ COMPOUND_STATEMENT_IF If;
        /* [default] */  /* Empty union arm */ 
        }	NAMELESS_UNION;
    }	COMPOUND_STATEMENT;

typedef struct  tagSTATEMENT
    {
    STATEMENT_TYPE Type;
    /* [switch_is] */ /* [switch_type] */ union 
        {
        /* [case()] */ ASSIGNMENT Assignment;
        /* [case()] */ CTRL_FLOW Flow;
        /* [case()] */ COMPOUND_STATEMENT Compound;
        /* [default] */  /* Empty union arm */ 
        }	NAMELESS_UNION;
    }	STATEMENT;

typedef struct  tagSIMPLE_ASSIGNMENT
    {
    OPERATION Operation;
    OPERAND Destination;
    OPERAND Source[ 2 ];
    }	SIMPLE_ASSIGNMENT;

typedef struct  tagQUAD
    {
    STATEMENT_TYPE Type;
    /* [switch_is] */ /* [switch_type] */ union 
        {
        /* [case()] */ SIMPLE_ASSIGNMENT Assignment;
        /* [case()] */ CTRL_FLOW Flow;
        /* [default] */  /* Empty union arm */ 
        }	NAMELESS_UNION;
    }	QUAD;

typedef struct  tagREGISTER_BANK_SPEC
    {
    BYTE RegisterSize;
    BYTE NumberOfRegisters;
    /* [size_is] */ OLECHAR __RPC_FAR *RegisterNames[ 1 ];
    }	REGISTER_BANK_SPEC;

typedef struct  tagREGISTER
    {
    BYTE Bank;
    BYTE Index;
    }	REGISTER;

typedef struct  tagREGDEF
    {
    REGISTER Register;
    BYTE Mask;
    }	REGDEF;

typedef struct tagREGDEF REGUSE;

typedef struct  tagMACHINE_SPEC
    {
    BYTE NumberOfRegisterBanks;
    /* [size_is] */ REGISTER_BANK_SPEC __RPC_FAR *RegisterBanks;
    REGISTER StackPointer;
    BYTE NumberOfFlags;
    /* [size_is] */ OLECHAR __RPC_FAR *__RPC_FAR *FlagNames;
    }	MACHINE_SPEC;



extern RPC_IF_HANDLE __MIDL__intf_0141_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0141_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
