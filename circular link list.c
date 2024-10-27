#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
struct node*create(struct node*head,int v)
{
	struct node*new=(struct node*)malloc(sizeof(struct node));
	new->data=v;
	if(new==NULL)
	{
		return NULL;
	}
	if(head==NULL)
	{
		head=new;
		head->next=head;
	}
	else
	{
	struct node*ptr=head;
	while(ptr->next!=head)
	{
		ptr=ptr->next;
	}
	ptr->next=new;
	new->next=head;
	}
	return head;
}
struct node*insert_at_beginning(struct node*head,int v)
{
	struct node*ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		return NULL;
	}
	ptr->data=v;
	struct node*h=head->next;
	while(h->next!=head)
	{
		h=h->next;
	}
	h->next=ptr;
	ptr->next=head;
	head=ptr;
	return head;
}
struct node*insert_at_any_index(struct node*head,int v,int index)
{
	int i=0;
	struct node*ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		return NULL;
	}
	ptr->data=v;
	if(index==0)
	{
		return insert_at_beginning(head,v);
	}
	struct node*h=head;
	while(i!=index-1)
	{
		h=h->next;
		i++;
	}
	ptr->next=h->next;
	h->next=ptr;

	return head;
}
void display(struct node*head)
{
	struct node*h=head;
	do{
		printf("%d",h->data);
		h=h->next;
		if(h!=head)
		{
			printf("->");
		}
		
	}while(h!=head);
	
}
int main(){
	int n,v,i;
	struct node*head=NULL;
	
	printf("Enter the numder of node:");
	scanf("%d",&n);
	while(n>0)
	{
		printf("Enter data of node:");
	scanf("%d",&v);
		head=create(head,v);
		n--;
	}
	display(head);
	printf("\nEnter data of node:");
	scanf("%d",&v);
	head=insert_at_beginning(head,v);
	display(head);
	printf("\nEnter data of node: and enter the index:");
	scanf("%d %d",&v,&i);
	insert_at_any_index(head,v,i);
	display(head);
return 0;
}
