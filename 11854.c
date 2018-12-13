#include<stdio.h>
#include<math.h>

int main()
{
    long int a,A,b,B,c,C;

    while(scanf(" %ld %ld %ld",&a,&b,&c))
    {
        if(a==0 && b==0 && c==0)
            break;

        A=pow(a,2);
        B=pow(b,2);
        C=pow(c,2);
        if(A+B==C || A+C==B || B+C==A )
            printf("right\n");
        else
            printf("wrong\n");
    }

    return 0;
}
