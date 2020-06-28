// MsgBoardCtl.h : CMsgBoardCtl 的声明
#pragma once
#include "resource.h"       // 主符号
#include "MessageBoard.h"
#include "_IMsgBoardCtlEvents_CP.h"
#include <atlctl.h>
#include <comutil.h>							// 添加的：COM实用工具头文件
using namespace _com_util;						// 添加的：使用“_com_util”名字空间
#pragma comment( lib, "comsupp.lib" )			// 添加的：添加引入库命令

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif


// CMsgBoardCtl
class ATL_NO_VTABLE CMsgBoardCtl :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IMsgBoardCtl, &IID_IMsgBoardCtl, &LIBID_MessageBoardLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IPersistStreamInitImpl<CMsgBoardCtl>,
	public IOleControlImpl<CMsgBoardCtl>,
	public IOleObjectImpl<CMsgBoardCtl>,
	public IOleInPlaceActiveObjectImpl<CMsgBoardCtl>,
	public IViewObjectExImpl<CMsgBoardCtl>,
	public IOleInPlaceObjectWindowlessImpl<CMsgBoardCtl>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CMsgBoardCtl>,
	public CProxy_IMsgBoardCtlEvents<CMsgBoardCtl>,
	public IPersistStorageImpl<CMsgBoardCtl>,
	public ISpecifyPropertyPagesImpl<CMsgBoardCtl>,
	public IQuickActivateImpl<CMsgBoardCtl>,
#ifndef _WIN32_WCE
	public IDataObjectImpl<CMsgBoardCtl>,
#endif
	public IProvideClassInfo2Impl<&CLSID_MsgBoardCtl, &__uuidof(_IMsgBoardCtlEvents), &LIBID_MessageBoardLib>,
#ifdef _WIN32_WCE // 要在 Windows CE 上正确加载该控件，要求 IObjectSafety
	public IObjectSafetyImpl<CMsgBoardCtl, INTERFACESAFE_FOR_UNTRUSTED_CALLER>,
#endif
	public CComCoClass<CMsgBoardCtl, &CLSID_MsgBoardCtl>,
	public CComControl<CMsgBoardCtl>
{
public:


	CMsgBoardCtl()
	{
		this->m_bstrMessage = L"没有消息内容";	// 初始化成员变量m_bstrMessag
	}

DECLARE_OLEMISC_STATUS(OLEMISC_RECOMPOSEONRESIZE |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_INSIDEOUT |
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST
)

DECLARE_REGISTRY_RESOURCEID(IDR_MSGBOARDCTL)


BEGIN_COM_MAP(CMsgBoardCtl)
	COM_INTERFACE_ENTRY(IMsgBoardCtl)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY(IPersistStorage)
#ifndef _WIN32_WCE
	COM_INTERFACE_ENTRY(IDataObject)
#endif
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
#ifdef _WIN32_WCE // 要在 Windows CE 上正确加载该控件，要求 IObjectSafety
	COM_INTERFACE_ENTRY_IID(IID_IObjectSafety, IObjectSafety)
#endif
END_COM_MAP()

BEGIN_PROP_MAP(CMsgBoardCtl)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	// 示例项
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_CONNECTION_POINT_MAP(CMsgBoardCtl)
	CONNECTION_POINT_ENTRY(__uuidof(_IMsgBoardCtlEvents))
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(CMsgBoardCtl)
	MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown)
	CHAIN_MSG_MAP(CComControl<CMsgBoardCtl>)
	DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()
// 处理程序原型:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid)
	{
		static const IID* arr[] =
		{
			&IID_IMsgBoardCtl,
		};

		for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
		{
			if (InlineIsEqualGUID(*arr[i], riid))
				return S_OK;
		}
		return S_FALSE;
	}

// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IMsgBoardCtl
public:
	HRESULT OnDraw(ATL_DRAWINFO& di)
	{
		RECT& rc = *(RECT*)di.prcBounds;						// 获取浏览器中ActiveX对象所占区域大小
		Rectangle( di.hdcDraw, rc.left, rc.top, rc.right, rc.bottom );		// 画出矩形框
		HFONT hfont = CreateFont( 14, 7, 0, 0, FW_NORMAL, FALSE, FALSE, 0, ANSI_CHARSET,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			DEFAULT_PITCH|FF_SWISS,"宋体");		// 创建字体
		SelectObject( di.hdcDraw, hfont );						// 将字体选入设备上下文
		RECT msgRc;										// 文字输出区域
		msgRc.left = rc.left + 5;								// 设置区域大小
		msgRc.top = rc.top + (rc.bottom - rc.top)/2;
		msgRc.right = rc.right - 5;
		msgRc.bottom = rc.bottom - 5;
		char *pcmsg = ConvertBSTRToString( this->m_bstrMessage );	// 将COM字符串转为多字节字符串
		DrawText( di.hdcDraw, pcmsg, strlen( pcmsg ), &msgRc, 0 );	// 输出字符消息
		return S_OK;										// 返回成功代码
	}

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}
	STDMETHOD(get_msgText)(BSTR* pVal);
	STDMETHOD(put_msgText)(BSTR newVal);
	BSTR m_bstrMessage;
	LRESULT OnLButtonDown(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
};

OBJECT_ENTRY_AUTO(__uuidof(MsgBoardCtl), CMsgBoardCtl)
