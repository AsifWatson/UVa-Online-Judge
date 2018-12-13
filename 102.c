#include<stdio.h>
int main()
{
    int b1,b2,b3,g1,g2,g3,c1,c2,c3,s[6],min,i;
    while(scanf("%d %d %d %d %d %d %d %d %d",&b1,&g1,&c1,&b2,&g2,&c2,&b3,&g3,&c3)==9)
    {
        s[0]=b2+b3+c1+c3+g1+g2;
        s[1]=b2+b3+g1+g3+c1+c2;
        s[2]=c2+c3+b1+b3+g1+g2;
        s[3]=c2+c3+g1+g3+b1+b2;
        s[4]=g2+g3+b1+b3+c1+c2;
        s[5]=g2+g3+c1+c3+b1+b2;
        min=s[0];
        for(i=0; i<6; i++){
            if(min>s[i]){min=s[i]; }
        }

        if(min==s[0])
        {
            printf("BCG %d\n",s[0]);
        }
        else if(min==s[1])
        {
            printf("BGC %d\n",s[1]);
        }
        else if(min==s[2])
        {
            printf("CBG %d\n",s[2]);
        }
        else if(min==s[3])
        {
            printf("CGB %d\n",s[3]);
        }
        else if(min==s[4])
        {
            printf("GBC %d\n",s[4]);
        }
        else if(min==s[5])
        {
            printf("GCB %d\n",s[5]);
        }

    }
    return 0;
}
