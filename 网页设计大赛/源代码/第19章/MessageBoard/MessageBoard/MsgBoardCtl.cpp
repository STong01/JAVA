// MsgBoardCtl.cpp : CMsgBoardCtl ��ʵ��
#include "stdafx.h"
#include "MsgBoardCtl.h"


// CMsgBoardCtl

STDMETHODIMP CMsgBoardCtl::get_msgText(BSTR* pVal)
{
	*pVal = this->m_bstrMessage;						// �����ⲿ�����msgText���Ե�ֵ
	return S_OK;									// ���سɹ�����
}

STDMETHODIMP CMsgBoardCtl::put_msgText(BSTR newVal)
{
	this->m_bstrMessage = newVal;					// �����ⲿ���õ�msgText���Ե�ֵ
	this->FireViewChange();							// �����ؼ��ػ��¼�
	return S_OK;									// ���سɹ�����
}

LRESULT CMsgBoardCtl::OnLButtonDown( UINT uMsg, WPARAM wParam, 
									LPARAM lParam, BOOL& bHandled )
{
	WORD x = LOWORD( lParam );			// ����Ϣ��������ȡ�����ʱ��x����
	WORD y = HIWORD( lParam );			// ����Ϣ��������ȡ�����ʱ��y����
	this->Fire_ClickIn( x, y );			// �����¼�
	return 0;
}
