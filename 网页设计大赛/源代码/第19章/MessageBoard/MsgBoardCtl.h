// MsgBoardCtl.h : CMsgBoardCtl ������
#pragma once
#include "resource.h"       // ������
#include <atlctl.h>
#include "MessageBoard.h"
#include "_IMsgBoardCtlEvents_CP.h"
#include <comutil.h>
#pragma comment( lib, "comsupp.lib" )
using namespace _com_util;
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
	public IDataObjectImpl<CMsgBoardCtl>,
	public IProvideClassInfo2Impl<&CLSID_MsgBoardCtl, &__uuidof(_IMsgBoardCtlEvents), &LIBID_MessageBoardLib>,
	public CComCoClass<CMsgBoardCtl, &CLSID_MsgBoardCtl>,
	public CComControl<CMsgBoardCtl>
{
public:

	CMsgBoardCtl()
	{
		this->m_bstrMessage = L"��Ϣ";
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
	COM_INTERFACE_ENTRY(IDataObject)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
END_COM_MAP()

BEGIN_PROP_MAP(CMsgBoardCtl)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	// ʾ����
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
// �������ԭ��: 
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
			RECT& rc = *(RECT*)di.prcBounds;
			// ��������������Ϊ di.prcBounds ָ���ľ���
			Rectangle( di.hdcDraw, rc.left, rc.top, rc.right, rc.bottom );
			HFONT hfont = CreateFont( 14, 7, 0, 0, FW_NORMAL, FALSE, FALSE, 0, ANSI_CHARSET,
						OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
						DEFAULT_PITCH|FF_SWISS,"����");
			SelectObject( di.hdcDraw, hfont );
			RECT msgRc;
			msgRc.left = rc.left + 5;
			msgRc.top = rc.top + (rc.bottom - rc.top)/2;
			msgRc.right = rc.right - 5;
			msgRc.bottom = rc.bottom - 5;
			char *pcmsg = ConvertBSTRToString( this->m_bstrMessage );
			DrawText( di.hdcDraw, pcmsg, strlen( pcmsg ), &msgRc, 0 );
			return S_OK;
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
