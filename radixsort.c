#include<stdio.h>
#include<math.h>
void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int max(int a[],int n)
{
    int t=a[0];
    for(int i=0;i<n;i++)
    {
        if(t<a[i])
        {
            t=a[i];
        }
    }
    return t;
}
void countsort(int a[],int n,int exp)
{
    int output[n];
    int count[10]={0};

    //first loop counts number of digits
    for(int i=0;i<n;i++)
    {
        count[(a[i]/exp)%10]++;
    }

    //second loop  calculates cumulative count
    for(int i=1;i<10;i++)
    {
        count[i]+=count[i-1];
    }

    //loop witch  puts elements in sorted order
    for(int  i=n-1;i>=0;i--){
       output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    //loop witch  copies the sorted elements to the original array
    for(int i=0;i<n;i++)
    {
        a[i]=output[i];
    }
}
void radixsort(int a[],int n)
{
    int m=max(a,n);
    for(int exp=1; m/exp>0;exp*=10){
        countsort(a,n,exp);
    }
}
main()
{
    int a[]={31,29,471,8,91,66};
    int n=sizeof(a)/sizeof(a[0]);
    printf("array before sorting: ");
    print(a,n);
    printf("array after sorting: ");
    radixsort(a,n);
    print(a,n);
}