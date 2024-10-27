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
struct node*insert_beginning(struct node*head,int v)
{
	struct node*ptr1=(struct node*)malloc(sizeof(struct node));
	ptr1->data=v;
	ptr1->next=NULL;
	ptr1->next=head;
	return ptr1;
}
struct node*insert_at_end(struct node*head,int v)
{
	struct node*ptr1=(struct node*)malloc(sizeof(struct node));
	ptr1->data=v;
	ptr1->next=NULL;
	struct node*ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=ptr1;
	return head;
}
struct node*insert_at_between(struct node*head,int v,int index)
{
	
	int i=0;
	struct node*ptr1=(struct node*)malloc(sizeof(struct node));
	ptr1->data=v;
	ptr1->next=NULL;
	if(index==0)
	{
		ptr1->next=head;
		head=ptr1;
		return head;
	}
	struct node*ptr=head;
	while(ptr!=NULL && i!=index-1)
	{
		ptr=ptr->next;
		i++;
	}
	if(ptr==NULL)
	{
		printf("\n Invalid index\n");
		return head;
	}
	ptr1->next=ptr->next;
	ptr->next=ptr1;
	return head;
}
void display(struct node*start)
{
	while(start!=NULL)
	{
		printf("%d",start->data);
		if(start->next!=NULL)
		{
			printf("->");
		}
		start=start->next;
	}
}
int main()
{int value,i;
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
	int ch;
	
	do{
	printf("\nenter the chooice->1 for insert at the beginning , 2-> for insert at the end or 3 for insert at between,4 for dispaly ,0 for exit");
	scanf("%d",&ch);
	switch(ch)
	{
		
		case 1:printf("Enter the the of new node:");
				scanf("%d",&value);
				head=insert_beginning(head,value);
				break;
		case 2:
				printf("Enter the number of new node:");
				scanf("%d",&value);
				head=insert_at_end(head,value);
				break;
		case 3:
				printf("Enter the value of new node and enter index number:");
				scanf("%d %d",&value,&i);
				head=insert_at_between(head,value,i);
				break;
		case 4:display(head);
				break;
				
		default:printf("Wrong chooice");
	}
	}while(ch);
	return 0;
	
}
