#include <stdio.h>

int check_strong_num(int);

int main(int argc, char const *argv[]) {
    printf("Strong numbers between 100 and 999:\n");
    for (int i = 100; i < 1000; i++)
        if (check_strong_num(i) == 0) printf("%d\t", i);
    
    printf("\n");
    return 0;
}

/*
1. Get the last digit of the input number.
    2. Multiply all the digits from 1 to the last digit.
    3. Add the result to the fact_sum.
    4. Repeat steps 1-3 until the input number is 0.
    5. If the fact_sum is equal to the input number, return 0. Strong number
    6. Else return 1. Not a strong number
*/
int check_strong_num(int input) {
    int fact_sum = 0, num = input;
    while (num > 0) {
        int digit = num % 10;   // get the last digit
        num /= 10;  // remove last digit
        int fact = 1;
        for (int j = digit; j > 1; j--) {   // j > 1 because there is no point multiplying with 1 every time
            fact *= j;
        }
        fact_sum += fact;
    }
    if (fact_sum == input) return 0;
    else return 1;
}