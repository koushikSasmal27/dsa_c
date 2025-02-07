#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*left;
	struct node*right;
};
void inorder(struct node*root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}
	
}
//int isBST(struct node*root)
//{
//	static struct node*prev=NULL;
//	if(root!=NULL)
//	{
//		if(!isBST(root->left))
//		{
//			return 0;
//		}
//		if(prev!=NULL && root->data<=prev->data)
//		{
//			return 0;
//		}
//		prev=root;
//		return isBST(root->right);
//	}
//	else 
//	{
//		return 1;
//	}
//	
//}

int isBST(struct node*root)
{
	static struct node*prev=NULL;
	if(root==NULL)
	{
		return 1;   // An empty tree is always a BST.
	}
	else
	{
		if(!isBST(root->left))
		{
			return 0;
		}
		if(prev!=NULL && prev->data>=root->data)
		{
			return 0;
		}
		prev=root;
		return isBST(root->right);
	}
}







struct node*create(int data)
{
	struct node*new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	new->left=NULL;
	new->right=NULL;
	return new;
}
int main()
{
	
	struct node*root=create(4);
	struct node*p1=create(2);
	struct node*p2=create(6);
	struct node*p3=create(1);
	struct node*p4=create(3);
	root->left=p1;
	root->right=p2;
	p1->left=p3;
	p1->right=p4;
	inorder(root);
	if(isBST(root))
	{
	printf("\nyes! it is a BST");	
	}
	else
	{
	printf("\nit is not a BST");		
	}
	return 0;
}
