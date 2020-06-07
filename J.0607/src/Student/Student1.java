package Student;

public class Student1 
{
	//定义Student类的6个私有属性 id name eng math comp sum
		private String id;
		private String name;
		private int eng;
		private int math;
		private int comp;
		private int sum;
		
		//定义Student类的全参构造方法	
		public Student1(String id,String name,int eng,int math,int comp) 
		{
			this.id=id;
			this.name=name;
			this.eng=eng;
			this.math=math;
			this.comp=comp;
			sum();
		}
		
		//定义Student类的构造方法
		public Student1(Student1 s, int math, int comp) 
		{
			this.id=s.id;
			this.name=new String(s.name);
			this.eng=s.eng;
			this.math=math;
			this.comp=comp;
			sum();
		}

		//生成所有属性的get和set方法
		public String getId() 
		{
			return id;
		}

		public void setId(String id) 
		{
			this.id = id;
		}

		public String getName() 
		{
			return name;
		}

		public void setName(String name) 
		{
			this.name = name;
		}

		public int getEng() 
		{
			return eng;
		}

		public void setEng(int eng) 
		{
			this.eng = eng;
		}

		public int getMath() 
		{
			return math;
		}

		public void setMath(int math) 
		{
			this.math = math;
		}

		public int getComp()
		{ 

			return comp;
		}

		public void setComp(int comp)
		{
			this.comp = comp;
		}

		public int getSum()
		{
			return sum;
		}

		public void setSum(int sum) 
		{
			this.sum = sum;
		}
		
		//定义sum方法
		void sum() 
		{
			this.sum=eng+math+comp;
		}

		//定义toString()方法
		@Override
		public String toString()
		{
			return "Student [id=" + id + ", name=" + name + ", eng=" + eng + ", math=" + math + ", comp=" + comp + ", sum="
					+ sum + "]";
		}
		
		//判断参数对象是否为Student类的对象
		public boolean equals(Object x) 
		{
			//若当前对象不是Student类的对象
			if(this.getClass()!=x.getClass())
				//直接返回false
				return false;
			//将参数对象转为Student类型
			Student1 bStudent=(Student1)x;
			//返回当前对象的id是否和参数对象的id相等
			return (this.getId().equals(bStudent.getId()));
		}
		
		//比较成绩大小，当前对象成绩比参数对象成绩大时返回1 相等返回0 其他返回-1
		public int compare(Student1 A) 
		{
			if(this.getSum()>A.getSum()) 
				return 1;
			else if(this.getSum()==A.getSum())
				return 0;
			else return -1;
		}

}
