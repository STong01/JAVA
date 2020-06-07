package book;

public class Book
{
	//定义Book的四个属性， id name author price
	int id;
	String name;
	String author;
	float price;
	
	//定义Book类的全参构造方法
	public Book(int id,String name, String author,float price)
	{
		this.id = id;
		this.name = name;
		this.author = author;
		this.price = price;
	}

}
