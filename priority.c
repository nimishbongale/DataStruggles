#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int pri_que[SIZE];
int front = -1,rear=-1;

void enque(int ele)
{
	int i,j;
	if (rear == SIZE - 1)
	printf("Queue is full!");
	else if ((front == -1) && (rear == -1))
	{

        front=rear=0;
		pri_que[rear] = ele;
	}
	
	else
	{
		int i;
   		for(i=rear;i>=0;i--)
			{
				if(ele > pri_que[i])
				pri_que[i+1] = pri_que[i];
				else
				break;
			}
    	pri_que[i+1] = ele;
	    rear++;
	}
	
} 

int deque()
{

    int i;
	if ((front==-1) || (rear==-1))
	printf("Queue is empty");
	else
	return pri_que[rear--];
}

void display()
{
	int k;
	for (k=front;k<=rear;k++)
	printf(" %d ", pri_que[k]);
}

int main()
{

    int element, choice; 
	while (1)
	{
		printf("\n1.Insert\n2.Delete\n3.Display\nEnter anything else to exit");
		printf("\nEnter your choice : ");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
			printf("\nEnter value to be inserted: ");
			scanf("%d",&element);
			enque(element);
			break;

            case 2: 
			printf("Deleted element=%d",deque());
			break;
			
			case 3: 
			display();
			break;

            default:
			exit(0);
		}
	}
	return 0;
}



	













