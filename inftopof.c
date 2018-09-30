#include <ctype.h>
#include <stdio.h>

#define size 50

int top=-1;
char s[size],infix[size],postfix[size];

void push(char item)
{
	if(top==(size-1))
	printf("Overflow");
    else
	s[++top]=item; 
}

int pop()
{
	if(top==-1)
	{
	printf("Underflow");
    return '0';
    }
	else
	return s[top--];
} 
 
int priority(char symbol)
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

void inftopof()
{
	int i=0,j=0;
	push('#');
	while(infix[i]!='\0')
	{
		if(infix[i]=='(')
		push('(');
		else if(isalpha(infix[i]))
		{
		   postfix[j++]=infix[i];
		}
		else if(infix[i]==')')
		{
	    while (s[top]!='(')
	    {
	    postfix[j]=pop();
	    j++;
	}
	pop();
	}
	else
	{
	while(priority(s[top])>=priority(infix[i]))
		{
		postfix[j]=pop();
		j++;
}
	push(infix[i]);
	}
	i++;
}
	while(s[top]!='#')
	{
		postfix[j]=pop();
		j++;
	}
	postfix[j]='\0';
	//printf("%s",postfix);
	}



int main()
{
  	printf("Enter a valid infix expression\n");
  	scanf("%s",infix);
  	/*for(int k=0;k<50;k++)
  	scanf("%c",&infix[k]);*/
	inftopof();
  	printf("Converted expression : %s",postfix);
  	return 0;
}

 	
	 	
			
	
