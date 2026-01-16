#include <stdio.h>
int main()
{
    int a = 123;
    int *pa = &a;
    float *pc = &a; // 函数栈帧
    printf("%d, %d\n", *(pa + 1), *(pc + 1));
    printf("%p, %p\n", (pa), (pc));
    printf("%p, %p\n", (pa + 1), (pc + 1));
    return 0;
}