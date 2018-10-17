#include<stdio.h>
#include<math.h>

// int main(int argc, char const *argv[])
// {
//     int num_of_test_case;
//     long long int target_number = 0;
//     char current_ch;
//     scanf("%d", &num_of_test_case);
//     getchar();
//     if(!num_of_test_case) return 0;
//     else {
//         for(int count = 0; count < num_of_test_case; count ++) {
//             long long int current_number = 0;
//             scanf("%lld", &target_number);
//             getchar();           
//             if(- pow(2.0, 31.0) > target_number || pow(2.0, 31.0) - 1 < target_number) printf("0\n");
//             else {
//                 while(target_number) {
//                     current_number = (current_number * 10) + (target_number % 10);          
//                     target_number = target_number / 10;
//                 }
//                 printf("%lld\n", current_number);
//             }
//         }
//     }
//     return 0;
// }

int main(int argc, char const *argv[])
{
    int num_of_test_case;
    int sign = 1, current_digit;
    long long int target_number = 0;
    int res_number;
    char current_ch;
    double num_of_digits = 0;
    scanf("%d", &num_of_test_case);
    getchar();
    if(!num_of_test_case) return 0;
    else {
        for(int count = 0; count < num_of_test_case; count ++) {
            while(scanf("%c", &current_ch) != EOF){
                if(current_ch != '\n') {
                    if(current_ch == '-')  sign = - 1;
                    else{
                        current_digit = (int) current_ch - 48;
                        target_number += pow(10.0, num_of_digits) * current_digit * sign;
                        num_of_digits += 1;
                    }
                }
                else{

                    if(- pow(2.0, 31.0) > target_number || pow(2.0, 31.0) - 1 < target_number) printf("0\n");
                    else {
                        res_number = target_number;
                        printf("%d\n", res_number);
                        num_of_digits = 0;
                        sign = 1;
                        target_number = 0;  
                    }      
                }
            }
        }                        
    }
    return 0;
}





