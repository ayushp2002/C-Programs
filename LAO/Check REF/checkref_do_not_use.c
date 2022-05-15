#include <stdio.h>

int main(int argc, char const *argv[]) {
    // int sizex, sizey, isref = 0;
    // printf("Enter dimensions [X Y]: ");
    // scanf("%d%d", &sizex, &sizey);

    // if (sizex <= 0 || sizey <= 0) {
    //     return 1;
    // }

    // int matrix[sizex][sizey], leads[sizex];

    // for (int i = 0; i < sizex; i++) {
    //     for (int j = 0; j < sizey; j++) {
    //         scanf("%d", &matrix[i][j]);
    //     }  
    // }
    
    // // Find the leading entries' index for every row
    // for (int i = 0; i < sizex; i++) {
    //     for (int j = 0; j < sizey; j++) {
    //         if (matrix[i][j] != 0) { // search for the first non zero element
    //             leads[i] = j;
    //             break;
    //         }
    //     }
    // }        

    // // Each leading entry of a row is in a column to the right of the leading entry of the row above it.
    // for (int i = 0; i < sizex - 1; i++) {
    //     if (leads[i] > leads[i+1]) {
    //         printf("Condition: \"Each leading entry of a row is in a column to the right of the leading entry of the row above it\" failed.\n");
    //         isref = 1;
    //         break;
    //     }
    // }
    // if (isref == 0) {
    //     printf("Condition: \"Each leading entry of a row is in a column to the right of the leading entry of the row above it\" passed.\n");
    // }

    // // All entries in a column below a leading entry are zeros
    // for (int i = 0; i < sizex; i++) {
    //     for (int j = i; j < sizey; j++) {
    //         if (matrix[j][leads[i]] != 0) {
    //             printf("Condition: \"All entries in a column below a leading entry are zeros\" failed.\n");
    //             isref = 1;
    //             break;
    //         }
    //     }
    //     if (isref == 1) {
    //         break;
    //     }
    // }
    // if (isref == 0) {
    //     printf("Condition: \"All entries in a column below a leading entry are zeros\" passed.\n");
    // }    



    // // for (int i = 0; i < sizex; i++)
    // // {
    // //     printf("%d ", leads[i]);
    // // }
    
    return 0;
}

// Convert to REF and then compare both