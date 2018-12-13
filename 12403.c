#include<stdio.h>
#include<string.h>
int main()
{
    int T,i,tk,sum=0;
    char a[10];
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%s",a);
        if(strcmp(a,"donate")==0)
        {
            scanf("%d",&tk);
            sum=sum+tk;
        }

        if(strcmp(a,"report")==0)
        {
            printf("%d\n",sum);
        }
    }
    return 0;
}
