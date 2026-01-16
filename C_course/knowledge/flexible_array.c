// 柔性数组指的是在C99中，结构体中最后一个元素允许是未知大小的数组，这叫做柔性数组成员
// 柔性数组前面至少有一个其他成员
// 柔性数组的结构体计算大小时不包括柔性数组的大小
#include <stdio.h>
#include <stdlib.h>

typedef struct a
{
    int n;
    int arr[];
} a;

int main()
{
    a *p = (a *)malloc(sizeof(a) + 40); // 利用malloc定义柔性数组arr的长度
    if (p == NULL)
    {
        perror("malloc");
        return;
    }
    p->n = 1;
    p->arr[4] = 10;
    printf("%d.%d\n", p->n, p->arr[4]);
    printf("%d\n", (unsigned int)sizeof(a));
    
    a *ptr = realloc(p, sizeof(a) + 60);
    if (ptr == NULL)
    {
        perror(realloc);
        return;
    }
    else
    {
        p = ptr;
    }
    ptr = NULL;
    p->arr[12] = 9;
    printf("%d", p->arr[12]);
    free(p);
    p = NULL;
    return 0;
}