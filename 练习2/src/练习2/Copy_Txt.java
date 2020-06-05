package 练习2;

//将一个D盘中的“作业0602java.txt”文件复制到E盘
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Copy_Txt 
{
	public static void main(String[] args) throws IOException 
	{
		//创建字符读取流对象和源相关联
		FileReader fr = new FileReader("D:\\作业0602java.txt");
		//创建字符输出流对象，明确要存储数据的目的
		FileWriter fw = new FileWriter("E:\\作业0602java.txt");
		int ch = 0;
		while((ch = fr.read())!=-1)
		{
			fw.write(ch);
		}
		//关闭资源
		fw.close();
		fr.close();
	}
}
