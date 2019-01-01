/*
Author @nimishbongale
Version 1.0.4
Date 26/09/2018
A program which performs binary search  
*/
#include <stdio.h>

int m;

void binsearch(int a[],int l,int u,int ele)//recursive function to perform binary search 
{
	m=(l+u)/2;
	if(a[m]==ele)
	{
		printf("Element found at pos %d!",(m+1));
		return;
	}
	else if(u==(l+1))
	{
		printf("Element not found!");
		return;
	}
	else if(ele>a[m])
	binsearch(a,m,u,ele);
	else
	binsearch(a,l,m,ele);
}

int main()//driver function 
{
	int n,num,i;
	printf("Enter the no. of elements: ");
	scanf("%d",&num);
	int b[num];
	printf("Enter the sorted array\n");//accepting input
	for(i=0;i<num;i++)
	scanf("%d",&b[i]);
	printf("Enter the element to be searched for: ");
	scanf("%d",&n);
	binsearch(b,0,num,n);
	return 0;
}
