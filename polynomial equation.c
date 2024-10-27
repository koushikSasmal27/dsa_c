#include<stdio.h>
#include<stdlib.h>
struct node
{	int expo;
	double coeff;
	
	struct node*next;
	
};
struct node*insert(struct node*head,double co,int ex)
{
	struct node* ptr = (struct node*) malloc(sizeof(struct node));
	ptr->expo=ex;
	ptr->coeff=co;
	ptr->next=NULL;
	 // If the list is empty or new node has larger exponent, insert at the head
	if(head==NULL||head->expo<ex)
	{
		ptr->next=head;
		return ptr;
	}
	else
	{
		struct node*temp=head;
		 // Traverse to find the correct position for the new node
		while(temp->next!=NULL&& temp->next->expo>ex)
		{
			temp=temp->next;
		}
		// Insert the new node at the correct position
		ptr->next=temp->next;
		temp->next=ptr;
		
	}
	return head;
}
void display(struct node*head)
{
	struct node*temp=head;
	while(temp!=NULL)
	{
		printf("%.2lfX^%d",temp->coeff,temp->expo);
		if(temp->next!=NULL)
		{
			printf("+");
		}
		temp=temp->next;
	}
}
struct node*create(struct node*head)
{
	int n,i;
	int ex;
	double co;
	printf("Enter the number of terms:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
			printf("Enter the coefficient for term %d:",i+1);
			scanf("%lf",&co);
			printf("Enter the exponent for term %d:",i+1);
			scanf("%d",&ex);
			head=insert(head,co,ex);
	}
	return head;
}
struct node*polyadd(struct node*head1,struct node*head2)
{
	struct node*head3=NULL;
	while(head1!=NULL&&head2!=NULL)
	{
		if(head1->expo==head2->expo)
		{
			head3=insert(head3,head1->coeff+head2->coeff,head2->expo);
			head1=head1->next;
			head2=head2->next;
		}
		else if(head1->expo>head2->expo)
		{
			head3=insert(head3,head1->coeff,head1->expo);
			head1=head1->next;
		}
		else
		{
			head3=insert(head3,head2->coeff,head2->expo);
			head2=head2->next;
		}
		
	}
	while(head1!=NULL)
	{
		head3=insert(head3,head1->coeff,head1->expo);
		head1=head1->next;
	}
	while(head2!=NULL)
	{
		head3=insert(head3,head2->coeff,head2->expo);
			head2=head2->next;
	}
	display(head3);
}
int main()
{
	struct node*head1=NULL;
	struct node*head2=NULL;
	head1=create(head1);
	display(head1);
	printf("\n");
	head2=create(head2);
	display(head2);
	printf("\n");
	printf("sum of polynomial equation=");
	polyadd(head1,head2);
	return 0;
}
