#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
	struct node*prev;
};
struct node*create(struct node*head,int d)
{
	struct node*new=(struct node*)malloc(sizeof(struct node));
	new->data=d;
	new->next=NULL;
	new->prev=NULL;
	if(head==NULL)
	{
		new->next=head;
		head=new;
		return head;	
	}
	struct node*h=head;
	while(h->next!=NULL)
	{
		h=h->next;
	}
	h->next=new;
	new->prev=h;
	new->next=NULL;
	return head;
}
void dis(struct node*head)
{
	struct node*h=head;
	while(h!=NULL)
	{
		printf("%d->",h->data);
		h=h->next;	
	}
	printf("NULL\n");	
}
//void display(struct node*head)
//{
//	struct node*h=head;
//	while(h->next!=NULL)
//	{
//		h=h->next;	
//	}
//	while(h!=NULL)
//	{
//		printf("%d->",h->data);
//		h=h->prev;	
//	}	
//}

struct node*insertAtend(struct node*head,int d)
{
	struct node*new=(struct node*)malloc(sizeof(struct node));
	new->data=d;
	new->next=NULL;
	new->prev=NULL;
	struct node*h=head;
	while(h->next!=NULL)
	{
		h=h->next;
	}
	h->next=new;
	new->prev=h;
	return head;
}
struct node*deletAtend(struct node*head)
{
	if(head==NULL)
	{
		printf("list is empty:");
		return head;
	}
	
	struct node*h=head;
	while(h->next->next!=NULL)
	{
		h=h->next;
	}
	free(h->next);
	h->next=NULL;
	return head;
}
struct node*insertAtbegining(struct node*head,int d)
{
	struct node*new=(struct node*)malloc(sizeof(struct node));
	new->data=d;
	new->next=head;
	new->prev=NULL;
	head->prev=new;
	head=new;
	
	
	return head;
}
struct node*deletAtbegining(struct node*head)
{
	if(head==NULL)
	{
		printf("list is empty:");
		return head;
	}
	head=head->next;
	free(head->prev);
	head->prev=NULL;
	return head;
}
struct node*insertAtindex(struct node*head,int d,int i)
{
	int j=0;
	struct node*new=(struct node*)malloc(sizeof(struct node));
	new->data=d;
	new->next=NULL;
	new->prev=NULL;
	if(i==0)
	{
		head=insertAtbegining(head,d);
		return head;
	}
	struct node*h=head;
	while(h!=NULL && j<i-1)
	{
		h=h->next;
		j++;
	}
	if(h==NULL)
	{
		printf("\n index is out of bound");
		free(new);
		return head;
	}
	struct node*temp=h->next;
	h->next=new;
	new->next=temp;
	new->prev=h;
	// If temp is not NULL, set its previous pointer to new_node
    if (temp != NULL) {
        temp->prev =new;
    }
	return head;
}


struct node*deletAtindex(struct node*head,int i)
{
	if(head==NULL)
	{
		printf("\nlist is empty");
		return NULL;
	}
	int j=0;
	if(i==0)
	{
		head=deletAtbegining(head);
		return head;
	}
	struct node*h=head;
	while(h->next!=NULL && j<i-1)
	{
		h=h->next;
		j++;
	}
	if(h->next==NULL)
	{
		printf("\n index is out of bound");
		return head;
	}
	struct node*temp=h->next;
	h->next=temp->next;
	free(temp);
	return head;
}
int main() {
    int n, d,i, choice;
    struct node* head = NULL;
    
    do {
        printf("\n----- Menu -----\n");
        printf("1. Create linked list\n");
        printf("2. Display linked list\n");
        printf("3. Insert at the end\n");
        printf("9. Delet at the end\n");
        printf("4. Insert at the beginning\n");
        printf("8. Delet at the beginning\n");
        printf("5. Insert at the index\n");
        printf("10. Delet at the index\n");
        printf("6. Delet at the beginning\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of terms: ");
                scanf("%d", &n);
                while (n > 0) {
                    printf("Enter the data of node: ");
                    scanf("%d", &d);
                    head = create(head, d);
                    n--;
                }
                break;

            case 2:
                dis(head);
                break;

            case 3:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &d);
                head = insertAtend(head, d);
                break;
            case 9:
                head = deletAtend(head);
                break;

            case 4:
                printf("Enter the data to insert at the beginning: ");
                scanf("%d", &d);
                head = insertAtbegining(head, d);
                break;
			case 5:
                printf("Enter the data to insert at the index: ");
                scanf("%d", &d);
                 printf("Enter the index to insert  the data: ");
                scanf("%d", &i);
                head = insertAtindex(head, d,i);
                break;
            case 10:
                 printf("Enter the index to delet  the data: ");
                scanf("%d", &i);
                head = deletAtindex(head,i);
                break;
            case 6:
            	head=deletAtbegining(head);
            case 7:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
