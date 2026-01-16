#define N 10
#include <stdio.h>
#include <stdlib.h>

typedef struct INFO
{
    int *a;
    int size;
    int capacity;
} Info;

void start(Info *info)
{
    info->a = (int *)malloc(sizeof(int));
    info->size = N;
    info->capacity = N;
}

void pushback(Info *info, int *x)
{
    info->a[(info->size) - 1] = *x;
    info->size++;
}

int main()
{
    int x = 10;
    Info info;
    start(&info);
    int i = 0;
    for (i = 0; i < 9; i++)
    {
        info.a[i] = i;
    }
    pushback(&info, &x);
    for (i = 0; i < (info.size) - 1; i++)
    {
        printf("%d\n", info.a[i]);
    }
    return 0;
}