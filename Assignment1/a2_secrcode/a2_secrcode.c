#include <stdio.h>

int encrypt(int, int, int);

int main(int argc, char const *argv[])
{
    int scode, nkey, mkey;

    printf("Secret code: ");scanf("%d", &scode);
    printf("Key N: ");scanf("%d", &nkey);
    printf("Key M: ");scanf("%d", &mkey);

    printf("Encrypted code: %d", encrypt(scode, nkey, mkey));

    return 0;
}

int encrypt(int s, int n, int m) {
    return (((s*n%10)^m)%17);
}