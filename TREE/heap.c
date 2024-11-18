#include<stdio.h>
#include<stdlib.h>

// Modified swap function to pass by reference
void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

// Function to heapify the array
void heapify(int a[], int n, int i)
{
    int largest = i;  // Set the current root as largest
    int l = 2 * i + 1;  // Left child
    int r = 2 * i + 2;  // Right child

    // Check if left child exists and is greater than root
    if (l < n && a[l] > a[largest])
    {
        largest = l;
    }

    // Check if right child exists and is greater than largest so far
    if (r < n && a[r] > a[largest])
    {
        largest = r;
    }

    // If largest is not the root
    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);  // Recursively heapify the affected sub-tree
    }
}

// Function to perform heap sort
void heapsort(int a[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }

    // One by one extract elements from heap
    for (int i = n - 1; i >= 0; i--)
    {
        // Move current root to end
        swap(&a[0], &a[i]);

        // Call max heapify on the reduced heap
        heapify(a, i, 0);
    }
}

// Function to print the array
void print(int a[], int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int main()
{
    int a[] = {12, 2, 4, 55, 65, 12, 100};
    int n = sizeof(a) / sizeof(a[0]);
    print(a, n);        // Print original array
    heapsort(a, n);     // Perform heap sort
    print(a, n);        // Print sorted array
    return 0;
}
