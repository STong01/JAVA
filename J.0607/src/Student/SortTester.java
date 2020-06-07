package Student;

import java.io.*;

public class SortTester 
{
	public static void main(String[] args) throws Exception
	{
		//创建Student类的对象并申请空间
		Student1 students[]=new Student1[5];
		//构建文件输入流
		FileInputStream fileOutputStream=new FileInputStream("stu.ser");
		//构建对象输入流
		ObjectInputStream stream=new ObjectInputStream(fileOutputStream);
		for(int i=0;i<5;i++) 
		{
			//循环5次读取students[]对象
			students[i]=(Student1)stream.readObject();
		}
		//关闭输入流管道
		stream.close();
		//创建类StudentClass的对象，并对其初始化
		StudentClass1 aClass=new StudentClass1("软件0201", 5);
		aClass.setStudents(students);		
		//调用toString()方法
		System.out.println(aClass);	
		//调用选择排序方法		
		aClass.selectionSort();		
		System.out.println("选择排序后的结果:\n");
		//调用toString()方法
		System.out.println(aClass);    	    
	}		

}
