package 练习2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Copy_Maker 
{
	//源名称 
    static String sourceName = "E:\\环境变量设置.txt"; 
    // 目的名称
    static String destName = "F:\\copy环境变量设置.txt"; 
    //字符输入流带缓冲
    static BufferedReader source;
    //字符输出流带缓冲
    static BufferedWriter dest;
    //每一行的内容
    static String line;

    //打开文件
	private static boolean openFiles()
	{
		try
		{
			//创建一个给定文件名的输入流对象 并将其放入输入缓冲流
			source = new BufferedReader (new FileReader(sourceName));
		}
		catch(IOException iox)
		{
			//捕获IO异常
			System.out.println("Problem opening"+sourceName);
			return false;
		}
		try
		{
			//创建一个给定文件名的输出流对象 并将其放入输出缓冲流
			dest = new BufferedWriter(new FileWriter(destName));
		}
		catch(IOException iox)
		{
			System.out.println("Problem opening"+destName);
			return false;
		}
		return true;
	}
	
	//复制内容
	private static boolean copyFiles()
	{
		try
		{
            //一行一行读取输入流中的内容
            //读文本文件也有缓冲器类BufferReader，具有readLine()函数，可以对换行符进行鉴别
			line = source.readLine();
			//内容不为空时
			while(line!=null)
			{
				//向目的文件中写入内容
				dest.write(line);
				//使用newLine方法进行换行
				dest.newLine();
				//刷新
				dest.flush();
				//一行一行读取输入流中的内容
				line = source.readLine();
			}
		}
		catch(IOException iox)
		{
			System.out.println("Problem reading or writing");
			return false;
		}
		catch(ArithmeticException e)
		{
			//TODO:handle exception
		}
		catch(NullPointerException e)
		{
			//TODO:handle exception
		}
		return true;
	}
	
	//关闭文件
	private static boolean closeFiles()
	{
		boolean retVal = true;
		try
		{
			//关闭缓冲流，文件输入流也自动被关闭
			source.close();
		}
		catch(IOException iox)
		{
			System.out.println("Problem closing"+sourceName);
			retVal = false;
		}
		try
		{
			//关闭缓冲流，文件输出流也自动被关闭
			dest.close();
		}
		catch(IOException iox)
		{
			System.out.println("Problem closing"+destName);
			retVal = false;
		}
		return retVal;
	}

	//源文件向目的文件的复制
	public static boolean copy(String src,String dst)
	{
		sourceName = src;
		destName = dst;
		return openFiles() && copyFiles() && closeFiles();
	}
	
    public static void main(String[] args) {
        String sourceName = "E:\\环境变量设置.txt";
        String destName = "F:\\copy环境变量设置.txt"; 
        copy(sourceName, destName);
    }
}