#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
    int matrix[3][3] = {{1, 2, 3}, {2, 4, 6}, {1, 1, 1}};
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         scanf("%d", &matrix[i][j]);
    //         matrix[i][j] = abs(matrix[i][j]);
    //     }
    // }

    for (int i = 0; i < 3; i++)
    {
        int same = 0;
        for (int j = 0; j < 3; j++)
        {
            if (i < 2)
            { // comparison for (0,1) and (1, 2)
                if ((matrix[i][j] % matrix[i + 1][j] != 0) || (matrix[i+1][j] % matrix[i][j] != 0))
                {
                    same = 1;
                    break;
                }
            }
            else
            { // comparison for (2, 0)
                if (matrix[0][j] % matrix[i][j] != 0)
                {
                    same = 1;
                    break;
                }
            }
        }
        if (same == 0)
        {
            if (i < 2)
            { // comparison for (0,1) and (1, 2)
                if (matrix[i + 1][0] > matrix[i][0])
                {
                    printf("\n%d#%d", i, i + 1);
                }
            }
            else
            {
                if (matrix[0][0] > matrix[i][0])
                {
                    printf("\n%d#%d", 0, i);
                }
            }
        }
        else
        {
            printf("\n0#0");
        }

        return 0;
    }
}
