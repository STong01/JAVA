// MsgBoardCtl.cpp : CMsgBoardCtl 的实现
#include "stdafx.h"
#include "MsgBoardCtl.h"


// CMsgBoardCtl

STDMETHODIMP CMsgBoardCtl::get_msgText(BSTR* pVal)
{
	*pVal = this->m_bstrMessage;						// 传出外部请求的msgText属性的值
	return S_OK;									// 返回成功代码
}

STDMETHODIMP CMsgBoardCtl::put_msgText(BSTR newVal)
{
	this->m_bstrMessage = newVal;					// 保存外部设置的msgText属性的值
	this->FireViewChange();							// 激发控件重绘事件
	return S_OK;									// 返回成功代码
}

LRESULT CMsgBoardCtl::OnLButtonDown( UINT uMsg, WPARAM wParam, 
									LPARAM lParam, BOOL& bHandled )
{
	WORD x = LOWORD( lParam );			// 从消息参数中提取鼠标点击时的x坐标
	WORD y = HIWORD( lParam );			// 从消息参数中提取鼠标点击时的y坐标
	this->Fire_ClickIn( x, y );			// 触发事件
	return 0;
}
