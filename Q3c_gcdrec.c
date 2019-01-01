/*
Author @nimishbongale
Version 1.0.2
Date 26/09/2018
A program which finds the gcd of two numbers  
*/
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
	}//printing and terminating the function calls
	
	findgcd(a,b,n+1);
}

int main()//driver function 
{
	int c,d;
	printf("Enter the 2 no.s\n");
	scanf("%d%d",&c,&d);
	findgcd(c,d,1);
	return 0;
}
