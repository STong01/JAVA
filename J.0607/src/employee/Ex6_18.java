package employee;

import java.io.*;

public class Ex6_18 
{
	//定义类的属性Filename
	String Filename;
	
	//定义类Ex6_18的全参构造方法
	public Ex6_18(String Filename)
	{
		this.Filename=Filename;
	}
		
	//定义写对象的方法
	public void writeEmployee(Employee e,int n) throws Exception 
	{
		//创建RandomAccessFile类的对象  对文件执行的操作类型是读写
		RandomAccessFile randomAccessFile=new RandomAccessFile(Filename, "rw");
		//移动文件位置，从偏离文件开头的n*20个字节数的位置开始
		randomAccessFile.seek(n*20);
		for(int i=0;i<8;i++) 
		{
			//循环8次写入4个字节的int型数字
			randomAccessFile.writeInt(e.age);
			//关闭随机访问流
			randomAccessFile.close();
		}
	}
		
	//定义读对象的方法
	public void readEmployee(int n) throws Exception 
	{
		//创建8个字符大小的字符数组
		char buf[]=new char[8];
		//创建RandomAccessFile类的对象  对文件执行的操作类型是只读
		RandomAccessFile randomAccessFile=new RandomAccessFile(Filename, "r");
		//移动文件位置，从偏离文件开头的n*20个字节数的位置
		randomAccessFile.seek(n*20);
		for(int i=0;i<8;i++)
		{
			//循环8次读取字符
			buf[i]=randomAccessFile.readChar();
		}
		System.out.println("name");
		System.out.println("buf");
		System.out.println("age:"+randomAccessFile.readInt());
		//关闭随机访问流
		randomAccessFile.close();
	}
		
	public static void main(String[] args) throws Exception 
	{
		//创建类Ex6_18的对象tEx6_18
		Ex6_18 tEx6_18=new Ex6_18("E:/1.txt");
		//创建三个Employee类的对象
		Employee e1=new Employee("张三",23);
		Employee e2=new Employee("李四",44);
		Employee e3=new Employee("赵六",36);
		//写入对象数据
		tEx6_18.writeEmployee(e1, 0);
		tEx6_18.writeEmployee(e3, 2);
		System.out.println("第一个雇员的信息");
		//读取第一个雇员的信息
		tEx6_18.readEmployee(0);
		System.out.println("第三个雇员的信息");
		//读取第三个雇员的信息
		tEx6_18.readEmployee(2);
		//写入对象数据
		tEx6_18.writeEmployee(e2, 1);
		System.out.println("第二个雇员信息");
		//读取第二个雇员的信息
		tEx6_18.readEmployee(1);
	}
}
