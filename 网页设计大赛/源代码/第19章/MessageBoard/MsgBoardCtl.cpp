// MsgBoardCtl.cpp : CMsgBoardCtl ��ʵ��
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
	WORD x = LOWORD( lParam );	// ����Ϣ��������ȡ�����ʱ��x����
	WORD y = HIWORD( lParam );	// ����Ϣ��������ȡ�����ʱ��y����
	this->Fire_ClickIn( x, y );	// �����¼�
	return 0;
}
