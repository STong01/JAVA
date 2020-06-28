<?php														// PHP程序开始
error_reporting(E_ALL^E_NOTICE);// 关闭所有提示
$filename = $_GET["file"];			// 提取文件名
if( $filename != "" )						// 若参数不为空
{
	if( file_exists($filename) )			// 若文件在在
	{ 
			$fd = fopen($filename, "r");	// 打开文件  
			$contents =   fread($fd,filesize($filename));	// 读取文件内容
			$contents = iconv("gb2312","UTF-8",$contents);// 编码转换
			echo $contents;								// 返回HTTP响应
	}
	else													// 文件不存在
	{
		echo "文件找不到";					// 输出提示
	}
}
?>