========================================================================
    �ģ��⣺MessageBoard ��Ŀ����
========================================================================

Ӧ�ó�������Ϊ�������˴� MessageBoard ��Ŀ���������ڴ˻���֮��
��д�Լ��Ķ�̬���ӿ� (DLL)��


���ļ������������Ŀ��ÿ���ļ�
�����ݡ�

MessageBoard.vcproj
    ����ʹ��Ӧ�ó��������ɵ� VC++ ��Ŀ������Ŀ�ļ��� 
    �������й����ɸ��ļ���ʹ�õ� Visual C++ �汾����Ϣ���Լ�
    �й���Ӧ�ó�������ѡ���ƽ̨�����ú���Ŀ����
    ����Ϣ��

MessageBoard.idl
    ���ļ�������������Ŀ�ж�������Ϳ⡢�ӿ�
    �� coclass �� IDL ���塣
    ���ļ����� MIDL ���������������ɣ�
        C++ �ӿڶ���� GUID ����                 (MessageBoard.h)
        GUID ����                                (MessageBoard_i.c)
        һ�����Ϳ�                               (MessageBoard.tlb)
        ���ʹ���                                 (MessageBoard_p.c �� dlldata.c)

MessageBoard.h
    ���ļ������� MessageBoard.idl �ж������� C++ �ӿڶ���
    �� GUID �����������ڱ���������� MIDL �������ɡ�

MessageBoard.cpp
    ���ļ���������ӳ��� DLL ������ʵ�֡�

MessageBoard.rc
    ���ǳ���ʹ�õ����� Microsoft Windows ��Դ����
    ����

MessageBoard.def
    ��ģ�鶨���ļ�Ϊ�������ṩ�й� DLL ��Ҫ���
    ��������Ϣ�������������������ݵĵ�����
        DllGetClassObject  
        DllCanUnloadNow    
        GetProxyDllInfo    
        DllRegisterServer	
        DllUnregisterServer

/////////////////////////////////////////////////////////////////////////////
������׼�ļ���

StdAfx.h��StdAfx.cpp
    ��Щ�ļ�����������Ϊ MessageBoard.pch ��Ԥ����ͷ (PCH) �ļ�
    ����Ϊ StdAfx.obj ��Ԥ���������ļ���

Resource.h
    �������ڶ�����Դ ID �ı�׼ͷ�ļ���


/////////////////////////////////////////////////////////////////////////////
