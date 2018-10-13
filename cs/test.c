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
