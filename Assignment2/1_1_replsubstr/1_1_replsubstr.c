#include <stdio.h>
#include <string.h>

char* repl_sub_str(char*, char*, int, int);

int main() {
    char inputstr[80], replstr[80];
    int startpos, endpos;

    printf("Enter a string: ");fgets(inputstr, 80, stdin);
    printf("Replacement string: ");fgets(replstr, 80, stdin);
    printf("Start position [space] End position: ");scanf("%d%d", &startpos, &endpos);
    // if the user gives an end position more than the replacement string can cover,
    // then give error and terminate program with RC 1
    if ((endpos-startpos) > strlen(replstr) - 1) {
        printf("End position is longer than replacement string\n");
        return 1;
    }

    printf("\nResult string: %s", repl_sub_str(inputstr, replstr, startpos, endpos));

    printf("\n");
    return 0;
}

/*
Replace the substring in the original string with the replacement string.
*/
char* repl_sub_str(char *str, char *repl, int start, int end) {
    char newstr[80];
    end--;
    // copy the text from original string
    for (int i = 0; i < start; i++) {
        newstr[i] = str[i];
    }
    // copy the text from replacement string
    for (int i = 0; i < end; i++) {
        newstr[start+i-1] = repl[i];
    }
    // copy the remaining text from original string
    for (int i = end; i < strlen(str); i++) {
        newstr[i] = str[i];
    }
    return newstr;
}