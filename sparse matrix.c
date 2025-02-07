#include<stdio.h>
int main()
{
	int i,j,m,n,a[20][20],c=0;
	printf("enter the no of row and column: ");
	scanf("%d %d",&m,&n);
	printf("\nEnter the elements of matrix:");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]!=0)
			{
				c++;
			}
		}
	}
	if(c<((m*n)*(2.0/3)))
	{
		printf("\nit is sparse matrix\n");
	
	int k=0;
	int b[10][10];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]!=0)
			{
				b[0][k]=i;
				b[1][k]=j;
				b[2][k]=a[i][j];
				k++;
			}
		}
	}
	printf("\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	}
	return 0;
}
