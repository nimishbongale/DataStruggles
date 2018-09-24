import java.util.Scanner;
class fibrec
{
	static int fib(int n)
	{
		if(n==1)
		return 0;
		if(n==2)
		return 1;		
		return (fib(n-1)+fib(n-2));
	}
		
	public static void main(String args[])
	{
		int n;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the number of terms \t");
		n=sc.nextInt();
		for(int i=1;i<=n;i++)
		System.out.println(fib(i)+"\t");
	}
		
}

