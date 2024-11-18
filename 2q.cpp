#include<iostream>
using namespace std;
void bubble(int a[],int n)
{
    int i,j,t;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}
int main(){
    // int x=min(12,13);
    // cout<<x;
    int t,j=0;
    cin>>t;
    int ans[t];
    while(t--)
    {
        int n;
        cin>> n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>> a[i];
        }  
        bubble(a,n);
        int l=a[n-1]-a[2];
        int r=a[n-3]-a[0];
        int ar=min(l,r);
        ans[j] =ar;
        j++;
    }
    for(int i=0;i<j;j++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}