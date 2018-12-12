#include<stdio.h>
#include<stdlib.h>

struct node 
{ 
     int data; 
     struct node* left; 
     struct node* right; 
}*root=NULL; 

void display()
{
	printf("\nPreorder traversal of binary tree is \n"); 
     printPreorder(root); 
  
     printf("\nInorder traversal of binary tree is \n"); 
     printInorder(root);   
  
     printf("\nPostorder traversal of binary tree is \n"); 
     printPostorder(root); 
  
}

struct node* newNode(int data) 
{ 
     struct node* node = (struct node*)malloc(sizeof(struct node)); 
     node->data = data; 
     node->left = NULL; 
     node->right = NULL; 
  
     return(node); 
} 
  
void printPostorder(struct node* node) 
{ 
     if (node == NULL) 
        return; 
     printPostorder(node->left);
     printPostorder(node->right); 
     printf("%d ", node->data); 
} 

void printInorder(struct node* node) 
{ 
     if (node == NULL) 
          return; 
     printInorder(node->left);
     printf("%d ", node->data);   
     printInorder(node->right); 
} 

void printPreorder(struct node* node) 
{ 
     if (node == NULL) 
          return; 
     printf("%d ", node->data);   
     printPreorder(node->left);   
     printPreorder(node->right); 
}     

struct node* insert(struct node* node, int key) 
{ 
	char ch;
    if (node == NULL) return newNode(key); 
  
   	printf("\nEnter left(l) or to the right(r)of the node no. %d: ",node->data);
    scanf(" %c",&ch);
	if (ch=='l') 
        node->left  = insert(node->left, key); 
    else 
        node->right = insert(node->right, key);    
  
  return node; 
} 

int main() 
{ 
    int a,ch;
	struct node *ptr;
    while(1)
	{
		printf("\n1.Insert\n2.Display\nEnter anything else to exit:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter element to be inserted:");
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
