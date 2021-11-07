#include <stdio.h>

int sum(int, int);

int main(int argc, char const *argv[]) {
    int num1, num2;
    printf("Enter 2 numbers(separated by space): ");
    scanf("%d%d", &num1, &num2);
    printf("Sum of %d and %d is %d.", num1, num2, sum(num1, num2));
    return 0;
}

int sum(int a, int b) {
    unsigned int temp;
    while (b != 0) {
        temp = a & b;
        a = a ^ b;
        b = temp << 1;
    }
    return a;
}