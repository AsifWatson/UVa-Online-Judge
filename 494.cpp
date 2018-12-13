#include<bits/stdc++.h>
using namespace std;
int main()
{

    char str[100000];
    int i,l,c;
    while(gets(str))
    {
        c=0;
        l=strlen(str);
        for(i=0;i<l;i++)
        {
            if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z'))
            {
                if((str[i+1]>=0 &&str[i+1]<=64) || (str[i+1]>=91 &&str[i+1]<=96) || str[i+1]>=123 &&str[i+1]<=127)
                {
                    c++;
                }
            }
        }
        printf("%d\n",c);
    }
    return 0;
}
