#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,rem;
    while(scanf("%d",&n))
    {
        if(n==0)
        {
            break;
        }
        int x=n;
        int arr[50];
        int j=0;
        while(x!=0)
        {
            rem = x%2;
            arr[j++]=rem;
            x=x/2;
        }
        cout<<"The parity of ";
        int coun = 0;
        for(int i=j-1;i>=0;i--)
        {
            cout<<arr[i];
            if(arr[i]==1)
            {
                coun++;
            }
        }
        cout<<" is "<<coun<<" (mod 2)."<<endl;
    }
}
