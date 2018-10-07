#include<stdio.h>
#include<assert.h>
#include<math.h>

main(int argc, char const *argv[])
{
    char current_ch;
    int current_digit = 0, num_of_test_cases = 0;
    scanf("%d\n", &num_of_test_cases);
    for(int count = 0; count < num_of_test_cases; count ++) {
        int target_number = 0, sign = 1;
        long long int ref_number = 0;    // used to judge whether overflow at one specific time, which is not the number used to store and print
        double num_of_digits = 0.0;
        while(scanf("%c", ¤t_ch)) {
            if(current_ch == '\n') {
            	printf("%d\n", target_number);
            	break;
            }
            if(current_ch == '-') sign = -1;
            else {
                current_digit = ((int) current_ch) - 48;
                assert(0 <= current_digit && current_digit <= 9);              
                ref_number += current_digit * pow(10.0, num_of_digits) * sign;
                if(- pow(2.0, 31.0) > ref_number || pow(2.0, 31.0) - 1 < ref_number) {
                    while(scanf("%c", ¤t_ch)) {
                        if(current_ch == '\n') {
                            target_number = 0;
                            printf("%d\n", target_number);
                            break;
                        }
                    }
                    break;
                }
                else {
                    target_number += current_digit * pow(10.0, num_of_digits) * sign;
                    num_of_digits += 1;
                }
            }       
        }
    }
    return 0;
}