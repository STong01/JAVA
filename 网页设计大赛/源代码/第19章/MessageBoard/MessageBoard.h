

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Sat Aug 16 19:54:18 2008
 */
/* Compiler settings for .\MessageBoard.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __MessageBoard_h__
#define __MessageBoard_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMsgBoardCtl_FWD_DEFINED__
#define __IMsgBoardCtl_FWD_DEFINED__
typedef interface IMsgBoardCtl IMsgBoardCtl;
#endif 	/* __IMsgBoardCtl_FWD_DEFINED__ */


#ifndef ___IMsgBoardCtlEvents_FWD_DEFINED__
#define ___IMsgBoardCtlEvents_FWD_DEFINED__
typedef interface _IMsgBoardCtlEvents _IMsgBoardCtlEvents;
#endif 	/* ___IMsgBoardCtlEvents_FWD_DEFINED__ */


#ifndef __MsgBoardCtl_FWD_DEFINED__
#define __MsgBoardCtl_FWD_DEFINED__

#ifdef __cplusplus
typedef class MsgBoardCtl MsgBoardCtl;
#else
typedef struct MsgBoardCtl MsgBoardCtl;
#endif /* __cplusplus */

#endif 	/* __MsgBoardCtl_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IMsgBoardCtl_INTERFACE_DEFINED__
#define __IMsgBoardCtl_INTERFACE_DEFINED__

/* interface IMsgBoardCtl */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMsgBoardCtl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DB6DB533-3C1F-401A-ABF3-F06BED7FD28E")
    IMsgBoardCtl : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_msgText( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_msgText( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMsgBoardCtlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMsgBoardCtl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMsgBoardCtl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMsgBoardCtl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMsgBoardCtl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMsgBoardCtl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMsgBoardCtl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMsgBoardCtl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_msgText )( 
            IMsgBoardCtl * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_msgText )( 
            IMsgBoardCtl * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IMsgBoardCtlVtbl;

    interface IMsgBoardCtl
    {
        CONST_VTBL struct IMsgBoardCtlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMsgBoardCtl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMsgBoardCtl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMsgBoardCtl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMsgBoardCtl_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IMsgBoardCtl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IMsgBoardCtl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IMsgBoardCtl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IMsgBoardCtl_get_msgText(This,pVal)	\
    (This)->lpVtbl -> get_msgText(This,pVal)

#define IMsgBoardCtl_put_msgText(This,newVal)	\
    (This)->lpVtbl -> put_msgText(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMsgBoardCtl_get_msgText_Proxy( 
    IMsgBoardCtl * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IMsgBoardCtl_get_msgText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMsgBoardCtl_put_msgText_Proxy( 
    IMsgBoardCtl * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IMsgBoardCtl_put_msgText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMsgBoardCtl_INTERFACE_DEFINED__ */



#ifndef __MessageBoardLib_LIBRARY_DEFINED__
#define __MessageBoardLib_LIBRARY_DEFINED__

/* library MessageBoardLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_MessageBoardLib;

#ifndef ___IMsgBoardCtlEvents_DISPINTERFACE_DEFINED__
#define ___IMsgBoardCtlEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IMsgBoardCtlEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IMsgBoardCtlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("8DEBEE1C-38AF-430A-AF3A-F7AA1AAD5C2E")
    _IMsgBoardCtlEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IMsgBoardCtlEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IMsgBoardCtlEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IMsgBoardCtlEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IMsgBoardCtlEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IMsgBoardCtlEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IMsgBoardCtlEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IMsgBoardCtlEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IMsgBoardCtlEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IMsgBoardCtlEventsVtbl;

    interface _IMsgBoardCtlEvents
    {
        CONST_VTBL struct _IMsgBoardCtlEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IMsgBoardCtlEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IMsgBoardCtlEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IMsgBoardCtlEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IMsgBoardCtlEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IMsgBoardCtlEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IMsgBoardCtlEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IMsgBoardCtlEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IMsgBoardCtlEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MsgBoardCtl;

#ifdef __cplusplus

class DECLSPEC_UUID("697BE8C3-BD33-4F37-AB7D-9C65B0F9188D")
MsgBoardCtl;
#endif
#endif /* __MessageBoardLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


