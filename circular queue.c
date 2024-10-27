#include<stdio.h>
#include<stdlib.h>
struct queue{
	int size;
	int r;
	int f;
	int *a;
};
int is_full(struct queue *q)
{
	if((q->r+1)%q->size==q->f)
	{
		return 1;
	}
	return 0;
}
int is_empty(struct queue *q)
{
	if(q->r==q->f)
	{
		return 1;
	}
	return 0;
}
void enqueue(struct queue *q, int v)
{
	if(is_full(q))
	{
		printf("Queue is full\n");
	}
	else
	{
		q->r=(q->r+1)%q->size;
		q->a[q->r]=v;
	}
}
int dequeue(struct queue *q)
{
	int k=-1;
	if(is_empty(q))
	{
		printf("Queue is empty");
	}
	else
	{
		q->f=(q->f+1)%q->size;
		k=q->a[q->f];
		
	}
	return k;
}


void dis(struct queue *q) {
    int i;
    if (is_empty(q)) {
        printf("\n Queue is empty\n");
        return;
    }
    printf("\n Queue elements: ");
    for (i = (q->f + 1) % q->size; i != (q->r + 1) % q->size; i = (i + 1) % q->size) {
        printf("%d ", q->a[i]);
    }
    printf("\n");
}

int main()
{
	struct queue *q=(struct queue*)malloc(sizeof(struct queue));
		q->size=5;
		q->r=0;
		q->f=0;
		q->a=(int*)malloc(q->size*sizeof(int));
		int l,v,o;
	do{
		
		printf("\nfor enqueue(1) for deque(2):");
		scanf("%d",&l);
		switch(l)
		{
			case 1:printf("\n enter the value: ");
					scanf("%d",&v);
					enqueue(q, v);
					break;
			case 2:o=dequeue(q);
					if(o!=-1)
					{
						printf("\n dequeue element %d",o);
					}
					else
					{
						
					}
					
					break;
				
			case 3:dis(q);
		}
	}while(l!=0);
		
		return 0;
		
}
