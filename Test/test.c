#include <stdio.h>

// int main(int argc, char const *argv[])
// {
//     int a = 33, b = 47, c;
//     c = a & b;
//     printf("\na & b = %d", c);
//     c = c >> 4;
//     printf("\nc >> 4 = %d", c);
//     printf("\n");
//     return 0;
// }

// void main() {
//     int a[] = {3,1,5,4}, i, j, s = 0;
//     for (i = 0; i <=4; i++) s+=a[i];
//     for(i = 1; i<= s; i++) {
//         for(j = 0; j<4; j++)
//             if (i==a[j])
//             {
//                 printf("%d", i);
//             }            
//     }
// }

// int main()
// {
//     int input, flag = 0;
//     printf("Enter a number: ");
//     scanf("%d", &input);

//     for (int i = 2; i <= input/2; i++)
//     {
//         if (input%i == 0)
//         {
//             flag = 1;
//         }
//     }
//     if (flag == 1)
//     {
//         printf("Not Prime");
//     }
//     else
//     {
//         printf("Prime");
//     }
//     return 0;
// }

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

int main(int argc, char const *argv[]) {
    int count = 0;
    for (int i = 0; i < 100000; i++) {
        int n = i, sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        if (sum == 7) {
            count++;
            printf("%d\n", i);
        }        
    }
    printf("%d", count);
    return 0;
}
