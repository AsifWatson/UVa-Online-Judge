#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int st,int ed,int x)
{
    while (st<=ed)
    {
        int mid=st+(ed-st)/2;

        if (arr[mid]==x)
            return mid;

        if (arr[mid]<x)
            st=mid+1;

        else
            ed=mid-1;
    }

    return -1;
}

int func(int arr[],int st,int ed,int x)
{
    if(x<arr[st])
    {
        return -1;
    }
    if(x>arr[ed])
    {
        return -2;
    }
    while (st<=ed)
    {
        int mid=st+(ed-st)/2;

        if (arr[mid]<x && arr[mid+1]>x)
            return mid;

        if (arr[mid]<x)
            st=mid+1;

        else
            ed=mid-1;
    }

}

int main()
{
    ///freopen("in.txt", "rt", stdin);
    ///freopen("out.txt", "wt", stdout);

    int n,q,srch,st,ed,val,index,ar,z;
    int arr[50002];
    while(scanf("%d",&n)!=EOF)
    {
        z=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&ar);
            if(i==0)
            {
                arr[z++]=ar;
            }
            if(arr[z-1]==ar)
            {
                continue;
            }
            arr[z++]=ar;
        }

        scanf("%d",&q);
        for(int j=0;j<q;j++)
        {
            scanf("%d",&srch);
            st=0;
            ed=z-1;
            if(z==1)
            {
                if(srch==arr[0])
                {
                    printf("X X\n");
                    continue;
                }
                if(srch>arr[0])
                {
                    printf("%d X\n",arr[0]);
                    continue;
                }
                if(srch<arr[0])
                {
                    printf("X %d\n",arr[0]);
                    continue;
                }
            }
            index=binarySearch(arr,st,ed,srch);
            if(index>-1 && index<z)
            {
                if(index>0 && index<z-1)
                {
                    printf("%d %d\n",arr[index-1],arr[index+1]);
                    continue;
                }
                if(index==0)
                {
                    printf("X %d\n",arr[index+1]);
                    continue;
                }
                if(index==z-1)
                {
                    printf("%d X\n",arr[index-1]);
                    continue;
                }

            }
            if(index==-1)
            {
                val=func(arr,st,ed,srch);
                if(val==-1)
                {
                    printf("X %d\n",arr[st]);
                    continue;
                }
                if(val==-2)
                {
                    printf("%d X\n",arr[ed]);
                    continue;
                }
                printf("%d %d\n",arr[val],arr[val+1]);
            }
        }
    }
    return 0;
}
