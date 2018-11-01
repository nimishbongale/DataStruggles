#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define SIZE 50 

int stack[SIZE];
char user[SIZE];
int top=0,flag=0;

int pop()
{
	if(top<0)
	{
	printf("Stack underflow.\n");
	flag=1;
	}
	return stack[--top];
}

void push(int n)
{
	if(top<(SIZE-1))
	stack[top++]=n;
	else{
		printf("Stack overflow.\n");
		flag=1;
	}
}

int main()
{
	int i=0,cn=0,pop1=0,pop2=0,k=0;
	char input;
	top=0;flag=0;
	printf("Please enter a valid postfix expression, each token separated by a space:-\n");
	gets(user);
	
	while(user[i]!='\0')
	{
		int result=0,l=0;
		input=user[i];
		if((input>=48)&&(input<=57))
	    {
	    	for(k=0;user[i+k]!=' ';k++)
	    	{
	    		result=(result*10)+user[i+k]-48;
	    		l++;
			}
			i+=l;
		    push(result);
		}
		
		else if ((input=='+')||(input=='-')||(input=='*')||(input=='/')||(input=='$')||(input=='^'))
   		{
   			pop1=pop();
   			pop2=pop();
   			switch(input)
   			{
   			case '+':
   				result=pop2+pop1;
   				break;
   			case '-': 
   				result=pop2-pop1;
   			    break;
		    case '*':
		    	result=pop2*pop1;
		    	break;
		    case '/':
		    	if(pop1!=0)
		    	result=pop2/pop1;
		    	else
		    	printf("Can't divide by zero");
		    	break;
		    	
			}
			push(result);
		}
	else if(input==' ');
	else
	flag=1;
	
			i=i+1;
}
	if((top==1)&&(flag!=1))
	printf("Result=%d",pop());
	else 
	{
		printf("Invalid expression\n");
		main();
    }
	return 0;
}

