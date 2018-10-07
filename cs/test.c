#include<stdio.h>
#include<math.h>
#include<assert.h>

int main() {
    double a = - pow(2.0, 31.0);
    // assert(2147483647 < a);
    printf("%lf", a);
}