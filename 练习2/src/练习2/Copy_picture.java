package 练习2;

//将一个D盘中的“bd_logo1.png”图片复制到E盘
import java.io.*;

public class Copy_picture 
{
	public static void main(String[] args) throws IOException
	{
		//打开输入流
		InputStream fis = new FileInputStream("D:\\bd_logo1.png");
		//打开输出流
		OutputStream fos = new FileOutputStream("E:\\bd_logo1.png");
		//创建字节数组，数组大小为实际可读字节数-(avaolable())
		byte[] b = new byte[fis.available()];
		//进行读取
		fis.read(b);
		//进行写入
		fos.write(b);
		//关闭流，后开先关，先开后关
		fis.close();
		fos.close();
	}
}
