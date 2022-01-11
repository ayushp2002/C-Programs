#include <stdio.h>

int check_strong_num(int);

int main(int argc, char const *argv[]) {

    for (int i = 100; i < 1000; i++)
        if (check_strong_num(i) == 0) printf("%d\t", i);
    
    printf("\n");
    return 0;
}

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