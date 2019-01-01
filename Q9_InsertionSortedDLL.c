/*
Author @nimishbongale
Version 1.0.3
Date 25/11/2018
A program which performs insertion in a sorted DLL  
*/
#include<stdio.h>
#include<stdlib.h>

struct node//declaring a structure
{ 
struct node *prev;
int a;
struct node *next;
}*head=NULL,*ptr=NULL,*tail=NULL,*newNode=NULL;

struct node *create(int x)//function to create and return a node
{ 
	newNode=(struct node *)malloc(sizeof(struct node));
	newNode->a=x;
	newNode->next=NULL;
	newNode->prev=NULL;
    return newNode;
}

void swap(struct node *b,struct node *c) //to swap only the elements
{ 
    int temp = b->a; 
    b->a = c->a; 
    c->a = temp; 
} 

void sort()//arrange the list
{ int temp,p;
	ptr=head;
	do{  p=0; 
		 ptr=head;
		while(ptr->next!=NULL)
        {
        	if(ptr->a > (ptr->next)->a)
        	{ swap(ptr,ptr->next);
        	  p=1;
            }
            ptr=ptr->next;
        }

	}while(p);
	
}

void insert()//add data 
{   
    int a;
	printf("\nEnter number: ");
	scanf("%d",&a);
	newNode=create(a);			        
	if(head==NULL)
	{
		head=newNode;
		tail=head;
	}
	else
	{
		tail->next=newNode;
		newNode->prev=tail;
		tail=tail->next;
    sort();
		} 

}


void display()//print the data
{
	printf("\nCurrent Double linked list:\n ");

    for(ptr=head;ptr!=NULL;ptr=ptr->next)

    printf("%d->", ptr->a);
}

int main()//driver function 
{
	int q;
	
	while(1)
		{
			printf("\n1.Insert\n2.Display\nEnter anything else to exit: ");
			scanf("%d",&q);
			switch(q)
			{
				case 1: 
                       insert();
                       break;
                case 2:
                       display();
                       break;
                default:
                       exit(0);                     
			}
			
		}
		return 0;
}
