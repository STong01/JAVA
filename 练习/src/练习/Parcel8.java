package 练习;

public class Parcel8 //创建一个名为Parcel8的类
{
	public Destination dest(final String dest)//创建一个返回值为Destination类型的有参方法，参数的值不能改变
	{
		return new Destination()//实现Destination接口，产生并返回一个引用(匿名内部类)
				{
			private String label = dest;//给私有的lable复制(将dest的值赋给label)
			public String readLabel()//创建一个readLabel()方法，返回值为String类(类中所包含的方法)
			{
				return label;
			}
				};
	}

	public static void main(String[] args) 
	{
		Parcel8 p = new Parcel8();//创建一个类型为Parcel8的对象
		Destination d = p.dest("Tanzania");//创建一个类型为Destination的对象，值为对象p调用的dest()方法所返回的值，传入的参数为字符串“Tanzania”
	}
}
