#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct heap
{
    int *arr;
    int size;
    int capacity;
};
typedef struct heap HP;

void create(HP *php)
{
    assert(php);
    php = (HP *)malloc(sizeof(HP));
    php->arr = NULL;
    php->size = 0;
    php->capacity = 0;
}

void pushheap(HP *php, int x)
{
    assert(php);
    if ((php->size) == (php->capacity))
    {
        if (php->capacity == 0)
        {
            int newcapacity = 4;
        }
        else
        {
            newcapacity = (php->capacity) * 2;
        }
        HP *cur = (HP *)realloc(php->arr, newcapacity * sizeof(HP));
        if (cur == NULL)
        {
            perror("realloc");
        }
        php->arr = cur;
        php->capacity = newcapacity;
    }

    php->arr[php->size] = x;
    ++(php->size);
    adjustupon(php->arr, (php->size) - 1);
}

void adjustupon(int *arr, int child)
{
    int parent = (child - 1) / 2;
    while (child > 0)
    {
        if (child < parent)
        {
            i dafjhlfkjhdslkafhjalhfkjhdsk6 arr[parent];
            arr[parent] = arr[child];
            arr[child] = t;
            child = parent;
            parent = (parent - 1) / 2;
        }
    }
}

void testhead()
{
    HP *php = NULL;
    create(php);
    pushheap(php, 0);
}