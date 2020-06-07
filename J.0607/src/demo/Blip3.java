package demo;

import java.io.*;

public class Blip3
{
	//定义类Blip3的属性i 和 s
	int i;
	String s;
		
	public Blip3(String string, int j) {
		// TODO Auto-generated constructor stub
	}

	//构造类Blip3的无参构造方法
	public Blip3() 
	{
		//原样输出Blip3 Constructor
		System.out.println("Blip3 Constructor");
	}
		
	//构造类Blip3的全参构造方法
	public void Blip31(String x,int a)
	{
		//原样输出Blip3(String x, int a)
		System.out.println("Blip3(String x,int a)");
		//将x的值赋给属性s
		s=x;
		//将a的值赋给属性i
		i=a;
	}

	//定义toString()方法
	public String toString() 
	{
		return "Blip3 [i=" + i + ", s=" + s + "]";
	}
		
	//实现接口Externalizable中的方法writeExternal
	public void writeExternal(ObjectOutput out) throws IOException 
	{
		System.out.println("Blip3.writeExternal");
		out.writeObject(s);
		out.writeInt(i);
	}
	 
	//实现接口Externalizable中的方法readExternal
	public void readExternal(ObjectInput in) throws ClassNotFoundException, IOException
	{
		System.out.println("Blip3.readExternal");
		s=(String)in.readObject();
		i=in.readInt();
	}
		
	@SuppressWarnings("resource")
	public static void main(String[] args) throws Exception
	{
		//原样输出Constructing objects:
		System.out.println("Constructing objects:");
		//创建类Blip3的对象b3
		Blip3 b3=new Blip3("A String",47);
		//输出对象b3，即调用其toString()方法
		System.out.println(b3);
		//构建对象输出流
		ObjectOutputStream objectOutputStream=new ObjectOutputStream(new FileOutputStream("Blip3.out"));
		//原样输出Saving object:
		System.out.println("Saving object:");
		//写入指定的对象b3
		objectOutputStream.writeObject(b3);
		//关闭输出流管道
		objectOutputStream.close();
		//构建对象输入流
		ObjectInputStream inputStream=new ObjectInputStream(new FileInputStream("Blip3.out"));
		//原样输出Recovering b3:
		System.out.println("Recovering b3:");
		//读取并返回一个对象b3
		b3=(Blip3)inputStream.readObject();
		//输出对象b3，即调用toString()方法
		System.out.println(b3);
	}

}
