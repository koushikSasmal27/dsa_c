#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*left;
	struct node*right;
};
struct node*create(int v)
{
	struct node*new=(struct node*)malloc(sizeof(struct node));
	new->data=v;
	new->left=NULL;
	new->right=NULL;
	return new;
}
struct node*insert(struct node*root,int v)
{
	if(root==NULL)
	{
		return create(v);
	}
	if(root->data<v)
	{
		root->right=insert(root->right,v);
	}
	else if(root->data>v)
	{
		root->left=insert(root->left,v);
	}
	return root;
}
void inorder_traversal(struct node*root)
{
	if(root!=NULL)
	{
		inorder_traversal(root->left);
		printf("%d ",root->data);
		inorder_traversal(root->right);
	}
}
struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (root->data < key) {
        return search(root->right, key);
    } else {
        return search(root->left, key);
    }
}

int main()
{
	int n,v;
	struct node*root=NULL;
	
	printf("Enter the number of node:");
	scanf("%d",&n);
	while(n>0)
	{
		printf("Enter the data of node:");
		scanf("%d",&v);
		root=insert(root,v);
		n--;
	}
	
	inorder_traversal(root);
	int key;
	printf("\nEnter the element which we want to be search:");
	scanf("%d",&key);
	struct node*s=search(root,key);
	if(s!=NULL)
	{
		printf("\nThe value %d is found in tree",s->data);
	}
	else
	{
		printf("\nThe Value is not found");
	}
	return 0;
}
