#include <stdio.h>

int isPrime(int num) {
    int flag = 1;
    for (int i = 2; i < num/2; i++) {
        if (num % i == 0) {
            // Not a prime number
            flag = 0;
            break;
        }
    }
    return flag;
}

int main(int argc, char const *argv[]) {
    
    int primecounter = 0, limit = 3000;
    double probability;

    for (int i = 1; i <= limit; i++) {
        if (isPrime(i) == 1) {
            primecounter++;
        }
    }

    probability = (primecounter / limit) * 100;
    printf("Probability = %d/%d = %f%%", primecounter, limit, probability);
    
    printf("\n");
    return 0;
}
