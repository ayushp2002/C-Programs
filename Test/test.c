// #include <stdio.h>

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

// int main(int argc, char const *argv[]) {
//     int count = 0;
//     for (int i = 0; i < 100000; i++) {
//         int n = i, sum = 0;
//         while (n > 0) {
//             sum += n % 10;
//             n /= 10;
//         }
//         if (sum == 7) {
//             count++;
//             printf("%d\n", i);
//         }        
//     }
//     printf("%d", count);
//     return 0;
// }

// static int M = 4;
//     static int N = 5;
     
//     // Function to preprocess input mat[M][N].
//     // This function mainly fills aux[M][N]
//     // such that aux[i][j] stores sum of
//     // elements from (0,0) to (i,j)
//     int preProcess(int mat[M][N], int aux[M][N])
//     {
//         // Copy first row of mat[][] to aux[][]
//         for (int i = 0; i < N; i++)
//             aux[0][i] = mat[0][i];
         
//         // Do column wise sum
//         for (int i = 1; i < M; i++)
//             for (int j = 0; j < N; j++)
//                 aux[i][j] = mat[i][j] + aux[i-1][j];
         
//         // Do row wise sum
//         for (int i = 0; i < M; i++)
//             for (int j = 1; j < N; j++)
//                 aux[i][j] += aux[i][j-1];
                 
//         return 0;
//     }
     
//     // A O(1) time function to compute sum
//     // of submatrix between (tli, tlj) and
//     // (rbi, rbj) using aux[][] which is
//     // built by the preprocess function
//     static int sumQuery(int aux[M][N], int tli, int tlj, int rbi, int rbj)
//     {
//         // result is now sum of elements
//         // between (0, 0) and (rbi, rbj)
//         int res = aux[rbi][rbj];
     
//         // Remove elements between (0, 0)
//         // and (tli-1, rbj)
//         if (tli > 0)
//             res = res - aux[tli-1][rbj];
     
//         // Remove elements between (0, 0)
//         // and (rbi, tlj-1)
//         if (tlj > 0)
//             res = res - aux[rbi][tlj-1];
     
//         // Add aux[tli-1][tlj-1] as elements
//         // between (0, 0) and (tli-1, tlj-1)
//         // are subtracted twice
//         if (tli > 0 && tlj > 0)
//             res = res + aux[tli-1][tlj-1];
     
//         return res;
//     }
     
//     // Driver code
//     void main ()
//     {
//         int mat[4][5] = {{1, 2, 3, 4, 6},
//                       {5, 3, 8, 1, 2},
//                       {4, 6, 7, 5, 5},
//                       {2, 4, 8, 9, 4}};
                         
//         int aux[M][N];
         
//         preProcess(mat, aux);
         
//         int tli = 2, tlj = 2, rbi = 3, rbj = 4;
         
//         printf("\nQuery1: %d", sumQuery(aux, tli, tlj, rbi, rbj));
         
//         tli = 0; tlj = 0; rbi = 1; rbj = 1;
         
//         printf("\nQuery2: %d", sumQuery(aux, tli, tlj, rbi, rbj));
         
//         tli = 1; tlj = 2; rbi = 3; rbj = 3;
         
//         printf("\nQuery3: %d", sumQuery(aux, tli, tlj, rbi, rbj));
//     }

#include<stdio.h>
#define inf 100
void main()
{
int i,j,arr[3][3];
 for(i=0;i<3;i++)
  for(j=0;j<3;j++)
  {
  scanf("%d",&arr[i][j]);
  if(arr[i][j]==0)
  arr[i][j]=inf;
  }
 if(arr[0][0]/arr[1][0]==arr[0][1]/arr[1][1]&&arr[0][0]/arr[1][0]==arr[0][2]/arr[1][2])
  printf("0#1");
 else if(arr[0][0]/arr[2][0]==arr[0][1]/arr[2][1]&&arr[0][0]/arr[2][0]==arr[0][2]/arr[2][2])
  printf("0#2");
 else if(arr[1][0]/arr[2][0]==arr[1][1]/arr[2][1]&&arr[1][0]/arr[2][0]==arr[1][2]/arr[2][2])
  printf("1#2");
 else
   printf("0#0");
}