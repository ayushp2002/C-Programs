#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
Creating a linked list.
*/
struct item {
    int data;
    struct item *link;
} *first = NULL,    // begin
  *cursor = NULL;   // end

struct item* insert_item(int);
struct item* find_largest();
struct item* find_smallest();
int count_prime_items();
int count_items_div_seven();
void display_list();

int main(int argc, char const *argv[]) {
    // can use scanf for dynamic insertion of items
    insert_item(45);
    insert_item(2);
    insert_item(250);
    insert_item(13);
    insert_item(57);
    insert_item(49);
    insert_item(72);
    insert_item(824);
    insert_item(63);

    display_list();

    printf("\n\nLargest element: %d", find_largest()->data);
    printf("\nSmallest element: %d\n", find_smallest()->data);

    printf("\nNumber of prime elements: %d", count_prime_items());
    printf("\nNumber of items divisible by seven: %d", count_items_div_seven());

    printf("\n");
    return 0;
}

struct item* insert_item(int data) {
    struct item *node = (struct item*) malloc(sizeof(struct item));
    struct item *temp;

    node->data = data;
    node->link = NULL;

    /*
    If the list is empty,
    assign the node to the first pointer. If the list has only one node,
    assign the node to the cursor pointer. If the cursor pointer is null,
    assign the node to the cursor pointer. Otherwise, assign the node to the
    cursor link item.
    */
    if (first == NULL) {  // if the list is empty
        first = node;
        cursor = first;
    } else if (first->link == NULL) {   // if the list has only one item
        first->link = node;
        cursor = node;
    } else if (cursor->link == NULL) {  // if the cursor->link is null,
                                        // and we try to assign that address to cursor, it will fail
        cursor->link = node;
    } else {
        cursor = cursor->link;
        cursor->link = node;
    }

    return node;
}

struct item* find_largest() {
    struct item *ptr = first;
    struct item *large = (struct item*) malloc(sizeof(struct item));

    large->data = INT_MIN;  // initialize with smallest possible number

    /*
    Finding the largest value in the list.
    */
    while (ptr != NULL) {
        if (ptr->data > large->data) large = ptr;
        ptr = ptr->link;
    }

    return large;
}

struct item* find_smallest() {
    struct item *ptr = first;
    struct item *small = (struct item*) malloc(sizeof(struct item));

    small->data = INT_MAX;  // initialize with smallest possible number

   /*
   Finding the smallest element in the list.
   */
    while (ptr != NULL) {
        if (ptr->data < small->data) small = ptr;
        ptr = ptr->link;
    }

    return small;
}

int count_prime_items() {
    struct item *ptr = first;
    int count = 0;
    /*
    Count the number of prime numbers in a linked list.
    */
    while (ptr != NULL) {
        int flag = 0;
        for (int i = 2; i <= (ptr->data)/2; i++)
            if (ptr->data % i == 0) flag = 1;
        
        if (flag == 0) count++;

        ptr = ptr->link;        
    }
    return count;
}

int count_items_div_seven() {
    struct item *ptr = first;
    int count = 0;
    /*
    Counting the number of elements in the list that are divisible by 7.
    */
    while (ptr != NULL) {
        if (ptr->data % 7 == 0) count++;
        ptr = ptr->link;
    }
    return count;
}

void display_list() {
    struct item *node = first;
    /*
    Printing the data of each node in the linked list.
    */
    while (node != NULL) {
        printf(" -> %d", node->data);
        node = node->link;
    }
}