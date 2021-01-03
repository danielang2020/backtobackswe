#include <stdio.h>
#include <stdbool.h>

bool find3Numbers(int A[], int arr_size, int sum)
{
    int l, r;
    for (int i = 0; i < arr_size - 2; i++)
    {
        for (int m = i + 1; m < arr_size - 1; m++)
        {
            for (int n = m + 1; n < arr_size; n++)
            {
                if (A[i] + A[m] + A[n] == sum)
                {
                    printf("%d %d %d\n", A[i], A[m], A[n]);

                    return true;
                }
            }
        }
    }

    return false;
}

int main(void)
{
    int A[] = {1, 4, 45, 6, 10, 8};
    int sum = 22;
    int arr_size = sizeof(A) / sizeof(A[0]);
    find3Numbers(A,arr_size,sum);

    return 0;

}