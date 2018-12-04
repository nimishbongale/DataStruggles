#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *prev;
	int number;
	struct node *next;

}*head=NULL,*newNode=NULL,*tail=NULL,*sptr=NULL,*p=NULL; 



struct node* createNewNode()
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

void insertEnd()
{
	newNode=createNewNode();

	if((head==NULL)&&(tail==NULL))
	{
		head=newNode;
		tail=head;	
	}

    else
    {
	tail->next = newNode;
	newNode->prev = tail;
	tail = newNode;
	}
}

void checkpalin()
{
	sptr=tail;
	for(p=head;p!=NULL;p=p->next)
	{
		if(sptr->number!=p->number)
		{
			printf("\nNot a Palindrome!");
			return;
		}
		sptr=sptr->prev;
	}
	printf("\nPalindrome!");
}

int main()
{
	int ch;
	while(1)
	{
		printf("\n1.Insert\n2.Check if palindrome or not\nEnter anything else to exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insertEnd();
				break;
				
				case 2:
					checkpalin();
					break;
					
					default:
						break;
		}
	}
	return 0;
}
