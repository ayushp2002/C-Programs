#include <stdio.h>

#define ARR_SIZE 10

int isPrime(int);

int main(int argc, char const *argv[]) {
    int input[ARR_SIZE], prime[ARR_SIZE], nprime[ARR_SIZE], primectr = 0, nprimectr = 0;

    printf("Enter the array elements (separated by space)\n>> ");
    for (int i = 0; i < ARR_SIZE; i++) scanf("%d", &input[i]);
    /* this process should be done as soon as taking input in the same loop,
       to avoid creating another array for storing the numbers and also
       avoid the use of another loop */
    for (int i = 0; i < ARR_SIZE; i++) {
        if (isPrime(input[i]) == 0) {
            prime[primectr] = input[i];
            primectr++;
        } else {
            nprime[nprimectr] = input[i];
            nprimectr++;
        }
    }
    
    printf("\nPrime elements:\n");
    for (int i = 0; i < primectr; i++)  printf("%d\t", prime[i]);
    printf("\nNon Prime elements:\n");
    for (int i = 0; i < nprimectr; i++) printf("%d\t", nprime[i]);
    
    printf("\n");
    return 0;
}

/*
Given an integer n, return 1 if n is prime, 0 otherwise.
*/
int isPrime(int n) {
    int flag = 0;
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }
    return flag;
}