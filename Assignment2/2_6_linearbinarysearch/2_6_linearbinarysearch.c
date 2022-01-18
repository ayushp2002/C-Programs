#include <stdio.h>
#include <limits.h>

#define ARR_SIZE 11

void sort(int arr[], int size);
int linear_search(int[], int, int);
int binary_search(int[], int, int);

int main() {
    int set[] = {55, 23, 45, 12, 67, 20, 34, 10, 54, 50, 19}, pos;

    printf("Original array:\n");
    for (int i = 0; i < ARR_SIZE; i++) printf("%d\t", set[i]);
    
    pos = linear_search(set, 45, ARR_SIZE);
    if (pos != -1) printf("\n%d found on position %d using Linear search.", 45, pos); else printf("\n%d not found using Linear search", 45);
    pos = linear_search(set, 50, ARR_SIZE);
    if (pos != -1) printf("\n%d found on position %d using Linear search.", 50, pos); else printf("\n%d not found using Linear search", 50);
    pos = linear_search(set, 18, ARR_SIZE);
    if (pos != -1) printf("\n%d found on position %d using Linear search.", 18, pos); else printf("\n%d not found using Linear search", 18);

    sort(set, ARR_SIZE);
    printf("\n\n");
    printf("Array after sorting for binary search:\n");
    for (int i = 0; i < ARR_SIZE; i++) printf("%d\t", set[i]);

    pos = binary_search(set, 45, ARR_SIZE);
    if (pos != -1) printf("\n%d found on position %d using Binary search.", 45, pos); else printf("\n%d not found using Binary search", 45);
    pos = binary_search(set, 50, ARR_SIZE);
    if (pos != -1) printf("\n%d found on position %d using Binary search.", 50, pos); else printf("\n%d not found using Binary search", 50);
    pos = binary_search(set, 18, ARR_SIZE);
    if (pos != -1) printf("\n%d found on position %d using Binary search.", 18, pos); else printf("\n%d not found using Binary search", 18);
    
    
    printf("\n");
    return 0;
}

int linear_search(int arr[], int element, int size) {
    int pos = -2;
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            pos = i;
            break;
        }
    }
    return pos+1;
}

void sort(int arr[], int size) {
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

int binary_search(int arr[],int element, int size) {
  int f = 0, r = size, mid;

   while (f <= r) {
       mid = (f + r) / 2;
       if (arr[mid] == element) {
           return mid + 1;
           break;
       }
       else if (arr[mid] < element)
           f = mid + 1;
       else
           r = mid - 1;
   }
   if (f > r)
       return -1;
    return -2;
}