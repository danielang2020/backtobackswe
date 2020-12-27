#include <stdio.h>

void rotate(int matrix[4][4], int r, int c)
{
    int idx = r - 1;
    for (int layer = 0; layer < r / 2; layer++)
    {
        for (int i = layer; i < idx - layer; i++)
        {
            int top = matrix[layer][i];
            int right = matrix[i][idx - layer];
            int bottom = matrix[idx - layer][idx - i];
            int left = matrix[idx - i][layer];

            printf("----- matrix[%d][%d] matrix[%d][%d] matrix[%d][%d] matrix[%d][%d]\n", layer, i, i, idx - layer, idx - layer, idx - i, idx - i, layer);

            matrix[layer][i] = left;
            matrix[i][idx - layer] = top;
            matrix[idx - layer][idx - i] = right;
            matrix[idx - i][layer] = bottom;            
        }
    }
}
 

int main(void)
{
    int matrix1[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int matrix2[2][2] = {{10, 20}, {30, 40}};

    rotate(matrix1, 4, 4);
    // rotate(matrix2, 2, 2);

    for (int i = 0; i < 4; i++)
    {
        printf("row %d \n", i);
        for (int n = 0; n < 4; n++)
        {
            printf("%d,", matrix1[i][n]);
        }
        printf("\n");
    }
}
