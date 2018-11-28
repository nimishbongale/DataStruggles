#include<stdio.h>
#include<stdlib.h>

struct node 
{ 
    int key; 
    struct node *left, *right; 
}*root=NULL; 
   
struct node *newNode(int item) 
{ 
	if(item==-1)
	return NULL;
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    while (current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

struct node* deleteNode(struct node* root, int key) 
{ 
    if (root == NULL) return root; 
 
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
  
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
  
    else
    { 
        
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
       
        struct node* temp = minValueNode(root->right); 
  	root->key = temp->key; 
  	root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 
struct node* search(struct node* root, int key) 
{ 
    if (root == NULL || root->key == key) 
       return root; 
     
    if (root->key < key) 
       return search(root->right, key); 
 
    return search(root->left, key); 
} 

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d  ", root->key); 
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d ", root->key); 
        inorder(root->right); 
    } 
} 

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left); 
        postorder(root->right);
        printf("%d  ", root->key);
    }
}


   
struct node* insert(struct node* node, int key) 
{ 
    if (node == NULL) return newNode(key); 
  
   
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
  
  
    return node; 
} 
   
int main() 
{
   	int a;
	struct node *ptr;
	printf("Enter elements (-1 to terminate)");
    while(1)
	{
		scanf("%d",&a);
		if(a==-1)
		break;
 		root=insert(root,a);
	}
  
	printf("\nPreorder:");	
	preorder(root);
	printf("\nInorder:");	
	inorder(root);
	printf("\nPostorder:");	
	postorder(root);
	
	printf("\nEnter element to be searched: ");
	scanf("%d",&a);
	ptr=search(root,a);
	if(ptr==NULL)
	printf("\nNode not found!");
	else
	printf("\nNode found!");

	printf("\nEnter element to be deleted: ");
	scanf("%d",&a);
	deleteNode(root,a);
	
	printf("\nPreorder:");	
	preorder(root);
	printf("\nInorder:");	
	inorder(root);
	printf("\nPostorder:");	
	postorder(root);
		
	
   return 0; 
} 
