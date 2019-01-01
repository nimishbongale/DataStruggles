/*
Author @nimishbongale
Version 1.0.1
Date 03/10/2018
A program which demontrates the basic functionality of linear queues  
*/
#include <stdio.h>
#define SIZE 5 

int myQ[SIZE];
int element,front=-1,rear=-1;

void enQueue(int ele)//Entering into queue
{
  
    if(rear == SIZE-1) 
	printf("Queue is full!");
    else
    {
    if(front == -1) 
	front = 0; 
    myQ[++rear] = ele;
    }
}

void deQueue()//deleting from the queue
{
    if(front == -1 || front > rear) 
	printf("Queue is empty!");
    else
    printf("Element deleted:%d",myQ[front++]);
}

void display()//printing the queue
{
		int i;
   		printf("\nCurrent Queue:\n");
        for(i = front; i<=rear; i++)
        printf("%d\t", myQ[i]);
}

int main()//driver function 
{
    int ch;
   	while(1)//loop to run as long as the user wants to terminate
	   {
        printf("\n*****MENU ******\n1. Insert\n2. Delete\n3. Display\nEnter anything else to exit:");
        scanf("%d",&ch);
        switch(ch)
		{
            case 1:
			 printf("\nEnter the value to be inserted:");
    		 scanf("%d",&element);
			 enQueue(element);
            break;
            case 2: deQueue();
            break;
            case 3: display();
            break;
            default: exit(0);
        }
    }
    return 0;
}









