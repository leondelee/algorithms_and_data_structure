#include<stdio.h>
#include<math.h>

long long int find_num_of_factors(long long int N);

int main(int argc, char const *argv[])
{
    // int one_ch;
    long long int N = 0;
    long long int res = 0;
    while(scanf("%lld", &N) != EOF) {
        res = find_num_of_factors(N);
        printf("%lld\n", res);
        N = 0;
        res = 0;
    }
    return 0;
}

long long int find_num_of_factors(long long int N) {
    if(N == 1) return 1;
    else if(N == 2) return 2;
    else if(N == 3) return 2;
    else if(N == 4) return 3;
    else { 
        long long int count = 0;
        long double N_ = N;
        for(int fc = 2; fc < sqrt(N_); fc ++) {
            if(N % fc == 0) count ++;
        }
        return count * 2 + 2;
    }
}
