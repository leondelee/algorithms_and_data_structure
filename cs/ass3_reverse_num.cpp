#include<

main(int argc, char const *argv[])
{
    int num_of_test_case;
    long long int target_number;
    char current_ch;
    int current_digit;
    stack<int> my_stack;
    scanf("%d", &num_of_test_case);
    getchar();
    if(!num_of_test_case) return;
    else {
        for(int count = 0; count < num_of_test_case; count ++) {
            int sign = 1;
            while(scanf("%c", &current_ch) != '\n') {
                if(current_ch == '-')  sign = - 1;
                current_digit = (int) 
            }
        }
    }
    return 0;
}



