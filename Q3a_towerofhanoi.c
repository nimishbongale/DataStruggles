/*
Author @nimishbongale
Version 1.0.2
Date 03/10/2018
A program which solves the TOH problem  
*/
#include <stdio.h>

int step=0;// global var to count steps 

void MoveTower(int n, char source,char dest,char temp)//recursive function to solve TOH problem 
{
   
    if(n==1) 
    {   
		step++;
        printf("\nStep #%d disc %d from source:%c to destination:%c \n", step, n, source,dest);
        return;
	}
    
        MoveTower(n-1, source, temp, dest);
    	step++; 
    	printf("\nStep #%d disc %d from source:%c to destination:%c\n", step, n, source, dest);
        MoveTower(n-1, temp, dest, source);
}
               
int main()//driver function 
{
			int num;
            printf("Enter the number of disks: ");
            scanf("%d", &num);
            MoveTower(num,'A','B','C');
            return 0;
}
