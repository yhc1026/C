#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
struct heap
{
    int size;
    int capacity;
    int *arr;
};
typedef struct heap HP;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void sortarrow(int arr2[], int x, HP *php)
{
    int t = x;

    php->arr = (int *)malloc(sizeof(int) * x);
    while (x > 0)
    {
        php->arr[t - x] = arr2[x - 1];
        x--;
        (php->size)++;
        adjustupon(php->arr, (php->size) - 1);
    }
    printheap(php);
}

void adjustdown(HP *php)
{
    int parent = 0;
    int child = parent * 2 + 1;

    while (child < php->size)
    {
        if (parent * 2 + 2 < (php->size) && php->arr[child] < php->arr[parent * 2 + 2])
        {
            child += 1;
        }
        if (php->arr[parent] < php->arr[child])
        {
            swap(&php->arr[parent], &php->arr[child]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

void adjustupon(int *arr, int child)
{
    int parent = (child - 1) / 2;
    while (child > 0)
    {
        if (arr[child] > arr[parent])
        {
            swap(&arr[parent], &arr[child]);
            child = parent;
            parent = (parent - 1) / 2;
        }
        else
        {
            break;
        }
    }
}

int popheap(HP *php)
{
    int x = php->arr[0];
    swap(&php->arr[0], &php->arr[php->size - 1]);
    (php->size)--;
    adjustdown(php);
    return x;
}

void printheap(HP *php)
{
    while ((php->size) > 0)
    {
        printf("%d-", popheap(php));
    }
}

int main()
{
    HP heap = {0, 0, NULL};
    HP *php = &heap;
    int arr2[] = {5, 4, 8, 2, 9, 3, 55, 98, 63, 75, 12, 46, 85, 62, 39};
    sortarrow(arr2, sizeof(arr2) / sizeof(int), php);
    return 0;
}