#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define STRING_SIZE 100
#define WORD_SIZE 20

/*  
    Tokenizing the string into words and then comparing is not the most efficient
    solution when we already know the substring. It is better to use simple comparisons.
    However, I have included both the methods for the below solution.
*/

int count_article(char*);
int count_article_by_splitting(char*);  // tokenizer method
int str_tolower(char*);

int main(int argc, char* argv[])
{
    char *str = malloc(STRING_SIZE * sizeof(char));
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    str_tolower(str);   // strings are always passed by reference so no need to capture returning value

    printf("\nCount = %d", count_article(str));
    printf("\nCount (tokenizing method) = %d", count_article_by_splitting(str));

    printf("\n");

    return 0;
}

int count_article(char *str) {
    int count = 0, i = 0;
    int len = strlen(str) - 1;    // strlen counts the number of characters including escape sequence.

    /* this kind of comparison with nested ifs is more optimized than using and(&),
       because if the first condition fails, it will not continue to the second one.
       this is better than computing complete logical expressions */

    // perform checks for first letter
    if (str[0] == 'a') {
        if (str[1] == 'n') {
            if (str[2] == ' ') {count++;i+=2;}    // "an"
        } else if (str[1] == ' ') {count++;i+=1;} // "a"
    } else if (str[0] == 't') {
        if (str[1] == 'h')
            if (str[2] == 'e')
                if (str[3] == ' ') {count++;i+=3;}   // "the"
    }
    
    // perform checks for intermediate letters
    /*
    If the current character is a space,
    then check the next character. If the next character is 'a', then check the next
    two characters. If the next two characters are 'an', then increment the count.
    If the next two characters are 'a', then increment the count. If the next
    character is 't', then check the next two characters. If the next two characters
    are 'the', then increment the count.
    */
    for (i = 0; i <= len; i++) {
        if (str[i] == ' ') {
            if (str[i+1] == 'a') {
                if (str[i+2] == 'n') {
                    if (str[i+3] == ' ') {count++;i+=2;}    // "an"
                } else if (str[i+2] == ' ') {count++;i+=1;} // "a"
            } else if (str[i+1] == 't') {
                if (str[i+2] == 'h')
                    if (str[i+3] == 'e')
                        if (str[i+4] == ' ') {count++;i+=3;}   // "the"
            }
        } 
    }

    // perform checks for last letter
    if (str[len - 0] == 'n') {
        if (str[len - 1] == 'a')
            if (str[len - 2] == ' ')    // "an"
                count++;
    } else if (str[len - 0] == 'a') {
        if (str[len - 1] == ' ')    // "a"
            count++;
    } else if (str[len - 0] == 'e') {
        if (str[len - 1] == 'h')
            if (str[len - 2] == 't')
                if (str[len - 3] == ' ')    // "the"
                    count++;
    }
    return count;
}

int count_article_by_splitting(char *str) {
    int count = 0, len = strlen(str) - 1, word_count = 0;
    char *token[WORD_SIZE], currentchar[2];
    currentchar[1] = '\0';  // to append characters to token one by one

    // allocate memory
    for (int i = 0; i < WORD_SIZE; i++) {
        token[i] = malloc (WORD_SIZE * sizeof(char));
    }
    
    // can also use strtok() string method for the same purpose
    // tokenize and store the words separated by space, comma, or period
    /*
    1. Initialize the token array with the number of words in the string.
    2. Initialize the currentchar array with the first character of the string.
    3. Loop through the string, if the current character is not a space, comma, or period, add it to
    the currentchar array.
    4. If the current character is a space, comma, or period, add the currentchar array to the token
    array and increment the word_count.
    5. Return the token array.
    */
    for (int i = 0; i <= len; i++) {
        if (str[i] != ' ' || str[i] != ',' || str[i] != '.') {
        // if (str[i] < 'a' || str[i] > 'Z') {  // use this to assume any non alpha character as a separator
            currentchar[0] = str[i];
            strcat(token[word_count], currentchar);
        } else {
            word_count++;
        }
    }
    for (int i = 0; i <= word_count; i++) {
        if (strcmp(token[i], "a") == 0 || strcmp(token[i], "an") == 0 || strcmp(token[i], "the") == 0) {
            count++;
        }
        
    }
    
    return count;
}

/*
Convert all characters in a string to lowercase.
*/
int str_tolower(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
    return 0;
}