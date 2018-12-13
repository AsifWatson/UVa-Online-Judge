#include<stdio.h>
#include<math.h>
int main()
{
    int i,a,b,d,count;
    double c;
    for(;;)
    {
        count=0;
        scanf("%d %d",&a,&b);
        if(a==0 && b==0)
        {
            break;
        }
        for(i=a;i<=b;i++)
        {
            c=sqrt(i);
            d=(int)(c*1000);
            if(d%1000==0)
            {
                count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
