#include <stdio.h>

int main(int argc, char const *argv[]) {
    int size = 100;
    char str[size], remchar;
    printf("Enter a string: ");fgets(str, size, stdin);
    printf("Enter the character to remove: ");scanf("%c", &remchar);

    for (int i = 0; i < size; i++) {
        if (str[i] == remchar) {
            for (int j = i; j < --size; j++) {
                str[j] = str[j+1];
            }
        }
    }

    printf("%s", str);
    return 0;
}
