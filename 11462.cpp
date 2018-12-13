#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n==0)
        {
            break;
        }
        int arr[n+2];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+n);
        cout<<arr[0];
        for(int i = 1; i < n; i++)
        {
            cout<<" "<<arr[i];
        }
        cout<<endl;

    }
    return 0;
}
