#include<bits/stdc++.h>
using namespace std;

int main()
{

    int i,carry,c,a,x,sum;
    unsigned int A,B,b,y;

    while(scanf("%d %d",&A,&B)!=EOF)
    {
        c=0;
        carry=0;
        sum=0;
        if(A==0 && B==0)
        {
            break;
        }

        while(1)
        {
            a=A%10;
            b=A/10;
            A=b;

            x=B%10;
            y=B/10;
            B=y;

            sum=a+x+carry;
            carry=0;

            if(sum>9)
            {
                c++;
                carry=1;
            }

            if(b==0 && y==0)
            {
                break;
            }
            sum=0;
        }
        if(c==0)
        {
            printf("No carry operation.\n");
        }

        if(c==1)
        {
             printf("1 carry operation.\n");
        }

        if(c>1)
        {
            printf("%d carry operations.\n",c);
        }
    }

    return 0;
}
