#include<stdio.h>

void input(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void insert(int a[], int *n, int x, int p) {    
    int i;
    for (i = *n - 1; i >= p - 1; i--) {
        a[i + 1] = a[i];
    }
    a[p - 1] = x;
    *n = *n + 1;

    printf("Array after insertion: ");
    for (i = 0; i < *n; i++) {
        printf("%d  ", a[i]);
    }
    printf("\n");
}

void delet(int a[], int *n, int p) {    
    int i;
    for (i = p - 1; i < *n - 1; i++) {
        a[i] = a[i + 1];
    }
    *n = *n - 1;

    printf("Array after deletion: ");
    for (i = 0; i < *n; i++) {
        printf("%d  ", a[i]);
    }
    printf("\n");
}

int main() {
    int arr[100], n, x, p,i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n > 100) {
        printf("Size exceeds maximum array limit.\n");
        return 1;
    }
    
    printf("Enter the array elements:\n");
    input(arr, n);

    printf("Enter the element to insert: ");
    scanf("%d", &x);
    printf("Enter the position to insert the element: ");
    scanf("%d", &p);

    if (p < 1 || p > n + 1) {
        printf("Invalid position!\n");
        return 1;
    }

    printf("Array before insertion: ");
    for ( i = 0; i < n; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");

    insert(arr, &n, x, p);

    printf("Enter the position to delete the element: ");
    scanf("%d", &p);

    if (p < 1 || p > n) {
        printf("Invalid position!\n");
        return 1;
    }

    delet(arr, &n, p);

    return 0;
}

