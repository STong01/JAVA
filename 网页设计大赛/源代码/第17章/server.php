<?php				// PHP����ʼ
error_reporting(E_ALL^E_NOTICE);// �ر�������ʾ
if($_GET["username"]=="admin")	// ���������û�����admin����
{
	$msg="admin�Ѿ�����";	// ��Ϣ���û����ظ�
	$msg=iconv("gb2312","UTF-8",$msg);	// �ַ�����ת��
	echo $msg;		// ����HTTP��Ӧ����
}
else				// ��������������
{	
	$msg=$_GET["username"]."����";	// ��Ϣ���û�������
	$msg=iconv("gb2312","UTF-8",$msg);	// �ַ�����ת��
	echo $msg;		// ����HTTP��Ӧ����
}
?>