/*
Author @nimishbongale
Version 1.0.2
Date 26/10/2018
A program which demonstrates the concept of circular linked list   
*/
#include<stdio.h>
#include<stdlib.h>

struct node//declaring the structure 
{
	int data;
	struct node *link;
}*front=NULL,*head=NULL,*tail=NULL,*ptr,*p;

struct node* createNode()//returning the created node
{
	struct node *newNode=(struct node*)malloc(sizeof(struct node));
	if(newNode==NULL)
	{
	printf("Heap full!");
	exit(0);
	}
	else
	{
		printf("Enter the data\n");
		scanf("%d",&(newNode->data));
		newNode->link=NULL;
	}
	return newNode;
}

//functions to insert at various locations 
void InsertBegin()
{
	ptr=createNode();
	if(head==NULL)
	{
		head=tail=ptr;
		head->link=head;
		tail=head;
	}
	else
	{
	ptr->link=head;
	head=ptr;
	tail->link=head;
	}
}

void InsertEnd()
{
	if(head==NULL)
	InsertBegin();
	ptr=createNode();
	tail->link=ptr;
	ptr->link=head;
	tail=ptr;
}

void InsertMiddle(int ele)
{
	p=head;
	while((p!=tail)&&(p->data!=ele))
	p=p->link;
	if(p==NULL)
	printf("No node found!");
	else if(p==head)
	InsertBegin();
	else if(p==tail)
	InsertEnd();
	else
	{
		ptr=createNode();
	    ptr->link=p->link;
	    p->link=ptr;
	}
}

//functions to delete at various locaions 
void DeleteBegin()
{
	if(head==NULL)
	printf("Circular Queue empty!");
	else if (head==tail)
	{
		free(head);
		free(tail);
		head=NULL;
		tail=NULL;
	}
	else
	{
		p=head;
		head=head->link;
		tail->link=head;
		free(p);
	}
}

void DeleteEnd()
{
	if(head==NULL)
	printf("Circular Queue empty!");
	else if(head==tail)
	{
		free(head);
		head=NULL;
		tail=NULL;
	}
	else
	{
	for(p=head;p->link!=tail;p=p->link);
	free(tail);
	tail=p;
	tail->link=head;
	}
}

void DeleteMiddle(int ele)
{
	p=head;
	if(head==NULL)
	printf("Circular Queue is empty!");
	else if(head->data==ele)
	DeleteBegin();
	else
	{
	while((p!=tail)&&((p->link)->data!=ele))
	p=p->link;
	if(p==NULL)
	printf("No node found!");
	else
		{
			ptr=p->link;
			p->link=(p->link)->link;
			free(ptr);
		}
	}
}

void display()//printing the circular linked ist
{
	p=head;
	if(p!=NULL)
	{
	do
	{
		printf("%d->",p->data);
		p=p->link;
	}while(p!=head);
	}
}

int main()//driver function 
{
	int ch,d;
	while(1)
	{
	printf("\n*****MENU*****\n1.Insert in the beginning\n2.Insert in Middle\n3.Insert in the End\n4.Delete in the Beginning\n5.Delete in the Middle\n6.Delete in the End\n7.Display the contents\nEnter anything else to exit: ");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:
			InsertBegin();
			break;
			
			case 2:
				printf("Enter the data of the node before which the new node is to be inserted\n");
				scanf("%d",&d);
				InsertMiddle(d);
				break;
				
				case 3:
					InsertEnd();
					break;
					
					case 4:
						DeleteBegin();
						break;
						
						case 5:
						printf("Enter the data of the node to be deleted\n");
						scanf("%d",&d);
						DeleteMiddle(d);
						break;
						
						case 6:
							DeleteEnd();
							break;
						
						
						case 7:
							printf("\nCurrent list:\n");
							display();
							printf("\n");
							break;
								
								default:
								exit(0);
							}
							
						}
						return 0;
					}

