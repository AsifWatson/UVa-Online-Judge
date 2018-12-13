#include<stdio.h>
#include<string.h>

int sumDigit(int s)
{
    int Sum=0,a,b;
    for(;;)
    {
        a=s/10;
        b=s%10;
        s=a;
        Sum=Sum+b;
        if(a==0)
            break;
    }
    if(Sum<10)
        return Sum;
    else
        return sumDigit(Sum);
}

int main()
{
    char str[25];
    char str1[25];
    int sum,sum1,i,a,b,a1,b1,m,n;
    double x,y;
    while(gets(str))
    {
        x=0;
        y=0;
        sum=0;
        sum1=0;
        gets(str1);
        for(i=0;i<strlen(str);i++)
        {
            a1=str[i];
            if(a1>64 && a1<91)
                a=str[i]-64;
            else if(a1>96 && a1<123)
                a=str[i]-96;
            else
                continue;

            sum=a+sum;

        }
        for(i=0;i<strlen(str1);i++)
        {
            b1=str1[i];
            if(b1>64 && b1<91)
                b=str1[i]-64;
            else if(b1>96 && b1<123)
                b=str1[i]-96;
            else
                continue;

            sum1=b+sum1;
        }

        m=sumDigit(sum);
        n=sumDigit(sum1);

        if(m>n)
            printf("%.2lf %%\n",(100*(double)n)/(double)m);
        else
            printf("%.2lf %%\n",(100*(double)m)/(double)n);
    }
    return 0;
}
