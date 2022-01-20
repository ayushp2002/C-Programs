#include <stdio.h>
#include <limits.h>

#define ARR_SIZE 11

void selection_sort(int arr[], int size);

int main() {
    int set[] = {55, 23, 45, 12, 67, 20, 34, 10, 54, 50, 19}, pos;

    printf("Original array:\n");
    for (int i = 0; i < ARR_SIZE; i++) printf("%d\t", set[i]);

    selection_sort(set, ARR_SIZE);
    printf("\n\n");
    printf("Array after sorting\n");
    for (int i = 0; i < ARR_SIZE; i++) printf("%d\t", set[i]);    
    
    printf("\n");
    return 0;
}

/* "The selection sort algorithm sorts an array by repeatedly finding the minimum element
(considering ascending order) from unsorted part and putting it at the beginning."

The algorithm maintains two subarrays in a given array.

1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.

In every iteration of selection sort, the minimum element (considering ascending order) from the
unsorted subarray is picked and moved to the sorted subarray.

The idea of the algorithm is to go through the array and find the minimum */
void selection_sort(int arr[], int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
       for (int j = i + 1; j < size; j++) {
           if (arr[i] > arr[j]) {
               temp = arr[i];
               arr[i] = arr[j];
               arr[j] = temp;
            }
        }
   }
}