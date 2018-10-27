#include <stdio.h>
#include<math.h>

int step=0; 

void MoveTower(int n, char source,char dest,char temp)
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
               
int main()
{
			int num;
            printf("Enter the number of disks: ");
            scanf("%d", &num);
            MoveTower(num,'A','B','C');
            return 0;
}
