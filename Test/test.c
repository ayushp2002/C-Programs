#include <stdio.h>
#include <limits.h>

int main() {
    int x, y = 1, n = 4, asd = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        x = y;
        if (y == 1) y = 0;
        else y = 1;
        for (int j = 0; j <= i; j++)
        {
            printf("%d\t", x);
            if (x == 1) x = 0;
            else x = 1;
        }
        printf("\n");
    }
    
    return 0;
}