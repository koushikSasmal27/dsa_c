#include<stdio.h>
#include<stdlib.h>
struct Queue
{
 int size;
 int r;
 int f;
 int *a;	
};
int is_full(struct Queue *q)
{
	if(q->r==q->size-1)
	{
		return 1;
	}
	return 0;
}
int is_empty(struct Queue *q)
{
	if(q->r==q->f)
	{
		return 1;
	}
	return 0;
}
void enqueue(struct Queue *q,int v)
{
	if(is_full(q))
	{
		printf("queue overflow");
	}
	else
	{
		q->r++;
		q->a[q->r]=v;
		printf("\n%d\n",q->a[q->r]);
	}
}
int dequeue(struct Queue *q)
{
	int k=-1;
	if(is_empty(q))
	{
		printf("queue underflow\n");
	}
	else
	{
		
		q->f++;
		k=q->a[q->f];
	}
	return k;
}
void dis(struct Queue *q)
{
	int i;
	for(i=q->f+1;i<=q->r;i++)
	{
		printf(" %d ",q->a[i]);
	}
	printf("\n");
}

int main()
{
	struct Queue *q=(struct Queue*)malloc(sizeof(struct Queue));
	q->size=3;
	q->r=-1;
	q->f=-1;
	q->a=(int*)malloc(q->size*sizeof(int));
	int l,v;
	do{
		
		printf("Enter the number for enqueue(1) for deque(2) for display(3):");
		scanf("%d",&l);
		switch(l)
		{
			case 1:printf("\n enter the value");
					scanf("%d",&v);
					enqueue(q, v);
					break;
			case 2:printf("dequeue element %d",dequeue(q));
					break;
			case 3:dis(q);
		}
	}while(l!=0);
	
	return 0;
}


