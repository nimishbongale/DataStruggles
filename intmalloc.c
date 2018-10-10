#include <stdio.h>

int main()
{
    int *p; int i = 0;
    p = (int *)malloc(10*sizeof(int));
    printf("\nNumber of bytes allocated for p is %d", (10*sizeof(int)));
    *p = 10;
    
    printf("\nValue in position %d that 'p' points to is %d. Address of p is %d", i, *p,p);
    
        for(i = 1; i<10; i++)
        {
            *(++p) = *p + i;
            printf("\nValue in position %d that 'p' points to is %d. Address of p is %d", i, *p,p);
        
        }//end for
    
    printf("\n");
}//end main

