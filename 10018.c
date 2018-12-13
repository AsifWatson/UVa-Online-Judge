#include<stdio.h>
long long int reverse(long long int num)
{
    long long int temp,sum=0,r;
    for(temp=num;num!=0;num=num/10)
    {
        r=num%10;
        sum=sum*10+r;
    }
    return sum;
}
int main()
{
    long long int a,i,j,n,ch,c;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        c=0;
        scanf("%d",&a);
        for(j=1; ;j++)
        {
            ch=reverse(a);
            if(ch==a)
                break;
            a=a+ch;
            c++;
        }
       printf("%lld %lld\n",c,ch);
    }
    return 0;
}
