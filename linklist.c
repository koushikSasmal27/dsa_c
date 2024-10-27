#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
struct node*create(struct node*head,int v)
{
	struct node*ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		return  NULL;
	}
	ptr->data=v;
	ptr->next=NULL;
	struct node*h=head;
	if(h==NULL)
	{
		return ptr;
	}
	while(h->next!=NULL)
	{
		h=h->next;
	}
	h->next=ptr;
	return head;
}
void display(struct node*start)
{
	while(start!=NULL)
	{
		printf("%d->",start->data);
		start=start->next;
	}
}
int main()
{
	struct node *head=(struct node*)malloc(sizeof(struct node));
	head=NULL;
	int n;
	printf("enter the number of node");
	scanf("%d",&n);
	while(n>0)
	{
		int v;
		printf("enter the data of node:");
		scanf("%d",&v);
		head=create(head,v);
		n--;
	}
	display(head);
	return 0;
	
}
