#include <stdio.h>

void swap(int *x, int *y);

int main()
{
    int a = 1, b = 2;
    printf("%d, %d\n", a, b);
    swap(&a, &b);
    int sum = a + b;
    printf("%d, %d, sum=%d\n", a, b, sum);
    return 0;
}

void swap(int *x, int *y)
{
    int t = 0;
    t = *x;
    *x = *y;
    *y = t;
}