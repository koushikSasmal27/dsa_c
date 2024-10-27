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
		ptr->next=head;
		return ptr;
	}
	while(h->next!=NULL)
	{
		h=h->next;
	}
	h->next=ptr;
	return head;
}
struct node*delet_at_beginning(struct node*head)
{
	if(head!=NULL)
	{
	struct node*ptr1=head;
	head=head->next;
	free(ptr1);
	return head;	
	}
	else{
		printf("link list is empty");
		return NULL;
	}
	
}
struct node*delet_at_end(struct node*head)
{
	if(head==NULL)
	{
		printf("LInk list is empty");
		return NULL;
	}
	
    // If the list has only one node
		if(head->next==NULL)
	{
		free(head);
		return NULL;
	}
	
	
	struct node*ptr=head;

	while(ptr->next->next!=NULL)
	{
		ptr=ptr->next;
		
	}
	free(ptr->next);
	ptr->next=NULL;
	return head;
}
struct node*delet_at_between(struct node*head,int index)
{
	if(head==NULL)
	{
		printf("Linklist is emapty");
		return head;
	}
	if(index==0)
	{
		return delet_at_beginning(head);
	}
	int i=0;
	
	struct node*ptr=head;

		while(i<index-1 && ptr->next!=NULL)
	{
		ptr=ptr->next;
		i++;
	}
	if(ptr->next==NULL)
	{
		printf("Invalid position");
		return head;
	}
	struct node*temp=ptr->next;
	ptr->next=temp->next;
	
	
	free(temp);
	return head;
}
void display(struct node*head)
{
	struct node*s=head;
	while(s!=NULL)
	{
		printf("%d",s->data);
		if(s->next!=NULL)
		{
			printf("->");
		}
		s=s->next;
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
	printf("\nenter the choice->1 for delet at the beginning , 2-> for delet at the end or 3 for delet at between,4 for dispaly ,0 for exit");
	scanf("%d",&ch);
	switch(ch)
	{
		
		case 1:
				head=delet_at_beginning(head);
				break;
		case 2:
				head=delet_at_end(head);
				break;
		case 3:printf("Enter the index at which you want to delet:");
				scanf("%d",&i);
				head=delet_at_between(head,i);
				break;
		case 4:display(head);
				break;
				
		default:printf("Wrong choice");
	}
	}while(ch);
	return 0;
	
}
