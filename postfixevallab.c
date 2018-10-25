#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define SIZE 15 

int stack[SIZE];
char user[SIZE];
int top=0;

int pop()
{
	return stack[--top];
}

void push(int n)
{
	stack[top++]=n;
}

int main()
{
	start:;
	int i=0,cn=0,pop1=0,pop2=0;
	char input;
	top=0;
	printf("Please enter a valid postfix expression\n");
	gets(user);
	
	while(user[i]!='\0')
	{
		int result=0,l=0;
		input=user[i];
		
		if((input>=48)&&(input<=57))
	    push(input-48);
	    
		else if ((top!=0)&&((top%2==0)||((top-cn)%2==0))&&((input=='+')||(input=='-')||(input=='*')||(input=='/')||(input=='$')||(input=='^')))
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
		    cn++;
		}
			
	else
	{
	printf("Invalid expression\n");
	goto start;
	}
			i=i+1;
}
	if(top==1)
	printf("Result=%d",pop());
	else 
	{
		printf("Invalid expression\n");
		goto start;
    }
	return 0;
}

