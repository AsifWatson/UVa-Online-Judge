#include<stdio.h>
int main()
{
    int a,f,x,y,i,j,k,t,l;
    char c;

    scanf("%d",&t);

    for(l=1;l<=t;l++)
    {
        scanf("%d",&a);
        scanf("%d",&f);

        if(a>9)
            return 0;

        for(k=1;k<=f;k++)
        {
            x=1;
            y=a-1;

            for(i=1;i<=a;i++)
            {
                for(j=1;j<=i;j++)
                {
                    printf("%d",x);
                }
                x++;
                printf("\n");
            }

            for(i=y;i>=1;i--)
            {
                for(j=i;j>=1;j--)
                {
                    printf("%d",y);
                }
                y--;
                if(i==1 && k==f && l==t)
                    break;
                printf("\n");
            }
            printf("\n");
        }
    }

    return 0;
}
