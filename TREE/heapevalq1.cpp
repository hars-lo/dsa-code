 #include <bits/stdc++.h>
using namespace std;
class medianFinder
{
   int arr[100];
   int size;

public:
   medianFinder() { size = 0; }
   void addNum(int num)
   {
      size++;
      arr[size - 1] = num;
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
   void streamMed()
   {
       heapsort(arr,size);
       if(size%2==0)
    {
        int m=size/2;
        float k=(arr[m]+arr[m-1])/2.0;
        printf("\nMedian: %f",k);
    }
    else{
        printf("\nMedian: %d",arr[size/2]);
    }
   }
};

int main()
{
	medianFinder m;
    m.addNum(1);
    m.addNum(2);
	m.streamMed();
	m.addNum(3);
	m.streamMed();
	m.addNum(4);
    m.addNum(5);
	m.streamMed();
	m.addNum(6);
	m.streamMed();
	return 0;
}