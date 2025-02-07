#include<stdio.h>
void input(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
}
int partition(int a[],int low,int high)
{
	int pivot=a[low];
	int i=low+1;
	int j=high;
	do{
		while(a[i]<=pivot)
	{
		i++;
	}
	while(a[j]>pivot)
	{
		j--;
	}
	if(i<j)
	{
		int tem=a[i];
		a[i]=a[j];
		a[j]=tem;
	}
	}while(i<j);
	
	int tem=a[low];
	a[low]=a[j];
	a[j]=tem;
	
	return j;
}


void quick(int a[],int low,int high)
{
	if(low<high)
	{
	int partition_index=partition(a,low,high);//index of pivot after partition
	quick(a,partition_index+1,high);//sorting right sub array
	quick(a,low,partition_index-1);//sorting left sub array	
	}
	
	
	
}

void output(int* a,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		 printf("%d  ", a[i]);
	}
	
}
int main()
{
	int arr[40],n;
	printf("enter the size on an array:\n");
	scanf("%d",&n);
	
	printf("enter the array elements:\n");
	input(arr,n);
	
	printf("array after sorting:");
	quick(arr,0,n-1);
	
	
	output( arr, n);
	

return 0;
}

