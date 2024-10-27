#include<stdio.h>
int main()
{
	int i,j,n,a[100],c;
	printf("\n enter the array size:");
	scanf("%d",&n);
	printf("\n Enter the array elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n unsorted array:");
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		c=0;
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int tem=a[j];
				a[j]=a[j+1];
				a[j+1]=tem;
				c=1;
			}
		}
		if(c==0)
		{
			break;
		}
	}
	printf("\n sorted array:");
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	return 0;
}
