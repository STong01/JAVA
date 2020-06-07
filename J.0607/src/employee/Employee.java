package employee;

public class Employee 
{
	//定义Employee类的两个属性 name 和  age  其中姓名不超过8个字符
	char name[]= {'\u0000','\u0000','\u0000','\u0000','\u0000','\u0000','\u0000','\u0000'};
	int age;
	
	//定义Employee类的全参构造方法
	public Employee(String name,int age) 
	{
		//判断将String类型的参数转为字符数组，数组的长度是否>8
		if(name.toCharArray().length>8)
		{
			System.arraycopy(name.toCharArray(), 0, this.name, 0,8);
		}
		else 
		{
			System.arraycopy(name.toCharArray(), 0, this.name, 0, name.toCharArray().length);
		}
		this.age=age;
	}
}
