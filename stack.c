/*
#include<stdio.h>
#include<stdlib.h>
struct stack{
	int top;
	int size;
	int *a;
};
int is_full(struct stack *p)
{
	if(p->top==p->size-1)
	{
		printf("%d",p->top);
		return 1;
	}
	return 0;
}
int is_empty(struct stack *p)
{
	if(p->top==-1)
	{
		
		return 1;
	}
	return 0;
}
void pop(struct stack *p)
{
	if(is_empty(p))
	{
		printf("stack underflow");
	}
	else
	{
		p->top--;
	}
}

void push(struct stack *p,int v)           
{
	if(is_full(p))
	{
		printf("stack overflow");
	}
	else
	{
		p->top++;
		p->a[p->top]=v;
	}
}
void dis(struct stack *p)
{int i;
	for(i=0;i<=p->top;i++)
	{
		printf(" %d ",p->a[i]);
	}
}
void peek(struct stack *p,int i)
{
	int l=p->top-i+1;
	if(l<0)
	{
		printf("invalid potition");
		
	}
	else
	{
		printf("in %d position %d element present",i,p->a[l]);
	}
}

int main()
{
	struct stack *s=(struct stack*)malloc(sizeof(struct stack));
	s->top=-1;
	s->size=20;
	s->a=(int*)malloc(s->size*sizeof(int));
	int j,v,i;
	do{
		printf("\n for push(1),for pop(2), for display(3),for peek(4),for end(0)");
		scanf("%d",&j);
		switch(j)
		{
			case 1:printf("\n enter element:");
				scanf("%d",&v);
					push(s,v);
					break;
			case 2:pop(s);
					break;
			case 3:dis(s);
					break;
			case 4:printf("\n entetr the position:");
			scanf("%d",&i);
					peek(s,i);
					break;
			
		}
	}while(j!=0);
	return 0;
}
*/

//for parentheses


/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
	int top;
	int size;
	char *arr;
};
int is_full(struct stack *p)
{
	if(p->top==p->size-1)
	{
//		printf("%d",p->top);
		return 1;
	}
	return 0;
}
int is_empty(struct stack *p)
{
	if(p->top==-1)
	{
		
		return 1;
	}
	return 0;
}




void pop(struct stack *p)
{
	if(is_empty(p))
	{
		printf("stack underflow");
	}
	else
	{
		p->top--;
	}
}

void push(struct stack *s,char v)           
{
	if(is_full(s))
	{
		printf("stack overflow");
	}
	else
	{
		s->top++;
		s->arr[s->top]=v;
	}
}
int  paren(char *a)
{
	struct stack *s=(struct stack*)malloc(sizeof(struct stack));
	s->top=-1;
	s->size=20;
	s->arr=(char*)malloc(s->size*sizeof(char));
	int i;
	for(i=0;a[i]!='\0';i++)
	{
		
		 if(a[i]=='(')
		{
			push(s,'(')	;                                                          //push
		}
		else if(a[i]==')')
		{
			if(is_empty(s))
			{
				return 0;
			}
			else
			{
			pop(s);	
			}
			
		}
	}
	if(is_empty(s))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	char *a;
	printf("Enter the equation:");
	char b[20];
	gets(b);
	a=b;
	if(paren(a))
	{
		printf("balanced");
		
	}
	else
	{
		printf("unbalanced");
	}
	
	return 0;
	
}
*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
	int top;
	int size;
	char *arr;
};
int is_full(struct stack *p)
{
	if(p->top==p->size-1)
	{
		printf("%d",p->top);
		return 1;
	}
	return 0;
}
int is_empty(struct stack *p)
{
	if(p->top==-1)
	{
		
		return 1;
	}
	return 0;
}




void pop(struct stack *p)
{
	if(is_empty(p))
	{
		printf("stack underflow");
	}
	else
	{
		p->top--;
	}
}

void push(struct stack *s,char v)           
{
	if(is_full(s))
	{
		printf("stack overflow");
	}
	else
	{
		s->top++;
		s->arr[s->top]=v;
	}
}
int  paren(char *a)
{
	struct stack *s=(struct stack*)malloc(sizeof(struct stack));
	s->top=-1;
	s->size=20;
	s->arr=(char*)malloc(s->size*sizeof(char));
	int i;
	for(i=0;a[i]!='\0';i++)
	{
		
		 if(a[i]=='(')
		{
			push(s,'(')	;           //push
		}
		else if(a[i]==')')
		{
			if(is_empty(s))
			{
				return 0;
			}
			else
			{
			pop(s);	
			}
			
		}
	}
	if(is_empty(s))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	char *a;
	printf("Enter the equation:");
	char b[20];
	gets(b);
	a=b;
	if(paren(a))
	{
		printf("balanced");
		
	}
	else
	{
		printf("unbalanced");
	}
	
	return 0;
	
}

