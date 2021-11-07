#include <stdio.h>

int *initarray(int*, int);

int main(int argc, char const *argv[]) {
    int n, ctr = 0, existflag;
    printf("Enter the size of the array: ");scanf("%d", &n);
    int arr[n], uniqarr[n];
    initarray(uniqarr, n);
    printf("Enter the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        existflag = 0;
        for (int j = 0; uniqarr[j] != 0; j++) {
            if (arr[i] == uniqarr[j]) {
                existflag = 1;
                break;
            }
        }
        if (existflag == 0) {
            uniqarr[ctr] = arr[i];
            ctr++;
        }
    }
    
    printf("Unique array: ");
    for (int i = 0; uniqarr[i] != 0; i++) {
        printf("%d ", uniqarr[i]);
    }
    
    
    return 0;
}

int *initarray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = 0;
    }
}