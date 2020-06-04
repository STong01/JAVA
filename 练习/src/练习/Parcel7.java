package 练习;

public class Parcel7 //创建一个名为Parcel7的类
{
	public Wrapping wrap(int x)//创建一个返回值为Wrapping类型的有参方法
	{
		return new Wrapping(x)//实现Wrapping接口，产生并返回一个引用的(内部类)
				{
			public int value()//创建一个value()方法，返回值为int(类中所包含的方法)
			{
				return super.value()*47;//返回最终的数值
			}
				}
	}

	public static void main(String[] args) 
	{
		Parcel7 p = new Parcel7();//创建一个类型为Parcel7的对象
		Wrapping w = p.wrap(10);//创建一个类型为Wrapping的对象，值为对象p调用的wrap()方法所返回的值，传入的参数为7

	}

}
