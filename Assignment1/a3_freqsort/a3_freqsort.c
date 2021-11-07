#include <stdio.h>

int *initarray(int*, int);

int main() {
    int input[10], output[10], number[10], freq[10], temp, breakflag = 0, ctr = 0;
    
    initarray(number, 10);
    initarray(freq, 10);
    
    printf("Enter an array[10](separated by spaces): ");
    for (int i = 0; i < 10; i++) { scanf("%d", &input[i]); }
    
    for (int i = 0; i < 10; i++) {
        for (int x = 0; x < 10; x++) {
            if (number[x] == input[i]) {
                continue;
            } else {
                breakflag = 1;
            }
        }
        if (breakflag == 1) {
            number[ctr] = input[i];
            freq[ctr] = 0;
        } else {
            continue;
        }
        for (int j = i+1; j < 10; j++) {
            if (input[j] == number[i]) {
                freq[ctr]++;
            }
        }
        ctr++;
    }
    
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("%d-%d ; ",number[i], freq[i]);
    }
    return 0;
}


int *initarray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = 0;
    }
}