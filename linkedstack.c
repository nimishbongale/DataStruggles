#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
}*head=NULL,*ptr,*p;

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

void display()
{
	p=head;
	while(p!=NULL)
	{
		printf("%d ->",p->data);
		p=p->link;
	}
}

void InsertEnd()
{
	p=head;
	ptr=createNode();
	if(head==NULL)
	head=ptr;
	else
	{
	while(p->link!=NULL)
	p=p->link;
	p->link=ptr;
	}
}

void DeleteEnd()
{
	p=head;
	if(head==NULL)
	printf("Stack underflow!");
	else if(head->link==NULL)
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
						DeleteEnd();
						break;
						
						case 3:
							printf("\nCurrent Stack:\n");
							display();
							printf("\n");
							break;
								
								default:
								exit(0);
							}
							
						}
						return 0;
					}
						
