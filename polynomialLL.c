#include<stdio.h>
#include<stdlib.h>

int d;

struct node

{

	int data[20];//upto polynomial of degree 20,can be altered accordingly
	struct node *link;

}*head=NULL,*ptr=NULL,*p=NULL;



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
		int i;
		printf("Enter the constant coefficients in decreasing powers of x\n");
		for(i=0;i<=d;i++)
		scanf("%d",&(newNode->data[i]));

		newNode->link=NULL;

	}

	return newNode;

}

void InsertEnd()

{
	ptr=createNode();
	if(head==NULL)
	head=ptr;
	
	else
	{
		p=head;
	while(p->link!=NULL)

	p=p->link;

	p->link=ptr;
	}

}

void add()
{
	int i,sum=0;
	for(i=0;i<=d;i++)
	{
		sum=0;
		for(p=head;p!=NULL;p=p->link)
		sum+=p->data[i];
		printf("%d\t",sum);
	}
}

int main()
{
	int ch;
	printf("Enter the the maximum degree of the polynomial: ");
	scanf("%d",&d);
	while(1)
	{
		printf("\n1.Insert \n2.Add\nEnter anything else to exit: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				InsertEnd();
				break;
				
				case 2:
					add();
					break;
					
					default:
						exit(0);
		}
	}
	return 0;
}
