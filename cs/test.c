#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Inverse(char str[], char ptr[]);
int main(){
    char ptr[10]={"\0"};
    char ch;
    int i,t=0,n;
    int sign;
    scanf("%d",&n);
    ch=getchar();
    long long int ans[n];
    while(t<n){
        char str[10]={"\0"};
        sign=1;
        i=0;
        scanf("-%10s",&str);
        if (strlen(str)==0){
            printf("%s", str);
            scanf("%10s",&str);
        }

        else sign=-1;
        while (getchar()!='\n')
        {
            i=i+1;
        }
        if (i>0)
            ans[t]=0;
        else {
            Inverse(str,ptr);
            sscanf(ptr,"%lld",&ans[t]);
            if (ans[t]<=2147483647)
                ans[t]=ans[t]*sign;
            else if ((sign==(-1))&&(ans[t]=2147483648))
                ans[t]=ans[t];
            else ans[t]=0;
        }
        t=t+1;
    }
    for(t=0;t<n;t++)
        printf("%lld\n",ans[t]);
    return 0;
}

void Inverse(char str[], char ptr[]){
    int m=strlen(str);
    int l;
    for(l=0;l<=m;l++){
        ptr[l]=str[strlen(str)-l-1];
    }
    ptr[l-1]='\0';
}