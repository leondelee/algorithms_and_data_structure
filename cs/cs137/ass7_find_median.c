#include <stdio.h>
#include <stdlib.h>

float get_median(float* first_array, float* second_array, long long int first_length, long long int second_length) {
    int median_position = (first_length + second_length + 1) / 2;
    int is_even = (first_length + second_length) % 2 == 0;
    float median = 0;
    float* pivot_cursor = first_array;
    float* sup_cursor = second_array;
    float* first_end_position = first_array + first_length;
    float* second_end_position = second_array + second_length;
    float* current_cursor = NULL;
    int sorted_count = 0;
    while (1) {
        float pivot = *pivot_cursor;
        float sup = *sup_cursor;

        if (sorted_count == median_position) {
            median += * current_cursor;
            if (!is_even) return median;
        }
        else if (sorted_count == median_position + 1) {
            median += * current_cursor;
            median /= 2;
            return median;
        }
        if (pivot_cursor == first_end_position) {
            current_cursor = sup_cursor;
            sup_cursor += 1;
        }
        else {
            if (pivot > sup && sup_cursor != second_end_position) {
                current_cursor = sup_cursor;
                sup_cursor += 1;
            } else {
                current_cursor = pivot_cursor;
                pivot_cursor += 1;
            }
        }
        sorted_count++;
    }
}

int main() {
    int num_of_test_case = 0;
    scanf("%d", & num_of_test_case);
    getchar();
    for (int current_case = 0; current_case < num_of_test_case; current_case ++) {
        long long int first_length;
        long long int second_length;
        scanf("%lld %lld\n", & first_length, & second_length);
        float* first_array = (float* ) malloc(first_length * sizeof(float));
        float* second_array = (float* ) malloc(second_length * sizeof(float));
        for(float* i = first_array; i < (first_array + first_length); i ++) {
            scanf("%f", i);
        }
        for(float* i = second_array; i < (second_array + second_length); i ++) {
            scanf("%f", i);
        }
        float median = get_median(first_array, second_array, first_length, second_length);
        printf("%.1f\n", median);
    }
}

