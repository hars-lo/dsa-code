#include<stdio.h>
#include<stdlib.h>

// Corrected swap function that takes pointers
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
    {
        largest = l;
    }
    if (r < n && a[r] > a[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(&a[i], &a[largest]);  // Passing addresses to swap
        heapify(a, n, largest);
    }
}

void heapsort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        // Replace starting element with last element
        swap(&a[0], &a[i]);  // Passing addresses to swap
        // Do heapify for remaining elements
        heapify(a, i, 0);
    }
}

int main()
{
    int a[] = {22, 1, 55, 67, 9, 11,10};
    int n = sizeof(a) / sizeof(a[0]);
    
    printf("\nBefore Sorting: ");
    print(a, n);
    
    heapsort(a, n);
    
    printf("\nAfter Sorting: ");
    print(a, n);
    
    if(n%2==0)
    {
        int m=n/2;
        float k=(a[m]+a[m-1])/2.0;
        printf("\nMedian: %f",k);
        
    }
    else{
        printf("\nMedian: %d",a[n/2]);
    }
    
    return 0;
}
