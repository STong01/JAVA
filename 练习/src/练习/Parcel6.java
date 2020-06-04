package 练习;

public class Parcel6 //创建一个名为Pancel6的类
{
	public Contents cont()
	{
		//创建一个cont()方法，返回值为Contents
		return new Contents() //实现Contents接口，产生并返回一个引用(匿名内部类)
		{
			private int i = 11;//给私有的i赋值(类中所包含的属性)
			public int value()//创建一个value()方法，返回值为int(类中所包含的方法)
			{
				return i;
			}
		};
	}


	public static void main(String[] args) //主方法
	{
		Pancel6 p = new Parcel6();//创建一个类型为Parcel6的对象
		Contents c = p.cont();//创建一个类型为Contents的对象，值为对象p调用的cont()无参方法所返回的值
	}
}
