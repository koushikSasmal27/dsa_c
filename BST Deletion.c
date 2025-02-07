#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*left;
	struct node*right;
};
struct node*create(int data)
{
	struct node*new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	new->left=NULL;
	new->right=NULL;
	return new;
}
struct node*insert(struct node*root,int data)
{
	if(root==NULL)
	{
		root=create(data);
	}
	if(root->data>data)
	{
		root->left=insert(root->left,data);
	}
	else if(root->data<data)
	{
		root->right=insert(root->right,data);
	}
	return root;
}


void add(struct node*root,int v)
{
	struct node*r=root;
	struct node*prev=NULL;
	while(r!=NULL)
	{
		prev=r;
		if(r->data==v)
		{
			printf("%d is already exists in the tree",r->data);
			return;	
		}
		if(r->data>v)
		{
		r=r->left;
		}
		else if(r->data<v)
		{
		r=r->right;
		}
	}
	if(prev->data>v)
	{
		prev->left=create(v);
	}
	else
	{
		prev->right=create(v);
	}
	
	
}
struct node*inOrderpredecessor(struct node*root)
{
	root=root->left;
	while(root->right!=NULL)
	{
		root=root->right;
	}
	return root;
}
struct node*delet(struct node*root,int key)
{
	struct node*prev;
	
	
	if(root==NULL)return NULL;
	// Case 1: Traverse to find the node to delete
	if(root->data>key)
	{
		root->left=delet(root->left,key);
	}
	else if(root->data<key)
	{
		root->right=delet(root->right,key);
	}
	else
	{	
		// Case 2: Node to delete found
	
		// Case 2a: Node is a leaf
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
            
    	}
        // Case 2b: Node has one child
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
		else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }  
		// Case 2c: Node has two children 
        else{
        	prev=inOrderpredecessor(root);
		root->data=prev->data;
		root->left=delet(root->left,prev->data);
		}    
		
	}
	return root;
}
void display(struct node*root)
{ 
	
	if(root!=NULL)
	{
		display(root->left);
		printf("%d ",root->data);
		display(root->right);
	}
}
int main()
{
	struct node*root=NULL;
	int  n,v;
	printf("Enter the no of node:");
	scanf("%d",&n);
	while(n>0)
	{
		printf("Enter the value of  node:");
		scanf("%d",&v);	
		root=insert(root,v);
		n--;
	}
	int key;
	display(root);
	printf("\nEnter the key element for insert");
	scanf("%d",&key);
	add(root,key);
	display(root);
	printf("\nEnter the key element for delet\n");
	scanf("%d",&key);
	root=delet(root,key);

	display(root);
	return 0;
}
