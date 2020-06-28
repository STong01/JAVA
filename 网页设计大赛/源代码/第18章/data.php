<? 
if(isset($_GET['text']))												//检查text是否存在
{	
	$contents="读写错误!";												//给变量赋初值
	$r=stripcslashes($_GET['text']);							//取得GET方法传来的值，并去掉“/”
	$fp=fopen("ajax.txt","a+");										//打开ajax.txt文件
	$ss=date("h:i:s")."*";												//取得当前时间，并加上“*”表示换行
	$r=$ss.$r;
	//$r = iconv("gb2312","UTF-8",$r);						// 编码转换
	fwrite($fp, $r."*");													//将信息写入ajax.txt中
	fclose($fp);
	$fd=fopen("ajax.txt","r");	    							//打开ajax.txt文件
	$contents = fread($fd, filesize("ajax.txt"));	//读取ajax.txt文件中的内容，并存于变量$fd中
  fclose ($fd);																	//关闭文件
	$contents = iconv("gb2312","UTF-8",$contents);// 编码转换
	echo $contents;																//输出更新后的信息
}
else
{
	echo "错误";
}
?>
