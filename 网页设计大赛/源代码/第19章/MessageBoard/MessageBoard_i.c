

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

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

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IMsgBoardCtl,0xDB6DB533,0x3C1F,0x401A,0xAB,0xF3,0xF0,0x6B,0xED,0x7F,0xD2,0x8E);


MIDL_DEFINE_GUID(IID, LIBID_MessageBoardLib,0x4FA58F85,0x91B3,0x4F15,0x91,0x3D,0xAB,0x51,0xA3,0x3B,0x60,0x4E);


MIDL_DEFINE_GUID(IID, DIID__IMsgBoardCtlEvents,0x8DEBEE1C,0x38AF,0x430A,0xAF,0x3A,0xF7,0xAA,0x1A,0xAD,0x5C,0x2E);


MIDL_DEFINE_GUID(CLSID, CLSID_MsgBoardCtl,0x697BE8C3,0xBD33,0x4F37,0xAB,0x7D,0x9C,0x65,0xB0,0xF9,0x18,0x8D);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

