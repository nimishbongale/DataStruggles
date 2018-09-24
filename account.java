import java.util.Scanner;
class account
{
	static int Accno,Phone_no;
	static String name; 
	static float balance_amt;
	static Scanner sc=new Scanner(System.in);

        static void getinput()
	{
		System.out.println("Enter Accno,Phone_no,name,balance amt");
		Accno=sc.nextInt();
		Phone_no=sc.nextInt();
		name=sc.next();
		balance_amt=sc.nextFloat();
	}
	static void Deposit()
	{
		float dep;
		System.out.println("Enter amt to be deposited");
		dep=sc.nextInt();
		balance_amt+=dep;
		System.out.println("Balance amt="+balance_amt);
	}
	static void Withdraw()
	{
		float wit;
		System.out.println("Enter amt to be withdrawn");
		wit=sc.nextInt();
		balance_amt-=wit;
		System.out.println("Balance amt="+balance_amt);
	}
	public static void main(String args[])
	{
		getinput();
		int choice;
		while(true)
		{
			System.out.println("1.Deposit \n2.Withdraw \nEnter anything else to exit\nEnter choice ");
			choice=sc.nextInt();
			switch(choice)
			{
				case 1:
				Deposit();
				break;
				
				case 2:
				Withdraw();
				break;
				
				default:
				System.exit(0);
			}
		}
	}
}

			
		
