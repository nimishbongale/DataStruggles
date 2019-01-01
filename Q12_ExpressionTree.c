/*
Author @nimishbongale
Version 1.0.2
Date 21/11/2018
A program which forms and evaluates an expression tree  
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tree//declaring the tree structure
{
    char data; 
    struct tree *left,*right;
}*stack[20],*node;

int top=-1;

void push(struct tree* node)//insert into pointer stack 
{
    stack[++top]=node;
}

struct tree * pop()//delete from pointer stack
{
    return(stack[top--]);
}

int check(char ch)//check if operator or operand 
{
    if(ch=='+'||ch=='-'||ch=='/'||ch=='*')
        return 2;
    else
        return 1;
}

int cal(struct tree *node)//function to calculate result 
{
    int ch;
    ch=check(node->data);
    if(ch==1)
        return node->data-48;
       
    else if(ch==2)
    {
        if(node->data=='+')
            return cal(node->left)+cal(node->right);
        if(node->data=='-')
            return cal(node->left)-cal(node->right);
        if(node->data=='*')
            return cal(node->left)*cal(node->right);
        if(node->data=='/')
            return cal(node->left)/cal(node->right);
    }
    else
        return 0;
}

void inorder(struct tree *node)//print inorder form of expression 
{
    if(node!=NULL)
    {
        inorder(node->left);
        printf("%c",node->data);
        inorder(node->right);
    }
}

void operand(char b)//called function if char is operand 
{
    node=(struct tree*)malloc(sizeof(struct tree));
    node->data=b;
    node->left=NULL;
    node->right=NULL;
    push(node);
}

void operators(char a)//called function if char is operator 
{
    node=(struct tree*)malloc(sizeof(struct tree));
    node->data=a;
    node->right=pop();
    node->left=pop();
    push(node);
}

int main()//driver function 
{
    int i,op,result;
    char postfix[20];
    
    printf("Enter the expression in postfix form \n");
    fflush(stdin);
    scanf("%s",postfix);
    
    for(i=0;postfix[i]!='\0';i++)
    {
        op=check(postfix[i]); 
        if(op==1)
            operand(postfix[i]);
        else if(op==2)
            operators(postfix[i]);
    }
    result=cal(stack[top]);
    printf("\nThe value of the postfix expression you entered is %d\n",result);
    printf("\nThe inorder traversal of the tree is: ");
    inorder(stack[top]);
    return 0;
}
