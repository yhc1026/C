// 内存开辟,向内存申请一块指定大小的空间，并返回这个空间的指针，该指针为void*类型；如果开辟失败，则返回一个NULL类型的指针
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p = (int *)malloc(4); //   用p指针接收malloc开辟空间的地址，并强制类型转换将void*类型的指针转换为int*的指针
    printf("%d", *p);
    return 0;
}