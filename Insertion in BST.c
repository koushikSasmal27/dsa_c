#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*left;
	struct node*right;
};
struct node*create(int v)
{
	struct node*new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=v;
	new_node->left=NULL;
	new_node->right=NULL;
	return new_node;
}
struct node*insert(struct node*root,int v)
{
	
	if(root==NULL)
	{
		return create(v);
	}
	if(v>root->data)
	{
		root->right=insert(root->right,v);
		
	}
	else if(v<root->data) 														
	{
		root->left=insert(root->left,v);
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
struct node*search(struct node*root,int key)
{
	if(root==NULL || root->data==key)
	{
		return root;
	}
	if(root->data>key)
	{
		return search(root->left, key);
	}
	if(root->data<key)
	{
		return search(root->right, key);
	}
	
}
void add(struct node*root,int key)
{
	struct node*r=root;
	struct node*prev=NULL;
	while(r!=NULL)
	{
		prev=r;
		if(r->data==key)
		{
			printf("\n%d is already present in the BST",r->data);
			return ;
		}
		if(r->data>key)
		{
			r=r->left;
		}
		else
		{
		r=r->right;
		}	
	}
	if(prev==NULL)
	{
		root=create(key);
	}
	else if(prev->data>key)
	{
		prev->left=create(key);
	}
	else if(prev->data<key)
	{
		prev->right=create(key);
	}

	
}
int main()
{
	struct node*root=NULL;
	int n,v;
	printf("Enter the number of node:");
	scanf("%d",&n);
	while(n>0)
	{
		printf("Enter the number  data for each node:");
		scanf("%d",&v);
		root=insert(root,v);
		n--;
	}
	display(root);
	int key;
	printf("\nenter the key element");
	scanf("%d",&key);
	struct node*s=search(root,key);
	if(s!=NULL)
	{
		printf("\n%d is present in the tree",s->data);
	}
	else
	{
		printf("\n%d is not present in the tree",key);
	}
	printf("\nEnter a key to add to the BST: ");
	scanf("%d", &key);
	insert(root, key);
	printf("\n");
	display(root);
	return 0;
}


