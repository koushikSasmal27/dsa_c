#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*left;
	struct node*right;
	int height;
};
struct node*create(int v)
{
	struct node*new=(struct node*)malloc(sizeof(struct node));
	new->left=NULL;
	new->right=NULL;
	new->data=v;
	new->height=1;
	return new;
}
int get_height(struct node*root)
{
	if(root==NULL)
	{
		return 0;
	}
	return root->height;
}
int balance_factor(struct node*root)
{
	if(root==NULL)
	{
		return 0;
	}
	return get_height(root->left)-get_height(root->right);
}
struct node*leftRotation(struct node*x)
{
	struct node*y=x->right;
	struct node*T2=y->left;
	
	y->left=x;
	x->right=T2;
	y->height=1+(get_height(y->left)>get_height(y->right)?get_height(y->left):get_height(y->right));
	x->height=1+(get_height(x->left)>get_height(x->right)?get_height(x->left):get_height(x->right));
	return y;
}
struct node*rightRotation(struct node*y)
{
	struct node*x=y->left;
	struct node*T2=x->right;
	
	
	x->right=y;
	y->left=T2;
	y->height=1+(get_height(y->left)>get_height(y->right)?get_height(y->left):get_height(y->right));
	x->height=1+(get_height(x->left)>get_height(x->right)?get_height(x->left):get_height(x->right));
	return x;
}
struct node*insert(struct node*root,int v)
{
	if(root==NULL)
	{
		return create(v);
	}
	if(v<root->data)
	{
		root->left=insert(root->left,v);
	}
	else if(v>root->data)
	{
		root->right=insert(root->right,v);
	}
	else 
	{
		return root;
	}
	root->height=1+(get_height(root->left)>get_height(root->right)?get_height(root->left):get_height(root->right));
	int bf=balance_factor(root);
	
	// LL case: Right rotation
	if(bf>1 && v<root->left->data)
	{
		return rightRotation(root);
	}
	
	 // RR case: Left rotation
	if(bf<-1 && v>root->right->data)
	{
		return leftRotation(root);
	}
	
	// LR case: Left rotation on left child, then right rotation
	if(bf>1 && v>root->left->data)
	{
		root->left=leftRotation(root->left);
		return rightRotation(root);
	}
	
	// RL case: Right rotation on right child, then left rotation
	if(bf<-1 && v<root->right->data)
	{
		root->right=rightRotation(root->right);
		return leftRotation(root);
	}
	return root;
}
// In-order traversal to display the tree
void display(struct node* root) {
    if (root != NULL) {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}
int main()
{
	struct node*root=NULL;
	int n,v;
	printf("enter the no of node:");
	scanf("%d",&n);
	while(n>0)
	{
		printf("enter the data of node:");
		scanf("%d",&v);
		root=insert(root,v);
		n--;
	}
	printf("In-order traversal: ");
	display(root);
	printf("\n%d\n%d",root->left->data,root->right->data);
	return 0;
}
