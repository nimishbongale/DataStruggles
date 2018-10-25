#include <ctype.h>
#include <stdio.h>

#define size 50

int top=-1,ob=0,cb=0,op=0,od=0,flag=0;
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
		{
		push('(');
		ob++;
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
			flag++;
			break;
		}
			
	    while (s[top]!='(')
	    {
	    postfix[j]=pop();
	    j++;
	}
	pop();
	}
	else
	{
		if(od==(op+1))
		op++;
		else
		{
			flag++;
			break;
		}
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
}



int main()
{
	start:;
	top=-1;ob=0;cb=0;op=0;od=0;flag=0;
  	printf("Enter a valid infix expression\n");
  	scanf("%s",infix);
	inftopof();
	if((ob==cb)&&(flag==0))
  	printf("Converted expression : %s",postfix);
  	else 
  	{
  	printf("Invalid expression\n");
  	goto start;
  }
	  return 0;
}

 	
	 	
			
	

