public class test
{   private int val1,val2 ;
	public void myFun(int x,int y)
     {
	    val1=x ;
	    val2=y ;
	    System.out.println("The sum is: "+(val1+val2)) ; 
	} 
	public static void main(String arg[])
	{
	    test MyObj=new test();
	    MyObj.myFun(1,2);
	}
}
