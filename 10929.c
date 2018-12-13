#include<stdio.h>
#include<string.h>

int main()
{
    char str[10000];
    int i,sum=0,ln;

    while(gets(str)){
        sum=0;
        ln=strlen(str);

        for(i=0;i<ln;i++){
            sum=sum+str[i]-48;
        }

        if(sum==0){
            break;
        }

        sum=0;

        for(i=0;i<ln;i++){
            if(i%2==0){
                sum=sum+(str[i]-48);
            }
            else{
                sum=sum-(str[i]-48);
            }
        }

        if(sum==0 || sum%11==0){
            printf("%s is a multiple of 11.\n",str);
        }

        else{
            printf("%s is not a multiple of 11.\n",str);
        }
    }

    return 0;
}
