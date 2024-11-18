 #include <iostream>
#include <algorithm> 
using namespace std;

void bubble(int a[], int n)
{
    int i, j, t;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)  
        {
            if (a[j] > a[j+1])
            {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}

int main()
{
    int t, j = 0;
    cin >> t;
    int ans[t];
    
    while (t--)
    {
        int n;
        cin >> n;
        if (n < 3)
        {
            cout << "Array must have at least 3 elements" << endl;
            continue;
        }
        
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        
        bubble(a, n);
        
        int l = a[n-1] - a[2];
        int r = a[n-3] - a[0];
        int min_diff = min(l, r);
        ans[j++] = min_diff;
    }

    for (int i = 0; i < j; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}
