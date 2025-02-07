#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
	int top;
	int size;
	char *a;
};
int is_empty(struct stack*s)
{
	return (s->top==-1);
}
int is_full(struct stack*s)
{
	return (s->top==s->size-1); 
}
int peek(struct stack*s)
{
	if(!is_empty(s))
	{
		return s->a[s->top];
	}
	return -1;
}
void push(struct stack*s,char v)
{
	if(is_full(s))
	{
		printf("\nstack is over flow\n");
		return ;
	}
	s->top++;
	s->a[s->top]=v;
}
char pop(struct stack*s)
{
	if(is_empty(s))
	{
		printf("\nStack is empty\n");
		return -1;
	}
	char p=s->a[s->top];
	s->top--;
	return p;
	
}
int is_operator(char n)
{
	return (n=='+'||n=='-'||n=='*'||n=='/'||n=='^');
}
int precedence(char m)
{
	if((m=='+'||m=='-'))
	{
		return 1;
	}
	else if(m=='*'||m=='/')
	{
		return 2;
	}
	else if(m=='^')
	{
		return 3;
	}
	else
	{
		return 0;
	}
}

void infix_postfix(char *infix)
{
	struct stack*s=(struct stack*)malloc(sizeof(struct stack));
	s->top=-1;
	s->size=20;
	s->a=(char*)malloc(s->size*sizeof(char));
	char *postfix=(char*)malloc(strlen(infix+1)*sizeof(char));
	int i=0;
	int j=0;
	while(infix[i]!='\0')
	{
		if(!is_operator(infix[i]) && infix[i]!='(' && infix[i]!=')')
		{
			postfix[j++]=infix[i++];
		}
		else if(infix[i]=='(')
		{
			push(s,infix[i]);
			i++;
		}
		else if(infix[i]==')')
		{
			while(!is_empty(s) && peek(s)!='(' )
			{
				postfix[j++]=pop(s);
			}
			if(!is_empty(s) && peek(s)=='(')
			{
				pop(s);
			}
			i++;
		}
		else
		{
			while(!is_empty(s) && precedence(infix[i])<=precedence(peek(s)))
			{
				postfix[j++]=pop(s);
			}
			push(s,infix[i]);
			i++;
		}
	}
	while(!is_empty(s))
	{
		postfix[j]=pop(s);
		j++;
	}
	postfix[j]='\0';
	puts(postfix);
	free(s->a);
	free(s);
}
int main()
{
	char b[100];
	printf("Enter the infix expression");
	fgets(b,sizeof(b),stdin);
	b[strcspn(b,"\n")]='\0';
	puts(b);
	infix_postfix(b);
		
	return 0;
}
