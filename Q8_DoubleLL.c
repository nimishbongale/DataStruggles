/*
Author @nimishbongale
Version 1.0.1
Date 26/10/2018
A program which demonstrates the concept of double linked list   
*/
#include <stdio.h>
#include <stdlib.h>

struct node//declaring the structure
{
    struct node *prev;
    int number;
    struct node *next;
}*head=NULL,*newNode=NULL,*tail=NULL,*sptr=NULL,*p=NULL, *after=NULL, *before=NULL;

struct node* createNewNode()//returning the new created node
{
    int data;
    newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
    	printf("Heap Memory full!");
    	exit(0);
	}
    newNode->prev=newNode->next=NULL;
    printf("\nEnter the data : ");
    scanf("%d", &(newNode->number));
    return newNode;
}

struct node * mysearch(int data)//function to search for given element 
{
	for(p=head;p!=NULL;p=p->next)
	if(p->number==data)
	return p;
    return NULL;
}

//functions to insert at various locations 
void insertBegin()
{
	newNode=createNewNode();
    if (head == NULL)
    {
		head = newNode;
        tail = head;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertEnd()
{
	if(tail==NULL)
	insertBegin();
    newNode=createNewNode();
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insertBefore(int ele)
{
	sptr=mysearch(ele);
	if(sptr==NULL)
	printf("No node found!");
	else if(sptr==head)
	insertBegin();
	else
   	{
   		before=sptr->prev;
        newNode=createNewNode();
   		before->next=newNode;
   		newNode->prev=before;
    	newNode->next = sptr;
    	sptr->prev=newNode;
	}
}

void insertAfter(int ele)
{
	sptr=mysearch(ele);
	if(sptr==NULL)
	printf("No node found!");
	else if(sptr == tail)
    insertEnd();
    else
    {
    	after=sptr->next;
        newNode=createNewNode();
        sptr->next = newNode;
        newNode->prev = sptr;
        newNode->next=after;
        after->prev=newNode;
    }
    
}

//function to print the DLL
void display()
{
    p=head;
    printf("\nCurrent Double linked list:\n ");
    for(p=head;p!=NULL;p=p->next)
    printf("%d->", p->number);
}

//functions to delete from DLL
void deleteBegin()
{
	if(head==NULL)
	printf("Queue empty!");
	else
	{
    head=head->next;
    free(head->prev);
    head->prev=NULL;
	}
}

void deleteEnd()
{
	if(head==NULL)
	printf("Queue empty!");
	else
	{
	tail=tail->prev;
	free(tail->next);
	tail->next=NULL;
	}
}

void deleteMid(int key)
{
	if(head==NULL)
	printf("Queue empty!");
	else 
	{
	sptr=mysearch(key);
	if(sptr==NULL)
	printf("No node found!");
	else if(sptr==head)
	deleteBegin();
	else if(sptr==tail)
	deleteEnd();
	else
	{
		before=sptr->prev;
		after=sptr->next;
		before->next=after;
		after->prev=before;
		free(sptr);
	}
	}
}

int main()//driver function 
{
    int ch,data;
    while (1)
    {
    printf("\n 1 - Insert in the Beginning");
    printf("\n 2 - Insert at the end");
    printf("\n 3 - Insert before a node");
    printf("\n 4 - Insert after a node");
    printf("\n 5 - Delete at the begnning");
    printf("\n 6 - Delete at the end");
    printf("\n 7 - Delete in the middle");
    printf("\n 8 - Display the doubly linked list");
    printf("\nEnter anything else to exit"); 
    	printf("\nEnter your choice :");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                insertBegin();
                break;
            case 2:
                insertEnd();
				break;
            case 3:
				printf("\nEnter number to inserted before : ");
                scanf("%d", &data);
                insertBefore(data);
                break;
            case 4:
                printf("\nEnter number to inserted after : ");
                scanf("%d", &data);
                insertAfter(data);
                break;
            case 5:
				deleteBegin();
				break;
			case 6:
				deleteEnd();
				break;
            case 7:
                printf("\nEnter number to delete: ");
                scanf("%d", &data);
                deleteMid(data);
                break;
            case 8:
                display();
                break;
            
            default:
            	exit(0);
        }
    }
    return 0;
}





