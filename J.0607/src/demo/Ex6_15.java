package demo;

import java.util.zip.*;
import java.io.*;

public class Ex6_15
{
	public static void main(String[] args) throws Exception 
	{
		//构建压缩流，生成压缩文件test.zip
		ZipOutputStream out=new ZipOutputStream(new BufferedOutputStream(new FileOutputStream("E:/test.zip")));
		//遍历main函数的String数组参数
		for(int i=0;i<args.length;i++)
		{
			//原样输出Writing file以及对应的参数
			System.out.println("Writing file"+args[i]);
			//构建字节输入流的缓冲流
			BufferedInputStream inputStream=new BufferedInputStream(new FileInputStream(args[i]));
			out.putNextEntry(new ZipEntry(args[i]));
			//定义int类型变量c
			int c;
			//read()方法读取一个字节，转化为[0,255]的之间的一个整数，返回一个int，如果读到了文件末尾，则返回-1
			while((c=inputStream.read())!=-1)
			{
				//write()方法写一个字节的低8位
				out.write(c);
			}
			//关闭输入流管道
			inputStream.close();
		}
		//关闭输出流管道
		out.close();
		//原样输出Reading file
		System.out.println("Reading file");
		//构建压缩流，将生成的test.zip压缩文件解压恢复原状
		ZipInputStream in2=new ZipInputStream(new BufferedInputStream(new FileInputStream("E:/test.zip")));
		//定义ZipEntry类型变量zEntry
		ZipEntry zEntry;
		//判断：当每次获取到的ZIP文件是否为null
		while((zEntry=in2.getNextEntry())!=null) 
		{
			System.out.println("Reading file"+zEntry.getName());
			int x;
			while((x=in2.read())!=-1)
			{
				System.out.println(x);
			}
		}
		//关闭输入流管道
		in2.close();
	}
}
