#include<bits/stdc++.h>
using namespace std;

struct st
{
    int asci;
    int value;
};

void asciSort(struct st arr[],int c)
{
    int i,j,k;
    j=c;
    for(i=0;i<j-1;i++)
    {
        for(k=i+1;k<j;k++)
        {
            if(arr[i].value>arr[k].value)
            {
                struct st temp;
                temp.value=arr[i].value;
                temp.asci=arr[i].asci;

                arr[i].value=arr[k].value;
                arr[i].asci=arr[k].asci;

                arr[k].value=temp.value;
                arr[k].asci=temp.asci;
            }
            if(arr[i].value==arr[k].value)
            {
                if(arr[i].asci<arr[k].asci)
                {
                    struct st temp;
                    temp.value=arr[i].value;
                    temp.asci=arr[i].asci;

                    arr[i].value=arr[k].value;
                    arr[i].asci=arr[k].asci;

                    arr[k].value=temp.value;
                    arr[k].asci=temp.asci;
                }
            }
        }
    }
}

int main()
{

    char str[10000];
    int ln,i,j,k,n=0;
    int a[1000];
    struct st arr[1000];

    while(gets(str))
    {
        if(n>0)
        {
            printf("\n");
        }
        n++;
        for(i=0;i<96;i++)
        {
            a[i]=0;
        }
        ln=strlen(str);
        j=0;
        k=0;
        for(i=0;i<ln;i++)
        {
            a[str[i]-' ']++;
        }
        for(i=0;i<96;i++)
        {
            if(a[i]>0)
            {
                arr[j++].asci=i+32;
                arr[k++].value=a[i];
            }
        }
        asciSort(arr,j);

        for(i=0;i<j;i++)
        {
            printf("%d %d\n",arr[i].asci,arr[i].value);
        }
    }
    return 0;
}
