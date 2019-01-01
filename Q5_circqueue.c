/*
Author @nimishbongale
Version 1.0.1
Date 10/10/2018
A program to demonstrate the basic functions of circular queue  
*/
#include<stdio.h> 
#define SIZE 5

int myCQ[SIZE]; 


int front=-1,rear = -1,element;


void enQueue(int ele)//function to insert into the queue
{
   	if((front == 0 && rear == SIZE - 1) || (front == rear+1))
    printf("Queue is full!");
    else
    {
    	if(front==-1)
    	front=rear=0;
        else if(rear == SIZE-1) 
        rear = 0;
        else 
        ++rear;

       myCQ[rear] = ele;
   }
}   
      
void deQueue()//delete from queue
{
    
    if(front == -1)
    printf("Queue is Empty!");
    else
    {
        element = myCQ[front];
        printf("\nDeleted element is : %d\n",element);
		if(front== rear)
        front = rear = -1;
        else if(front == SIZE-1 )
        front = 0;
        else
        front++;
    }
}

void display()//to print content of queue
{
    	int i;
        printf("Current Queue:-\n");
        if(front <= rear)
        {
            
            for (i=front; i <= rear; i++)
            printf("%d\t",myCQ[i]);
        }
        else
        {
		 for (i = front;i <= SIZE - 1; i++) 
			printf("%d\t", myCQ[i]);
		
            for (i = 0;i <= rear; i++) 
			printf("%d\t",myCQ[i]);
            }
    }



int main()//driver function 
{
    int ch;
   	while(1)
	   {
        printf("\n*****MENU ******\n1. Insert\n2. Delete\n3. Display\nEnter anything else to exit:");
        scanf("%d",&ch);
        switch(ch)
		{
            case 1:
			 printf("\nEnter the value to be inserted:  ");
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


