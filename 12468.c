#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a,b,x,y;

    for(;;)
    {
        scanf(" %d %d",&a,&b);

        if(a==-1 && b==-1)
        {
            break;
        }

        x=abs(a-b);
        y=100-x;

        if(x>y)
            printf("%d\n",y);
        else
            printf("%d\n",x);
    }

    return 0;
}
