/*	       4
	      / \					 //41526		preorder 
	     1   6					//51246		    inorder
	    / \					   //52164			postorder
	   5   2     */

#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*left;
	struct node*right;
};
struct node*create(int data)
{
	struct node*new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=data;
	new_node->left=NULL;
	new_node->right=NULL;
	return new_node;
}
void preOrder(struct node*root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preOrder(root->left);
		preOrder(root->right);
		
	}
}
void inOrder(struct node*root)
{
	if(root!=NULL)											/*	       4
																      / \					 //41526		preorder 
																     1   6					//51246		    inorder
																    / \					   //52164			postorder
																   5   2     */
	{
	
		inOrder(root->left);
		printf("%d ",root->data);
		inOrder(root->right);
		
	}
}
void postorder(struct node*root)
{
	if(root!=NULL)
	{
	
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
		
	}
}
int main()
{
	struct node*root=create(4);
	struct node*p1=create(1);
	struct node*p2=create(6);
	struct node*p3=create(5);
	struct node*p4=create(2);
	root->left=p1;
	root->right=p2;
	p1->left=p3;
	p1->right=p4;
	preOrder(root);
	printf("\n");
	inOrder(root);
	printf("\n");
	postorder(root);
	return 0;
}
