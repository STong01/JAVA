package 练习;

public class Parcel9 //创建一个名为Parcel9的类
{
	public Destination dest(final String dest, final float price)//创建一个返回值为Destination类型的有参方法，参数的值必须被final修饰
	{
		return new Destination()//实现Destination接口，产生并返回一个引用(匿名内部类)
				{
			private int cost;//类中所包含的属性
			{
				cost= Math.round(price);//给属性cost赋值，使用Java库中的函数Math.round(price)四舍五入求价格
				if(cost>100)//如果大于100
				{
					System.out.println("Over budget!");//输出“Over budget！”
				}//不能重载
			}
			private String label = dest;//给私有的label赋值，(将dest的值赋给label)
			public String readLabel()//创建一个readLabel()方法，返回值为String类(类中所包含的方法)
			{
				return label;
			}
				};
	}

	public static void main(String[] args) 
	{
		Parcel9 p = new Parcel9();//创建一个类型为Parcel9的对象
		Destination d = p.dest("Tanzania", 101.395F);//创建一个类为Destination的对象，值为对象p调用的dest()方法所返回的值，传入的参数为字符串“Tanzania”，和float类型的数字101.395F
	}
}
