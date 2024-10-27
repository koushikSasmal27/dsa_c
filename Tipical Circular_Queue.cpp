#include<stdio.h>
#include<stdlib.h>
struct queue{
	int r,f;
	int size;
	int *a;
};
int isfull(struct queue*s)
{
	return (((s->r+1)%s->size==s->f)||(s->f==0 && s->r==s->size-1));
}
int isempty(struct queue*s)
{
	return (s->r==s->f && s->f==-1);
}
void push(struct queue*s,int v)
{
	if(isfull(s))
	{
		printf("stack is overflow\n");
		return ;
	}
	if(s->f==-1)
	{
		s->f=0;
		s->r=0;
	}
	else{
		s->r=(s->r+1)%s->size;
	}
	
	s->a[s->r]=v;
}
int pop(struct queue*s)
{
	int v=s->a[s->f];
	
	if(isempty(s))
	{
		printf("stack is underflow\n");
		return -1;
	}
	if(s->r==s->f)
	{
		s->r=-1;
		s->f=-1;
		
	}
	else{
		s->f=(s->f+1)%s->size;
	}
	
	return v;	
}

void display(struct queue*s)
{
	int i;
	printf("Stack elements are:");
	for(i=s->f;i!=s->r;i=(i+1)%s->size)
	{
		printf(" %d ",s->a[i]);
	}
	printf("%d",s->a[s->r]);
	printf("\n");
}
int main()
{
	struct queue*s=(struct queue*)malloc(sizeof(struct queue));
	s->size=3;
	s->r=-1;
	s->f=-1;
	s->a=(int*)malloc(s->size*sizeof(int));
	int ch,v;
	
	do{
		printf("Enter the choice:\n 1 for push\n 2 for pop\n 3 for peek\n4 for dispaly\n  0 for exit: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the elment: ");
				scanf("%d",&v);
				push(s,v);
				break;
			case 2:pop(s);
					break;
			case 4:display(s);
					break;
			
		}
	}while(ch);
	
	return 0;
}
