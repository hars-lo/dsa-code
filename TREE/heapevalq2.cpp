#include<iostream>
using namespace std;
class kthlargest{
    public:
    int a[100];
    int k;
    int n;
    kthlargest(int  arr[], int size, int k1){

    {
        k=k1;
        n=size;
        for(int i=0;i<size;i++)
        {
            a[i]=arr[i];
        }
    }
    }
       void swapp(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
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
        swapp(&a[i], &a[largest]);  // Passing addresses to swap
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
        swapp(&a[0], &a[i]);  // Passing addresses to swap
        // Do heapify for remaining elements
        heapify(a, i, 0);
    }
}
    int add(int m)
    {
        a[n]=m;
        n++;
        heapsort(a,n);
        return a[k-1];
    }
    

};
int main()
{
    int arr[]={4,5,8,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k=3;
    kthlargest obj(arr,size,k);
    cout<<obj.add(3)<<endl;
    cout<<obj.add(2)<<endl;
    cout<<obj.add(5);
    return 0;
}