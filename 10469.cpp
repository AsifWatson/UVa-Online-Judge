#include<bits/stdc++.h>
using namespace std;

int main()
{
    unsigned int a,b,x,sum;
    int A,AM,B,BM;
    while(scanf(" %d %d",&a,&b)!=EOF)
    {
        x=0;
        sum=0;

        while(1)
        {

            A = a / 2;
            AM = a % 2;
            a=A;

            B = b / 2;
            BM = b % 2;
            b = B;

            if(x==32)
            {
                break;
            }
            if(AM!=BM)
            {
                sum=sum+pow(2,x);
            }
            x++;
        }
        printf("%d\n",sum);
    }
}
