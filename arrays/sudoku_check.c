#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool check(int board[9][9])
{
    bool row[9] = {false};
    bool col[9] = {false};
    bool grid0[9] = {false};
    bool grid1[9] = {false};
    bool grid2[9] = {false};
    bool grid3[9] = {false};
    bool grid4[9] = {false};
    bool grid5[9] = {false};
    bool grid6[9] = {false};
    bool grid7[9] = {false};
    bool grid8[9] = {false};

    memset(grid0, false, sizeof(grid0));
    memset(grid1, false, sizeof(grid1));
    memset(grid2, false, sizeof(grid2));
    memset(grid3, false, sizeof(grid3));
    memset(grid4, false, sizeof(grid4));
    memset(grid5, false, sizeof(grid5));
    memset(grid6, false, sizeof(grid6));
    memset(grid7, false, sizeof(grid7));
    memset(grid8, false, sizeof(grid8));

    for (int i = 0; i < 9; i++)
    {
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(row));

        for (int n = 0; n < 9; n++)
        {
            if (board[i][n] > 0)
            {
                int rowIdx = board[i][n] - 1;
                if (row[rowIdx])
                {
                    printf("rowIdx : %d,%d", i, n);
                    return false;
                }
                row[rowIdx] = true;
            }

            if (board[n][i] > 0)
            {
                int colIdx = board[n][i] - 1;
                if (col[colIdx])
                {
                    printf("colIdx : %d,%d", n, i);
                    return false;
                }
                col[colIdx] = true;
            }

            int gridIdx = (i / 3) * 3 + n / 3;
// (0) (0) (0) (1) (1) (1) (2) (2) (2) 
// (0) (0) (0) (1) (1) (1) (2) (2) (2) 
// (0) (0) (0) (1) (1) (1) (2) (2) (2) 
// (3) (3) (3) (4) (4) (4) (5) (5) (5) 
// (3) (3) (3) (4) (4) (4) (5) (5) (5) 
// (3) (3) (3) (4) (4) (4) (5) (5) (5) 
// (6) (6) (6) (7) (7) (7) (8) (8) (8) 
// (6) (6) (6) (7) (7) (7) (8) (8) (8) 
// (6) (6) (6) (7) (7) (7) (8) (8) (8) 
            int gridVal = board[i][n];
            if (gridVal > 0)
            {
                if (gridIdx == 0)
                {
                    if (grid0[gridVal])
                    {
                        printf("grid0");
                        return false;
                    }
                    grid0[gridVal] = true;
                }
                else if (gridIdx == 1)
                {
                    if (grid1[gridVal])
                    {
                        printf("grid1");
                        return false;
                    }
                    grid1[gridVal] = true;
                }
                else if (gridIdx == 2)
                {
                    if (grid2[gridVal])
                    {
                        printf("grid2");
                        return false;
                    }
                    grid2[gridVal] = true;
                }
                else if (gridIdx == 3)
                {
                    if (grid3[gridVal])
                    {
                        printf("grid3");
                        return false;
                    }
                    grid3[gridVal] = true;
                }
                else if (gridIdx == 4)
                {
                    if (grid4[gridVal])
                    {
                        printf("grid4");
                        return false;
                    }
                    grid4[gridVal] = true;
                }
                else if (gridIdx == 5)
                {
                    if (grid5[gridVal])
                    {
                        printf("grid5");
                        return false;
                    }
                    grid5[gridVal] = true;
                }
                else if (gridIdx == 6)
                {
                    if (grid6[gridVal])
                    {
                        printf("grid6");
                        return false;
                    }
                    grid6[gridVal] = true;
                }
                else if (gridIdx == 7)
                {
                    if (grid7[gridVal])
                    {
                        printf("grid7");
                        return false;
                    }
                    grid7[gridVal] = true;
                }
                else if (gridIdx == 8)
                {
                    if (grid8[gridVal])
                    {
                        printf("grid8");
                        return false;
                    }
                    grid8[gridVal] = true;
                }
            }
        }
    }

    return true;
}

int main(void)
{
    int board[9][9] = {{4, 1, 0, 0, 7, 0, 0, 0, 5},
                       {0, 8, 0, 0, 0, 6, 0, 9, 0},
                       {0, 0, 0, 5, 0, 0, 0, 0, 0},
                       {0, 0, 7, 4, 0, 1, 3, 0, 0},
                       {5, 3, 0, 0, 0, 0, 0, 1, 2},
                       {0, 0, 4, 3, 0, 8, 7, 0, 0},
                       {0, 0, 0, 0, 0, 4, 0, 0, 0},
                       {0, 9, 0, 8, 0, 0, 0, 7, 0},
                       {7, 0, 0, 0, 6, 0, 0, 2, 8}};

    bool result = check(board);

    printf("result: %d ", result);
}

// {4, 1, 0, 0, 7, 0, 0, 0, 5},
// {0, 8, 0, 0, 0, 6, 0, 9, 0},
// {0, 0, 0, 5, 0, 0, 0, 0, 0},
// {0, 0, 7, 4, 0, 1, 3, 0, 0},
// {5, 3, 0, 0, 0, 0, 0, 1, 2},
// {0, 0, 4, 3, 0, 8, 7, 0, 0},
// {0, 0, 0, 0, 0, 4, 0, 0, 0},
// {0, 9, 0, 8, 0, 0, 0, 7, 0},
// {7, 0, 0, 0, 6, 0, 0, 2, 8}

// [0][0] [0][1]  [0][2]    [1][0] [1][1] [1][2]    [2][0] [2][1] [2][2]
// [0][3] [0][4]  [0][5]    [1][3] [1][4] [1][5]    [2][3] [2][4] [2][5]
// [0][6] [0][7]  [0][8]    [1][6] [1][7] [1][8]    [2][6] [2][7] [2][8]

// [3][0] [3][1]  [3][2]    [4][0] [4][1] [4][2]    [5][0] [5][1] [5][2]
// [3][3] [3][4]  [3][5]    [4][3] [4][4] [4][5]    [5][3] [5][4] [5][5]
// [3][6] [3][7]  [3][8]    [4][6] [4][7] [4][8]    [5][6] [5][7] [5][8]

// [6][0] [6][1]  [6][2]    [7][0] [7][1] [7][2]    [8][0] [8][1] [8][2]
// [6][3] [6][4]  [6][5]    [7][3] [7][4] [7][5]    [8][3] [8][4] [8][5]
// [6][6] [6][7]  [6][8]    [7][6] [7][7] [7][8]    [8][6] [8][7] [8][8]