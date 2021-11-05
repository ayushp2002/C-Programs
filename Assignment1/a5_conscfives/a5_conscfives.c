#include <stdio.h>

int validateconsecfives(int);

int main(int argc, char const *argv[]) {
    int input;

    printf("Enter a 6 digit number: ");scanf("%d", &input);

    if (validateconsecfives(input) == 0) {
        printf("Yes");
    } else if (validateconsecfives(input) == 1) {
        printf("No");
    } else if (validateconsecfives(input) == 2) {
        printf("Enter a six digit number");
    }
    
    return 0;
}

int validateconsecfives(int input) {
    int temp = input;
    int fives = 0;
    
    if (input < 100000 || input > 999999) { return 2; }
    
    while (temp > 0) {
        if (temp % 10 == 5) {
            fives++;
        } else {
            fives = 0;
        }
        temp /= 10;
        if (fives >= 3) { return 0; }
    }
    
    return 1;
}