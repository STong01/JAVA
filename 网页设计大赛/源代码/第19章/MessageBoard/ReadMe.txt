========================================================================
    �ģ��� : MessageBoard ��Ŀ�ſ�
========================================================================

Ӧ�ó�����Ϊ����������� MessageBoard ��Ŀ����������
��д��̬���ӿ�(DLL)����㡣

���ļ�����
�����Ŀ��ÿ���ļ�������ժҪ��

MessageBoard.vcproj
    ������Ӧ�ó��������ɵ� VC++ ��Ŀ������Ŀ�ļ���
    �������й����ɴ��ļ��� Visual C++ �汾����Ϣ���Լ�
    �й�ʹ��Ӧ�ó�����ѡ���
    ƽ̨�����ú���Ŀ���ܵ���Ϣ��

MessageBoard.idl
    ���ļ�������Ŀ�ж�������Ϳ⡢
    �ӿں� co-class �� IDL ���塣
    ���ļ����� MIDL ����������������:
        C++ �ӿڶ���� GUID ����(MessageBoard.h)
        GUID ����(MessageBoard_i.c)
        ���Ϳ�(MessageBoard.tlb)
        ���ʹ������(MessageBoard_p.c and dlldata.c)

MessageBoard.h
    ���ļ������� MessageBoard.idl �ж������� C++
    �ӿڶ���� GUID �����������ڱ����ڼ��� MIDL �������ɡ�
MessageBoard.cpp
    ���ļ���������ӳ��� DLL ������ʵ�֡�
MessageBoard.rc
    ���ǳ���ʹ�õ����� Microsoft Windows ��Դ
    ���б�

MessageBoard.def
    ��ģ�鶨���ļ�Ϊ�������ṩ�й� DLL �����
    ��������Ϣ���������������ݵĵ���:
        DllGetClassObject  
        DllCanUnloadNow    
        GetProxyDllInfo    
        DllRegisterServer	
        DllUnregisterServer

/////////////////////////////////////////////////////////////////////////////
������׼�ļ�:

StdAfx.h��StdAfx.cpp
    ��Щ�ļ�����������Ϊ MessageBoard.pch
    ��Ԥ����ͷ(PCH)�ļ��Լ���Ϊ StdAfx.obj ��Ԥ���������ļ���

Resource.h
    ���Ƕ�����Դ ID �ı�׼ͷ�ļ���

/////////////////////////////////////////////////////////////////////////////
