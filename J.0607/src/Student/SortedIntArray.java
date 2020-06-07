package Student;

public class SortedIntArray
{
	//定义类SortedIntArray的三个私有属性 capacity rep size
	private int capacity;
	private Integer[] rep;
	private int size;
		
	//定义类SortedIntArray的带参构造方法
	public SortedIntArray(int n)
	{
		capacity=n;
		rep=new Integer[capacity];
	}
		
	//定义类SortedIntArray的无参构造方法
	public SortedIntArray()
	{ 
		this(100); 
	}
		
		/**
		 * 定义私有的二分查询方法
		 */
	private int search(int i, int lower, int upper)
	{
	   int index=lower;
	   if (upper>=lower)
	   {
		   int middle=(upper+lower)/2;
		   int current=rep[middle].intValue();
		   if (current==i) 
		   {
			   index=middle; 
		   }
		   else if(current<i)
		   {
			   index=search(i, middle+1, upper); 
	       }
		   else
		   {
			   index=search(i, lower, middle-1); 
			}
	   }
	   return index;
	}

	//定义公共的查询方法
	public int search(int i)
	{ 
		return search(i, 0, size-1); 
	}
	
	
	// 定义公共的插入方法
	public SortedIntArray insert(int i)
	{
		int index=search(i);
		for(int j=size;j>index;--j)
		{  
			rep[j]=rep[j-1]; 
		}
		rep[index]=new Integer(i);
		++size;
		return this;
	}
		
	//定义公共的移除方法
	public SortedIntArray remove(int i)
	{
		int index = search(i);
		if (rep[index].intValue()==i)
		{ 
			--size;
			for (int j=index;j<size;++j)
			{ 
				rep[j]=rep[j+1];
			}
		}
		return this;
	}

	//定义toString()方法
	public String toString()
	{
		String toReturn="";
		for (int i=0;i<size;++i)
		{
			toReturn+=rep[i].toString()+ ","; 
		}
		return toReturn;
	}
		
		public static void main(String[] args)
		{
			//创建类SortedIntArray的对象
			SortedIntArray anArray = new SortedIntArray();
	   	    //插入元素
	        anArray.insert(3).insert(2).insert(5).insert(6).insert(4). insert(7).insert(1).insert(8);
	        //调用toString()方法
		    System.out.println(anArray);
		    //移除元素
		    anArray.remove(3).remove(5).remove(7).remove(1);
		    //调用toString()方法
		    System.out.println(anArray);		
		}
}
