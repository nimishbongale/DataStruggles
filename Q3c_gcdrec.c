#include <stdio.h>

int gcd=1;

void findgcd(int a,int b,int n)
{
	if((a%n==0)&&(b%n==0))
	gcd=n;
	
	if((n==a)||(n==b))
	{
		printf("GCD=%d",gcd);
		return;
	}
	
	findgcd(a,b,n+1);
}

int main()
{
	int c,d;
	printf("Enter the 2 no.s\n");
	scanf("%d%d",&c,&d);
	findgcd(c,d,1);
	return 0;
}
