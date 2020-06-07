package book;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class Ex6_17 
{
	public static void main(String[] args) throws Exception
	{
		//创建Book类的对象，并为其赋初值
		Book book=new Book(201710, "Java", "S_Tong", 25);
		//构建对象输出流
		ObjectOutputStream ooStream=new ObjectOutputStream(new FileOutputStream("E:/book.dat"));
		//写入指定的对象book
		ooStream.writeObject(book);
		//关闭输出流
		ooStream.close();
		//将book对象的值置空
		book=null;
		//构建对象输入流
		ObjectInputStream oisInputStream=new ObjectInputStream(new FileInputStream("E:/book.dat"));
		//读取并返回一个对象book
		book=(Book)oisInputStream.readObject();
		//关闭输入流管道
		oisInputStream.close();
		//原样输出ID is:及book属性id的值
		System.out.println("ID is:"+book.id);
		//原样输出name is:及book属性name的值
		System.out.println("name is:"+book.name);
		//原样输出author is:及book属性author的值
		System.out.println("author is:"+book.author);
		//原样输出price is:及book属性price的值
		System.out.println("price is:"+book.price);
	}

}
