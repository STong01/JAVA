// MsgBoardCtl.cpp : CMsgBoardCtl 的实现
#include "stdafx.h"
#include "MsgBoardCtl.h"
#include ".\msgboardctl.h"


// CMsgBoardCtl

STDMETHODIMP CMsgBoardCtl::get_msgText(BSTR* pVal)
{
	*pVal = this->m_bstrMessage;
	return S_OK;
}

STDMETHODIMP CMsgBoardCtl::put_msgText(BSTR newVal)
{
	this->m_bstrMessage = newVal;
	this->FireViewChange();
	return S_OK;
}

LRESULT CMsgBoardCtl::OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	WORD x = LOWORD( lParam );	// 从消息参数中提取鼠标点击时的x坐标
	WORD y = HIWORD( lParam );	// 从消息参数中提取鼠标点击时的y坐标
	this->Fire_ClickIn( x, y );	// 触发事件
	return 0;
}
