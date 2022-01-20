#include <stdio.h>
#include <math.h>

int check_cyclic_num(int);

int main(int argc, char const *argv[]) {
    printf("Cyclic numbers between 1 to 99:\n");
    for (int i = 1; i < 100; i++)
        if (check_cyclic_num(i) == 0) printf("%d\t", i);
    
    printf("\n");
    return 0;
}

int check_cyclic_num(int input) {
    int square = input * input, num = input, flag = 0;

    /*
    If the last digit of the number is not the same as the digits of the square, then the number
    is not a cyclic number.
    */
    for (int i = 1; num > 0; i++) {
        if (square % 10 != num % 10) {
            return 1;
        }
        num /= 10;
        square /= 10;
    }
    return 0;
}