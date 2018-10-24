#include <stdio.h>
#include <assert.h>

int main() {
    int num_of_test_cases = 0;
    char current_ch;
    scanf("%d\n", &num_of_test_cases);
    for(int i = 0; i < num_of_test_cases; i++) {
        int first_array[105], second_array[105], result_array[105];
        int first_number_digits = 0, second_number_digits = 0;
        int current_digit, result_digit, cache_number = 0;
        int num_of_loops = 0, num_of_result_length = 0;
        int first_number_flag = 1;  // judge 1st or 2nd number
        while(scanf("%c", &current_ch)) {
            if(current_ch == '\n') break;
            else if(current_ch == ' ') first_number_flag = 0;
            else {
                current_digit = (int) current_ch - 48;
                assert(0 <= current_digit && current_digit <= 9);
                if(first_number_flag) {
                    first_array[first_number_digits] = current_digit;
                    first_number_digits += 1;
                }
                else {
                    second_array[second_number_digits] = current_digit;
                    second_number_digits += 1;
                }
            }
        }
        num_of_loops = first_number_digits >= second_number_digits ? first_number_digits : second_number_digits;
        for(int j = 0; j < num_of_loops; j ++) {
            int current_first_digit = (j < first_number_digits) ? first_array[first_number_digits - 1 - j] : 0;
            int current_second_digit = (j < second_number_digits) ? second_array[second_number_digits - 1 - j] : 0;
            result_digit = (current_first_digit + current_second_digit + cache_number) % 10;
            cache_number = (current_first_digit + current_second_digit + cache_number) / 10;
            assert(0 <= result_digit && result_digit <= 9);
            result_array[j] = result_digit;
        }
        num_of_result_length = num_of_loops;
        if(cache_number) {
            result_array[num_of_result_length] = cache_number;
            num_of_result_length += 1;
        }
        for(int k = 0; k < num_of_result_length; k ++) {
            printf("%d", result_array[num_of_result_length - 1 - k]);
        }
        printf("\n");
    }
    printf("END");
}
