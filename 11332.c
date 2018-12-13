#include<stdio.h>
int recurse(int n)
{
	int a,b;
	a=n%10;
	b=n/10;
	if(b==0)
	    return a;
	else
	    return a+recurse(n/10);
}
int main()
{
	int i,x,y,N;
	while(scanf("%d",&N))
    {
        if(N==0)
            return 0;
        for(i=1; ;i++)
        {
            x=recurse(N);
            y=x/10;
            if(y==0)
                break;
            N=x;
        }
        printf("%d\n",x);
    }
	return 0;
}
