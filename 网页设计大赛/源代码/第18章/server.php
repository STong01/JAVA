<?php														// PHP����ʼ
error_reporting(E_ALL^E_NOTICE);// �ر�������ʾ
$filename = $_GET["file"];			// ��ȡ�ļ���
if( $filename != "" )						// ��������Ϊ��
{
	if( file_exists($filename) )			// ���ļ�����
	{ 
			$fd = fopen($filename, "r");	// ���ļ�  
			$contents =   fread($fd,filesize($filename));	// ��ȡ�ļ�����
			$contents = iconv("gb2312","UTF-8",$contents);// ����ת��
			echo $contents;								// ����HTTP��Ӧ
	}
	else													// �ļ�������
	{
		echo "�ļ��Ҳ���";					// �����ʾ
	}
}
?>