*/







/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
	int top;
	int size;
	char *arr;
};
int is_full(struct stack *p)
{
	if(p->top==p->size-1)
	{
		printf("%d",p->top);
		return 1;
	}
	return 0;
}
int is_empty(struct stack *p)
{
	if(p->top==-1)
	{
		
		return 1;
	}
	return 0;
}

char pop(struct stack *p)
{
	if(is_empty(p))
	{
		printf("stack underflow");
	}
	else
	{
		char l=p->arr[p->top];
		p->top--;
		return l;
	}
}

void push(struct stack *s,char v)           
{
	if(is_full(s))
	{
		printf("stack overflow");
	}
	else
	{
		s->top++;
		s->arr[s->top]=v;
	}
}
int match(char a,char b)
{
	if((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']'))
	{
		return 1;
	}
	


  return 0;  
}
int  paren(char *a)
{
	struct stack *s=(struct stack*)malloc(sizeof(struct stack));
	s->top=-1;
	s->size=20;
	s->arr=(char*)malloc(s->size*sizeof(char));
	int i;
	for(i=0;a[i]!='\0';i++)
	{
		char k;
		
		 if(a[i]=='('||a[i]=='{'||a[i]=='[')
		{
			push(s,a[i]);           //push
		}
		else if(a[i]==')'||a[i]=='}'||a[i]==']')
		{
			
			if(is_empty(s))
			{
				return 0;
			}
			else
			{
			 k=pop(s);
			   if(match(k,a[i]))
			   {
			 	
			   }
			   else
			   {
			   	return 0;
			   }
			}
			
		}
	}
	if(is_empty(s))
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
	free(s);
	free(s->a);
}
int main()
{
	char *a;
	printf("Enter the equation:");
	char b[20];
	gets(b);
	a=b;
	if(paren(a))
	{
		printf("balanced");
		
	}
	else
	{
		printf("unbalanced");
	}
	
	return 0;
	
}
*/






/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
	int top;
	int size;
	char *a;
};
int is_full(struct stack *p)
{
	if(p->top==p->size-1)
	{
		printf("%d",p->top);
		return 1;
	}
	return 0;
}
int is_empty(struct stack *p)
{
	if(p->top==-1)
	{
		
		return 1;
	}
	return 0;
}

char pop(struct stack *s)
{
	if(is_empty(s))
	{
		printf("stack underflow");
	}
	else
	{
		char l=s->a[s->top];
		s->top--;
		return l;
	}
}

void push(struct stack *s,char v)           
{
	if(is_full(s))
	{
		printf("stack overflow");
	}
	else
	{
		s->top++;
		s->a[s->top]=v;
	}
}
int isoperator(char ch)
{
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%')
	{
		return 1;
	}
	return 0;
}
int precedence(char a)
{
	if(a=='*'||a=='/')
	{
		return 3;
	}
	if(a=='-'||a=='+')
	{
		return 2;
	}
	else
	{
		return 0;
	}
	
}
char stacktop(struct stack *s)
{
	return s->a[s->top];
}
void infix_postfix(char *infix)
{
	struct stack *s=(struct stack*)malloc(sizeof(struct stack));
	s->top=-1;
	s->size=20;
	s->a=(char*)malloc(s->size*sizeof(char));
	char *postfix=(char*)malloc((strlen(infix)+1)*sizeof(char));
	int i=0;
	int j=0;
	while(infix[i]!='\0')
	{
		if(isoperator(infix[i]))
		{
			if(precedence(infix[i])>precedence(stacktop(s)))
			{
				push(s,infix[i]);
				i++;
			}
			else
			{
				postfix[j]=pop(s);
				j++;
			}
		}
		else
		{
			postfix[j]=infix[i];
			i++;
			j++;
		}
	}
	while(!is_empty(s))
	{
		postfix[j]=pop(s);
		j++;
	}
	puts(postfix);
}
int main()
{
	char *infix;
	char b[20];
	gets(b);
	infix=b;
	infix_postfix(infix);
	return 0;
}
*/
