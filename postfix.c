#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
	int top;
	int size;
	char *a;
};
int isfull(struct stack *s)
{
	if(s->top==s->size-1)
	{
		return 1;
		
	}
	return 0;
}
int isempty(struct stack *s)
{
	if(s->top==-1)
	{
		return 1;
		
	}
	return 0;
}
void push(struct stack *s,char v)
{
	if(isfull(s))
	{
		printf("stack overflow\n");
	}
	else
	{
		s->top++;
		s->a[s->top]=v;
	}
}
char pop(struct stack *s)
{
	if(isempty(s))
	{
		printf("stack under flow");
	}
	else
	{
		char k=s->a[s->top];
		s->top--;
		return k;
	}
}
char stacktop(struct stack *s)
{
	if(!isempty(s))
	{
		return s->a[s->top];
	}
	return -1;
}
int isoperator(char n)
{
	if(n=='+'||n=='-'||n=='*'||n=='/'|| n=='%')
	{
		return 1;
	}
	return 0;
}
int precedance(char m)
{
	if(m=='+'||m=='-')
	{
		return 1;
	}
	else if(m=='*'||m=='/'||m=='%')
	{
		return 2;
	}
	else
	{
		return 0;
	}
}
void infix_postfix(char *infix)
{
	struct stack *s=(struct stack*)malloc(sizeof(struct stack));
	s->top=-1;
	s->size=100;
	s->a=(char*)malloc(s->size*sizeof(char));
	char *postfix=(char*)malloc((strlen(infix)+1)*sizeof(char));
	int i=0;
	int j=0;
	
	while(infix[i]!='\0')
	{
		
		if(isoperator(infix[i]))
		{
			if((precedance(infix[i]))>precedance(stacktop(s)))
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
	while(!isempty(s))
	{
		postfix[j]=pop(s);
		j++;
	}
	postfix[j]='\0';
	puts(postfix);
	free(s->a);
    free(s);
    free(postfix);
}
int main()
{
	char *infix;
	char b[100];
	printf("Enter the equation:");
	fgets(b,sizeof(b),stdin);
	infix=b;
	b[strcspn(b,"\n")]='\0';
	infix_postfix(infix);
	
	return 0;
}

