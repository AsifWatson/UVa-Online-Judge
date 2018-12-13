#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h,u,d,f,day;
    double initialHeight,climbed,afterClimbing,afterSliding,factor,U;

    while(scanf("%d",&h))
    {
        scanf("%d %d %d",&u,&d,&f);

        if(h==0)
        {
            break;
        }

        U=u;

        day=0;
        initialHeight=0;

        factor=(U*f)/100;

        while(1)
        {
            day++;
            climbed = U;
            if(climbed > 0)
            {
                afterClimbing = initialHeight + climbed;
            }
            else
            {
                afterClimbing = initialHeight;
            }
            afterSliding = afterClimbing - d;

            if(afterClimbing > h)
            {
                printf("success on day %d\n",day);
                break;
            }

            if( afterSliding < 0 )
            {
                printf("failure on day %d\n",day);
                break;
            }

            initialHeight = afterSliding;
            U = U - factor;
        }

    }
    return 0;
}
