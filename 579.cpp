#include<bits/stdc++.h>
using namespace std;

int main()
{
    ///freopen("in.txt", "rt", stdin);
    ///freopen("out.txt", "wt", stdout);

    int H,M,DH,DM,D;
    double dis,degree;
    char c;

    while(scanf("%d %c %d",&H,&c,&M))
    {
        if(H==0 && M==0)
        {
            break;
        }

        DH = H * 30;
        DM = M * 6;
        D = DH - DM;
        dis = (double)M/2;
        degree = (double)D + dis;

        if(degree>180)
        {
            degree = 360 - degree;
        }
        if(degree<0)
        {
            degree = degree * -1;
            if(degree>180)
            {
                degree = 360 - degree;
            }
        }

        printf("%.3lf\n",degree);

    }
    return 0;
}
