/*
Author @nimishbongale
Version 1.0.2
Date 17/10/2018
A program which demonstrates the concept of singly linked list    
*/
#include<stdio.h>
#include<stdlib.h>

struct node//declaring the structure 
{
	int data;
	struct node *link;
}*head=NULL,*ptr,*p;

struct node* createNode()//function to return the created node
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
//functions to insert data into various locations 
void InsertBegin()
{
	ptr=createNode();
	ptr->link=head;
	head=ptr;
}

void InsertEnd()
{
	p=head;
	ptr=createNode();
	while(p->link!=NULL)
	p=p->link;
	p->link=ptr;
}

void InsertMiddle(int ele)
{
	p=head;
	while((p!=NULL)&&(p->data!=ele))
	p=p->link;
	if(p==NULL)
	printf("No node found!");
	else
	{
		ptr=createNode();
	    ptr->link=p->link;
	    p->link=ptr;
	}
}

//functions to delete data from various locations
void DeleteBegin()
{
	p=head;
	head=head->link;
	free(p);
}

void DeleteEnd()
{
	
	if(head->link==NULL)
	{
	free(head);
	head=NULL;
}
	else
	{
	while((p->link)->link!=NULL)
	p=p->link;
	free(p->link);
	p->link=NULL;
	}
}

void DeleteMiddle(int ele)
{
	p=head;
	if(head->data==ele)
	DeleteBegin();
	else
	{
	while((p!=NULL)&&((p->link)->data!=ele))
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

//function to print linked list 
void display()
{
	p=head;
	while(p!=NULL)
	{
		printf("%d ->",p->data);
		p=p->link;
	}
}

int main()//driver function 
{
	int ch,d;
	while(1)
	{
	printf("\n*****MENU*****\n1.Insert in the beginning\n2.Insert in Middle\n3.Insert in the End\n4.Delete in the Beginning\n5.Delete in the Middle\n6.Delete in the End\n7.Display the contents\nEnter anything else to exit: ");
	scanf("%d",&ch);
	
	if((head==NULL)&&((ch==4)||(ch==5)||(ch==6)))
	{
		printf("Linked List is empty!");
		continue;
	}
	else if((head==NULL)&&((ch==1)||(ch==2)||(ch==3)))
	ch=0;
	
	switch(ch)
	{
		case 0:
		case 1:
			InsertBegin();
			break;
			
			case 2:
				printf("Enter the data of the node after which the new node is to be inserted\n");
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
						
	

