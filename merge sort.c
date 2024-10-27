tr5tr#include<stdio.h>
void merge(int a[], int l,int mid,int h)
{ int b[100];
	int i,j,k;
	i=l;
	j=mid+1;
	k=l;
	while(i<=mid&&j<=h)
	{
		
		
		if(a[i]<a[j])
		{
			
			b[k]=a[i];
			i++;
			k++;
		}
		else
		{
			b[k]=a[j];
			j++;
			k++;
		}
	}
	while(i<=mid)
	{
		b[k]=a[i];
			i++;
			k++;
	}
		while(j<=h)
	{
		b[k]=a[j];
			j++;
			k++;
	}
	for(i=0;i<=h;i++)
	{
		a[i]=b[i];
	}
}
void mergesort(int a[],int l,int h)
{
	
	if(l<h)
	{
		int mid;
		mid=(h+l)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,h);
		merge(a,l,mid,h);
	}
	
	
}
int main()
{
	int a[40];
	int h,l,n,i;
	printf("enter the size of an array:");
	scanf("%d",&n);
	printf("enter the array elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	l=0;
	h=n-1;
	mergesort(a,l,h);
	printf("Now the array elements:");
	for(i=0;i<=h;i++)
	{
		printf("%d",a[i]);
	}
}
