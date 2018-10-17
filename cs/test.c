<<<<<<< HEAD
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
=======
#include<stdio.h>
<<<<<<< HEAD

main(int argc, char const *argv[])
{
    int a = 5;
    a = a >> 1;
    printf("%d", a);
    return 0;
}
=======
#include<math.h>
#include<assert.h>

int main() {
    double a = - pow(2.0, 31.0);
    // assert(2147483647 < a);
    printf("%lf", a);
}
>>>>>>> 6b7e9d5881b9c9e281fe5e13ff8d7bd70afab7bc
>>>>>>> 4e70ebbcf3ece2a5c1c137e55c784dd1587eea08
