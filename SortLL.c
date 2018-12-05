#include<stdio.h>
#include<stdlib.h>
struct node
{ int a;
struct node *next;
	
}*head=NULL,*ptr=NULL;

struct node *create(int x)
{ struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->a=x;
	;
	newnode->next=NULL;
    return newnode;

}

void insert()
{   
    int a;
	printf("\nEnter number");
	scanf("%d",&a);
				       
	if(head==NULL)
	{
		head=create(a);

	}
	else
	{
		ptr=head;
		
		while(ptr->next!=NULL)
			ptr=ptr->next;
		    
		ptr->next=create(a);


	} 

}

void swap(struct node *b,struct node *c) 
{ 
    int temp = b->a; 
    b->a = c->a; 
    c->a = temp; 
} 

void sort()
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



void display()
{
	ptr=head;
	if(head==NULL)
	{
		printf("\nEmpty! \n");
	}
	else{
		while(ptr!=NULL)
		{
			printf(" %d ",ptr->a);
			ptr=ptr->next;
		}
	}
}

void main()
{
	int q;
	
	while(1)
		{
			printf("\n1.Insert\n2.Sort\n3.Display\nEnter anything else to exit: ");
			scanf("%d",&q);
			switch(q)
			{
				case 1: 
                       insert();
                       break;
                case 2:
                       sort();

                       break;
                case 3:
                       display();
                       break;
                default:
                       exit(0);                     
			}
			
		}
}
