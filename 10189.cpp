#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n,m,i,j,c,k=1;
    char str[110][110];
    int arr[110][110];
    while(scanf("%d %d",&n,&m))
    {
        if(m==0 && n==0)
            break;

        getchar();

        if(k>1)
             printf("\n");

        for(i=0;i<n;i++)
        {
            gets(str[i]);
        }

        for(i=0;i<110;i++)
        {
            for(j=0;j<110;j++)
            {
                arr[i][j]=0;
            }
        }

        printf("Field #%d:\n",k);

       for(i=0;i<n;i++)
       {
           for(j=0;j<m;j++)
           {
               if(str[i][j]=='*')
               {
                   arr[i-1][j-1]++;
                   arr[i-1][j]++;
                   arr[i-1][j+1]++;

                   arr[i][j-1]++;
                   arr[i][j+1]++;

                   arr[i+1][j-1]++;
                   arr[i+1][j]++;
                   arr[i+1][j+1]++;

               }
           }
       }

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(str[i][j]=='*')
                {
                    arr[i][j]=-1;
                }
                if(arr[i][j]==-1)
                    printf("*");
                else
                    printf("%d",arr[i][j]);
            }
            printf("\n");
        }
        k++;
    }
    return 0;
}
