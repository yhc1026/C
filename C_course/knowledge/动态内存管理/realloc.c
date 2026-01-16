// 实现动态内存管理，第一个指针参数接收需要修改的空间地址，第二个参数接收修改的大小
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p = (int *)calloc(40, sizeof(int));
    int *ptr = realloc(p, 80);
    if (ptr != NULL) // 防止内存泄漏
    {
        p = ptr;
    }
    int t = 0;
    for (t = 0; t < 10; t++)
    {
        printf("%d\n", p[t]);
    }
    free(p);
    return 0;
}