/*
Author @nimishbongale
Version 1.0.3
Date 12/09/2018
A program which converts infix expresion to postfix 
*/

#include <ctype.h>
#include <stdio.h>

#define size 50

int top,ob,cb,op,od,flag;
/* top  is a stack pointer
ob counts opening brackets
cb counts cloing brackets
op counts operators
od counts operands*/

char s[size],infix[size],postfix[size];
/* infix is the input expression array
s is the stack
postfix stores resultant expression*/

void push(char item)// funtion to enter data
{
	if(top==(size-1))
	printf("Overflow");
    else
	s[++top]=item; 
}

int pop()// funtion to delete data
{
	if(top==-1)
	{
	printf("Underflow");
	return -1;
	}
    else
	return s[top--];
} 
 
int priority(char symbol)// function to find priority
{
	switch(symbol)
	{
		case '#': return 0;
		
		case '(':  return 1;
		
		case '+':  
		case '-':  return 2;
			
		case '*':  
		case '/':  return 3;
		
		case '$':
		case '^':  return 4;
	}
	
}

void inftopof()// actual funtion to convert 
{
	int i=0,j=0;
	push('#');
	while(infix[i]!='\0')
	{
		if(infix[i]=='(')
		{
		ob++;
		push('(');
		}
		else if(isalnum(infix[i]))
		{
			od++;
		   postfix[j++]=infix[i];
		}
		else if(infix[i]==')')
		{
			if(ob>0)
			cb++;
			
			else
			{
			flag=1;
			break;
		}
			
	    while (s[top]!='(')
	    postfix[j++]=pop();
	pop();
	}
	else
	{
		op++;
	while(priority(s[top])>=priority(infix[i]))
	postfix[j++]=pop();
        
	push(infix[i]);
	}
	i++;
}
	while(s[top]!='#')
	postfix[j++]=pop();
		
	postfix[j]='\0';
}

int main()// driver function 
{
	top=-1;ob=0;cb=0;op=0;od=0;flag=0;
  	printf("Enter a valid infix expression\n");
  	scanf("%s",infix);
	inftopof();
	if((ob==cb)&&(flag==0)&&(od==(op+1)))
  	printf("Converted expression : %s",postfix);
  	else 
  	{
  	printf("Invalid expression\n");
  	main();
 	}
	  return 0;
}

 	
	 	
			
	

