#include <stdio.h>

void check(int matrix[4][5], int bottomIdx, int rightIdx)
{
    int topIdx = 0;
    int leftIdx = 0;

    while (topIdx <= bottomIdx && leftIdx <= rightIdx)
    {
        for (int col = leftIdx; col <= rightIdx; col++)
        {
            printf("%d ", matrix[topIdx][col]);
        }
        topIdx++;

        for (int row = topIdx; row <= bottomIdx; row++)
        {
            printf("%d ", matrix[row][rightIdx]);
        }
        rightIdx--;

        if (topIdx <= bottomIdx)
        {
            for (int col = rightIdx; col >= leftIdx; col--)
            {
                printf("%d ", matrix[bottomIdx][col]);
            }
        }
        bottomIdx--;

        if (leftIdx <= rightIdx)
        {
            for (int row = bottomIdx; row >= topIdx; row--)
            {
                printf("%d ", matrix[row][leftIdx]);
            }
        }
        leftIdx++;
    }
}

int main(void)
{
    int board[4][5] = {{1, 2, 3, 4, 5},
                       {14, 15, 16, 17, 6},
                       {13, 20, 19, 18, 7},
                       {12, 11, 10, 9, 8}};

    check(board, 3, 4);
}