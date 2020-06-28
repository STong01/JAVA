<?php				// PHP程序开始
error_reporting(E_ALL^E_NOTICE);// 关闭所有提示
if($_GET["username"]=="admin")	// 如果填入的用户名是admin，则
{
	$msg="admin已经存在";	// 消息：用户名重复
	$msg=iconv("gb2312","UTF-8",$msg);	// 字符编码转换
	echo $msg;		// 传回HTTP响应数据
}
else				// 如果填入的是其它
{	
	$msg=$_GET["username"]."可用";	// 消息：用户名可用
	$msg=iconv("gb2312","UTF-8",$msg);	// 字符编码转换
	echo $msg;		// 传回HTTP响应数据
}
?>