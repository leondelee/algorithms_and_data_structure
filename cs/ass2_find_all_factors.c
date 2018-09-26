#include<stdio.h>
#include<math.h>

int find_num_of_factors(long int N);
int is_prime(long int num);

int main(int argc, char const *argv[])
{
    char one_ch;
    while(scanf("%c", &one_ch) != EOF) {
        long int N = 0;
        if(one_ch != '\n') {
            N = N * 10;
            N += (int) one_ch;
        }
        printf("%d", find_num_of_factors(N));
    }
    // printf("%d", is_prime(N));
    return 0;
}

int find_num_of_factors(long int N) {
    int res_count = 1;
    double N_ = N;
    for(long int fc = 1; fc <= sqrt(N_) + 1; fc ++){
        if(is_prime(fc)) {
            int count = 1;
            while(N % fc == 0) {
            count ++;
            N = N / fc;
            }
            res_count = res_count * count;
        }
    }
    return res_count;
}

int is_prime(long int num) {
    if(num == 2 || num == 3) return 1;
    else {
        double num_ = num;
        for(int i = 2; i <= sqrt(num_) + 1; i ++) {
            if(num % i == 0) return 0;
        }
        return 1;
    }
}
