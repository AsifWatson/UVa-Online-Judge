#include<bits/stdc++.h>
using namespace std;

int isDivisibleBy4(char str[])
{
    int sum=0;

    sum=10*(str[strlen(str)-2]-'0')+ (str[strlen(str)-1]-'0');

    if(sum%4==0)
        return 1;
    else
        return 0;
}

int isDivisibleBy100(char str[])
{

    if((str[strlen(str)-2]-'0')==0 && (str[strlen(str)-1]-'0')==0)
        return 1;
    else
        return 0;
}

int isDivisibleBy400(char str[])
{
    int sum=0;
    sum=10*(str[strlen(str)-4]-'0')+ (str[strlen(str)-3]-'0');

    if((str[strlen(str)-2]-'0')==0 && (str[strlen(str)-1]-'0')==0  && sum%4==0)
        return 1;
    else
        return 0;
}
int isDivisibleBy55(char str[])
{
    int sum=0;

    for(int i=0;i<strlen(str);i++)
    {
        if(i%2==0)
        {
            sum=sum+(str[i]-'0');
        }
        else
        {
            sum=sum-(str[i]-'0');
        }
    }

    if(sum%11==0 && ((str[strlen(str)-1]-'0')==0 || (str[strlen(str)-1]-'0')==5))
        return 1;
    else
        return 0;
}

int isDivisibleBy15(char str[])
{
    int sum=0;

    for(int i=0;i<strlen(str);i++)
    {
        sum = sum+(str[i]-'0');
    }

    if(sum%3==0 && (((str[strlen(str)-1]-'0')==0) || ((str[strlen(str)-1]-'0')==5)))
        return 1;
    else
        return 0;
}


int main()
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    int c,i=0,lp,h,b;
    char str[10000];

    while(scanf("%s",str)!=EOF)
    {
        if(i>0)
        {
            printf("\n");
        }

        c=0;
        lp=0;
        h=0;
        b=0;

        if(isDivisibleBy4(str)==1 && isDivisibleBy100(str)==1 && isDivisibleBy400(str)==1)
        {
            lp=1;
        }
        else if(isDivisibleBy4(str)==1 && isDivisibleBy100(str)==1 && isDivisibleBy400(str)==0)
        {
            lp=0;
        }
        else if (isDivisibleBy4(str)==1)
        {
            lp=1;
        }

        if(isDivisibleBy15(str)==1)
        {
            h=1;
        }

        if(lp==1 && isDivisibleBy55(str)==1)
        {
            b=1;
        }
        if(lp==1)
        {
            printf("This is leap year.\n");
            c++;
        }
        if(h==1)
        {
            printf("This is huluculu festival year.\n");
            c++;
        }
        if(b==1)
        {
            printf("This is bulukulu festival year.\n");
            c++;
        }
        if(c==0)
        {
            printf("This is an ordinary year.\n");
        }
        i++;
    }
    return 0;
}
