#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,a;
    int s[10000],ar[10000],arr[10000];
    char str[10000],str1[10000];

    while(scanf("%d",&n)!=EOF)
    {
        a=0;
        for(i=0;i<n-1;i++)
        {
            arr[i]=i+1;
        }

        for(i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
        }

        for(i=0;i<n-1;i++)
        {
            ar[i]=abs(s[i]-s[i+1]);
        }


        sort(ar,ar+(n-1));


        for(i=0;i<n-1;i++)
        {
            if(arr[i]!=ar[i])
            {
                a=1;
                break;
            }
        }

        if(a==1)
        {
            printf("Not jolly\n");
        }
        if(a==0)
        {
            printf("Jolly\n");
        }
    }
    return 0;
}
