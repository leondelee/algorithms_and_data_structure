#include <stdio.h>
#include <assert.h>

long long int num_of_ways(int stairs);

int main() {
    int num_of_test_cases = 0;
    int total_stairs = 0;
    scanf("%d", &num_of_test_cases);
    getchar();
    for(int i = 0; i < num_of_test_cases; i++) {
        scanf("%d", &total_stairs);
        long long int ways = num_of_ways(total_stairs);
        printf("%lld\n", ways);
    }
    printf("END");
}

long long int num_of_ways(int stairs) {
    assert(stairs >= 0);
    if(stairs == 0) return 1;
    if(stairs == 1) return 2;
    else {
        return 2*(num_of_ways(stairs - 1) + num_of_ways(stairs - 2));
    }

}