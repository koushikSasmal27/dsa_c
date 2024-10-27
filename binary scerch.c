#include<stdio.h>

void input(int a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

int binary(int a[], int n, int k)
{
    int h, l, mid;
    h = n - 1;
    l = 0;
    
    while(l <= h)
    {
        mid = (l + h) / 2;
        if(k == a[mid])
        {
            return mid;
        }
        else if(k > a[mid])
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    
    return -1;
}

int main()
{
    int a[40], n, key;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the array elements (sorted): ");
    input(a, n);
    printf("\nEnter the key element: ");
    scanf("%d", &key);
    
    int index = binary(a, n, key);
    
    if(index != -1)
    {
        printf("%d is present at index %d.\n", key, index);
    }
    else
    {
        printf("%d is not present in the array.\n", key);
    }
    
    return 0;
}

