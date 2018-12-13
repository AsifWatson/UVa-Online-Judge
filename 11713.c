#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,l1,l2,c=0;
    char str[200];
    char str1[200];

    scanf("%d",&n);

    for(i=1;i<=n;i++){
        c=0;
        scanf("%s",str);
        scanf("%s",str1);

        l1=strlen(str);
        l2=strlen(str1);

        if(l1!=l2){
            printf("No\n");
            continue;
        }

        for(j=0;j<l1;j++){
            if(str[j]=='a' || str[j]=='e' || str[j]=='i' || str[j]=='o' || str[j]=='u'){
                if(str1[j]=='a' || str1[j]=='e' || str1[j]=='i' || str1[j]=='o' || str1[j]=='u'){
                    c++;
                }
            }
            else{
                if(str[j]==str1[j]){
                    c++;
                }
            }
        }

        if(c==l1){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}
