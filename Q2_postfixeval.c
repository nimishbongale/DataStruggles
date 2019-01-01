/*
Author @nimishbongale
Version 1.0.1
Date 12/09/2018
A program which evauates a postfix expression  
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define SIZE 50 

int stack[SIZE];
char user[SIZE];
int top=0,flag=0;
//top is a stack pointer

int pop()// funtion to delete from stack
{
	if(top==-1)
	{
	//printf("Stack underflow.\n");
	flag=1;
	return -1;
	}
	else
	return stack[--top];
}

void push(int n)// function to insert in stack
{
	if(top==(SIZE-1))
    {
		//printf("Stack overflow.\n");
		flag=1;
	}
	else
	stack[top++]=n;
}

int main()// driver function 
{
	int i=0,pop1=0,pop2=0,k=0;
	char input;
	top=0;flag=0;
	printf("Please enter a valid postfix expression, each token separated by a space:-\n");
	gets(user);
	
	for(i=0;user[i]!='\0';i++)
	{
		int result=0;
		input=user[i];
		if(isdigit(input))
	    	{
	    		for(k=i;user[k]!=' ';k++)
	    		{
	    		result=(result*10)+user[k]-48;
	    		i++;
			}
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
		    case '^':
		        result=pow(pop2,pop1);
		        break;
		    	
			}
			push(result);
		}
	else if(input==' ');
	else
	flag=1;
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

 
