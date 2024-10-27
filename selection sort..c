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
		int min=i;
		
		for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
			{
				min=j;
			}
		}
		if(a[min]!=a[i])
		{
			int tem=a[min];
			a[min]=a[i];
			a[i]=tem;
		}
	}
	printf("\n sorted array:");
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	return 0;
}
