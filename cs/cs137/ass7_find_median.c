//
// Created by speit on 18-11-22.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct ArrayProperty {
    char* array_string, start_position, end_position;
    size_t array_length, string_length;
    int ascending;
    int iteration_manner;
};

void get_array_string_from_input(ArrayProperty* array_property) {
    getline(& (* array_property).array_string, & (* array_property).array_length, stdin);
    (* array_property).string_length = 2 * (* array_property).array_length;
    if ((* array_property).array_length == 1) {
        (* array_property).start_position = (* array_property).array_string;
        (* array_property).end_position = (* array_property).array_string;
        (* array_property).ascending = 1;
        (* array_property).iteration_manner = 2;
    }
    else {
        (* array_property).ascending = (int) (* (* array_property).array_string) <= (* ((* array_property).array_string + 2));
        (* array_property).iteration_manner = (* array_property).ascending == 1 ? 2 : -2;
        (* array_property).start_position = (* array_property).ascending == 1 ? (* array_property).array_string :
                (* array_property).array_string + (* array_property).string_length - 2;
        (* array_property).end_position = (* array_property).ascending == 1 ? (* array_property).array_string + (* array_property).string_length - 1 :
                                          (* array_property).array_string - 1;
    }
    return;
}

float get_median(ArrayProperty* first_array_property_ptr, ArrayProperty* second_array_property_ptr) {
    int sorted_count = 0;
    float median = 0;
    ArrayProperty pivot_ap = (* first_array_property_ptr).array_length >= (* second_array_property_ptr).array_length ? (* first_array_property_ptr)
            : (* second_array_property_ptr);
    ArrayProperty sup_ap = (* first_array_property_ptr).array_length < (* second_array_property_ptr).array_length ? (* first_array_property_ptr)
                                                                                                                   : (* second_array_property_ptr);
    int median_position = (first_array_property.array_length + second_array_property.array_length) / 2;
    int is_odd = (first_array_property.array_length + second_array_property.array_length) % 2 == 1;

    char* pivot_cursor = pivot_ap.start_position;
    char* sup_cursor = sup_ap.start_position;
    while (sorted_count < median_position) {
        char pivot = * pivot_cursor;
        char sup = * sup_cursor;
        if ( pivot < sup ) pivot_cursor += pivot_ap.iteration_manner;
        else if ( pivot > sup) sup_cursor += sup_ap.iteration_manner;
        else {
            pivot_cursor += pivot_ap.iteration_manner;
            sup_cursor += sup_ap.iteration_manner;
            sorted_count ++;
        }
        sorted_count ++;
    }
}

int main() {
    int num_of_test_case = 0;
    scanf("%d", & num_of_test_case);
    getchar();
    for (int current_case = 0; current_case < num_of_test_case; current_case ++) {
        size_t first_array_length, first_string_length;
        char* first_array_string = NULL;
        int first_array_ascending;

        size_t second_array_length, second_string_length;
        char* second_array_string = NULL;
        int second_array_ascending;

        scanf("%d %d\n", & first_array_length, & second_array_length);
        first_string_length = 2 * first_array_length;
        second_string_length = 2 * second_array_length;

        get_array_string_from_input(first_array_string, & first_string_length, & first_array_ascending);
        get_array_string_from_input(second_array_string, & second_string_length, & second_array_ascending);

    }
}

