#include<stdio.h>

float convertor(char type, float temperature);

int main(int argc, char const *argv[])
{
    int num_of_cases, count = 0;
    char type;
    float temperature;
    float res_temperature;
    scanf("%d", &num_of_cases);
    if(num_of_cases) {
        while(count < num_of_cases) {
            getchar();
            scanf("%c", &type);
            getchar();
            scanf("%f", &temperature);
            res_temperature = convertor(type, temperature);
            printf("%.2f", res_temperature);
            count ++;
        }
    } 
    return 0;
}

float convertor(char type, float temperature) {
    if(type == 'C') return 32 + temperature * 1.8;
    else return (temperature - 32) / 1.8;
}