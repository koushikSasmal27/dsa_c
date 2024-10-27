#include<stdio.h>
#include<string.h>
void rev(char a[],int i)
{
	if(i==0)
	{
		printf("%c",a[i]);
		return ;
	}
	printf("%c",a[i]);
	rev(a,i-1);
}
int main()
{
	char a[100];
	fgets(a,sizeof(a),stdin);
	int len=strlen(a);
	if(a[len-1]=='\n')
	{
		a[len-1]=='\0';
	}
	rev(a,len-1);

}
