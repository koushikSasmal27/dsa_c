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
	for(i=1;i<n;i++)
	{
		int tem=a[i];
		j=i-1;
		while(j>=0&&a[j]>tem)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=tem;
	}
	printf("\n sorted array:");
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	return 0;
}
