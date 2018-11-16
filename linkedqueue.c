#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
}*head=NULL,*ptr=NULL,*p=NULL,*tail=NULL;

struct node* createNode()
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

void InsertEnd()
{
	p=head;
	ptr=createNode();
	if(head==NULL)
	{
	head=ptr;
	tail=ptr;
	}
	else
	{
	tail->link=ptr;
	tail=ptr;
	}
}

void DeleteBegin()
{
	if(head==NULL)
	printf("Linked Queue empty!");
	else
	{
	p=head;
	head=head->link;
	free(p);
	}
}

void display()
{
	p=head;
	while(p!=NULL)
	{
		printf("%d ->",p->data);
		p=p->link;
	}
}

int main()
{
	int ch;
	while(1)
	{
	printf("\n*****MENU*****\n1.Insert\n2.Delete\n3.Display the contents\nEnter anything else to exit: ");
	scanf("%d",&ch);
	
	switch(ch)
	{
					case 1:
					InsertEnd();
					break;
					
					case 2:
						DeleteBegin();
						break;
						
						case 3:
							printf("\nCurrent Queue:\n");
							display();
							printf("\n");
							break;
								
								default:
								exit(0);
							}
							
						}
						return 0;
					}
						
	

