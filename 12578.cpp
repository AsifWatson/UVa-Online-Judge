#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T,L,i;
    double Carea,Farea,Width,Radius;

    scanf("%d",&T);

    for(i=1;i<=T;i++)
    {
        scanf("%d",&L);

        Width = (double)(0.6*L);
        Radius = (double)(0.2*L);

        Carea = (double)(3.1415926545*Radius*Radius);
        Farea =(double)(L*Width)-Carea;

        printf("%.2lf %.2lf\n",Carea,Farea);
    }

    return 0;
}
