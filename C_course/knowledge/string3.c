#include <Stdio.h>
int main()
{
    int a = 1, b = 2, c = 3;
    int *arr[] = {&a, &b, &c};
    printf("%d", *arr[2]);
    return 0;
}