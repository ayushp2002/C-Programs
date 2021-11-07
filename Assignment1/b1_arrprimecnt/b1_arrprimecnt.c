#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, primecount = 0, primeflag;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements of the array: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < n; i++) {
        primeflag = 0;
        for (int j = 2; j <= arr[i]/2; j++) {
            if (arr[i] % j == 0) {
                primeflag = 1;
                break;
            }
        }
        if (primeflag == 0) {
            primecount++;
        }
    }
    
    printf("There are %d prime numbers in the array.", primecount);
    return 0;
}
