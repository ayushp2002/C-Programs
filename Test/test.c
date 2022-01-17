#include <stdio.h>

int main()
{
    int input, flag = 0;
    printf("Enter a number: ");
    scanf("%d", &input);

    for (int i = 2; i <= input/2; i++)
    {
        if (input%i == 0)
        {
            flag = 1;
        }
    }
    if (flag == 1)
    {
        printf("Not Prime");
    }
    else
    {
        printf("Prime");
    }
    return 0;
}

// int main() {
//     int last = 0, current = 1, next, n;

//     printf("Enter number of times: ");
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d, ", current);
//         next = last + current;
//         last = current;
//         current = next;
//     }
//     return 0;
// }