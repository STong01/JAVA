package Student;

public class StudentClass1
{
	//定义StudentClass类的4个属性  3个私有属性name Students[] size 静态属性capacity
		private String name;
		static int capacity=40;
		private Student1 students[];
		private int size;
		
		//定义StudentClass类的构造方法
		public StudentClass1(String name, int size) 
		{
			super();
			this.name = name;
			this.size = size;
		}

		//定义所有属性的get和set方法
		public String getName() 
		{
			return name;
		}

		public void setName(String name)
		{
			this.name = name;
		}

		public static int getCapacity() 
		{
			return capacity;
		}

		public static void setCapacity(int capacity) 
		{
			StudentClass1.capacity = capacity;
		}

		public Student1[] getStudents() 
		{
			return students;
		}

		public void setStudents(Student1[] students) 
		{
			for(int i=0;i<size;i++) 
			{
				this.students[i] = new Student1(students[i], i, i);
			}
		}

		public int getSize() 
		{
			return size;
		}

		public void setSize(int size) 
		{
			this.size = size;
		}

		//定义toString()方法
		@Override
		public String toString()
		{
			String s;
			s= " 班级:" + name +"\t" + "容量:" + capacity + "\t" + "实际人数:" + size +"\n\n";
			s= s + "学号"+"\t" + "姓名"+"\t" + "英语"+"\t"+"数学"+"\t"+ "计算机" +"\t" + "总成绩\n";		
			for (int i=0; i<size; i++)
			  s=s+students[i].getId()+"\t"+students[i].getName()+"\t"+students[i].getEng()+"\t"+students[i].getMath()+"\t"+students[i].getComp()+"\t"+students[i].getSum()+"\n";  
		   	return s;
		}
		
		//已知学生的学号，查找此学号是否存在 如果存在，返回其在数组中的下标位置 若不存在，返回-1
		public int find(String id)
		{
			for (int i=0;i<size;i++)
				if (students[i].getId().equals(id)) return i;
			return -1;
		} 

		//在数组的末尾添加一个学生对象 增加之前需先判断数组中是否还有空间，并且在数组中查找将要增加的学号是否已经存在
		//增加成功，返回true 否则返回false
		public boolean add(Student1 aStudent)
		{
		    if (size==capacity) return false;
	        if (find(aStudent.getId())>=0) return false; 
	        this.students[size]=new Student1(
	                                          new String(aStudent.getId()),
	                                          new String(aStudent.getName()),
	                                          aStudent.getEng(),
	                                          aStudent.getMath(),
	                                          aStudent.getComp()
	                                         );
		     size++;
		     return true;
		} 
		
		//已知一个Student对象，将此对象从数组中删除
		public boolean del(Student1 aStudent)
		{
			int pos=find(aStudent.getId());
			if (pos==-1) return false; 
			for (int i=pos+1;i<size;i++)
			   students[i-1]=students[i];
			size--;		
			return true;
		}	

		//已知一个学号，删除一个学生
		public boolean del(String id)
		{
			int pos=find(id);
			if (pos==-1) return false; 
			for (int i=pos+1;i<size;i++)
			   students[i-1]=students[i];
			size--;		
			return true;
		}	

		//使用选择排序的方法将学生按总成绩从高到低排序
		public void selectionSort()
		{
			Student1 temp;
			for (int i=0;i<size-1;i++)
			  for (int j=i+1;j<size;j++)
			    if (students[j].compare(students[i])>0)
			    {
			    	temp = students[i];
			    	students[i]=students[j];
			    	students[j]=temp;
			    }
	     }
		
		//插入排序方法
		public void insertSort()
		{
			Student1 temp;
			for (int i=1;i<size;i++) 
			{
			      temp=students[i];
			      int j=i-1;
			      while (j>-1 && temp.compare(students[j])>0)
			      {
			    	  students[j+1]=students[j];
			    	  j--;
			       }
			       students[j+1]=temp;
			}		
		}
}
