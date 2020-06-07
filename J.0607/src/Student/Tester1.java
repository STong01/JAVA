package Student;

import java.io.*;
import java.util.Scanner;

public class Tester1 
{
	public static void main(String[] args) throws Exception
	{
		//声明Student类型的数组对象
		Student1 students[];
		//创建StudentClass类的对象
		StudentClass1 aClass=new StudentClass1("信息0228", 9);
		//为声明的数组对象申请空间
		students=new Student1[5];
		for(int i=0;i<5;i++) {
			//初始化数组对象
			students[i]=new Student1(getAStudent(i+1), i, i);
		}
		//
		aClass.setStudents(students);
		//调用toString()方法
		System.out.println(aClass);
		
		//定义文件输出流
		FileOutputStream fOutputStream=new FileOutputStream("stu.ser");
		//定义对象输出流
		ObjectOutputStream sObjectOutputStream=new ObjectOutputStream(fOutputStream);
		for(int i=0;i<5;i++) {
			//写入指定的数组对象
			sObjectOutputStream.writeObject(students[i]);
			//关闭输出流管道
			sObjectOutputStream.close();
		}
	}
	
	public static Student1 getAStudent(int i){
		//声明Student类的对象
		Student1 studenti;		    		
		System.out.println("输入第" + i + "个学生的信息:"); 
		@SuppressWarnings("resource")
		Scanner scanner=new Scanner(System.in);
		System.out.print("学号:");
		//从键盘获取id
       	String id =scanner.next(); 
       	System.out.print("姓名:");
       	//从键盘获取name
       	String name = scanner.next();         
       	System.out.print("英语成绩:"); 
       	//从键盘获取eng
       	int eng = scanner.nextInt();         
	    System.out.print("数学成绩:"); 
	    //从键盘获取math
	    int math = scanner.nextInt();          
	    System.out.print("计算机成绩:"); 
	    //从键盘获取comp
	    int comp = scanner.nextInt(); ;
	    //初始化声明的对象studenti
	    studenti = new Student1(id,name,eng,math,comp);
	    return studenti;
	   }

}
