#include <stdio.h>
#include <stdbool.h>

void primeFun(int n)
{
    int a[n];

    int i = 2;
    while (i < n)
    {
        int j = 2;
        bool isPrime = true;
        while (j < i)
        {
            if (i % j == 0)
            {
                isPrime = false;
            }
            j++;
        }
        if (isPrime)
        {
            printf("%d ", i);
        }
        i++;
    }
}

int main(void)
{
    primeFun(10);
}