/*
Author @nimishbongale
Version 1.0.4
Date 14/11/2018
A program which demonstrates the concept of Binary Search Tree  
*/
#include<stdio.h>
#include<stdlib.h>

struct node //declaring the structure
{ 
    int key; 
    struct node *left, *right; 
}*root=NULL; 
   
struct node *newNode(int item) //creating and returning the newnode
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

void preorder(struct node *root)//printing in preorder format
{
    if (root != NULL)
    {
        printf("%d  ", root->key); 
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root) //printing in inorder format
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d ", root->key); 
        inorder(root->right); 
    } 
} 

void postorder(struct node *root)//printing in postorder format
{
    if (root != NULL)
    {
        postorder(root->left); 
        postorder(root->right);
        printf("%d  ", root->key);
    }
}

void display()//printing the tree
{
	printf("\nPreorder:");	
	preorder(root);
	printf("\nInorder:");	
	inorder(root);
	printf("\nPostorder:");	
	postorder(root);
	
}
   
struct node* insert(struct node* node, int key) //add element
{ 
    if (node == NULL) return newNode(key); 
  
   if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
  
 	return node; 
} 
   
int main() //driver function 
{
   	int a,ch;
	struct node *ptr;
    while(1)
	{
		printf("\n1.Insert\n2.Display\nEnter anything else to exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter element to be inserted:");
				scanf("%d",&a);
				root=insert(root,a);
				break;
				
			case 2:
				display();
				break;
							
						default:
						exit(0);
		}
	}
  return 0; 
} 

