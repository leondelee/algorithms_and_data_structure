#include<stdio.h>

int main(int argc, char const *argv[])
{
    char character;
    while (scanf("%c", & character) != EOF) {
        printf("%c", character);
    }
    return 0;
}
