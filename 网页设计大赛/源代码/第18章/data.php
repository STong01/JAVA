<? 
if(isset($_GET['text']))												//���text�Ƿ����
{	
	$contents="��д����!";												//����������ֵ
	$r=stripcslashes($_GET['text']);							//ȡ��GET����������ֵ����ȥ����/��
	$fp=fopen("ajax.txt","a+");										//��ajax.txt�ļ�
	$ss=date("h:i:s")."*";												//ȡ�õ�ǰʱ�䣬�����ϡ�*����ʾ����
	$r=$ss.$r;
	//$r = iconv("gb2312","UTF-8",$r);						// ����ת��
	fwrite($fp, $r."*");													//����Ϣд��ajax.txt��
	fclose($fp);
	$fd=fopen("ajax.txt","r");	    							//��ajax.txt�ļ�
	$contents = fread($fd, filesize("ajax.txt"));	//��ȡajax.txt�ļ��е����ݣ������ڱ���$fd��
  fclose ($fd);																	//�ر��ļ�
	$contents = iconv("gb2312","UTF-8",$contents);// ����ת��
	echo $contents;																//������º����Ϣ
}
else
{
	echo "����";
}
?>
