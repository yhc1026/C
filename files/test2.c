#include <stdio.h>

void test(int *p)
{
    printf("%d\n%d\n%d", *p, *(p + 1), *(p + 2));
}

int main()
{
    int arr[3] = {0, 1, 2};
    test(arr);
    return 0;
}
