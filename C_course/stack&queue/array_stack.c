// 栈使用顺序结构
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int *a; // 此处的*a作为数组地址来用
    int top;
    int capacity;
};
typedef struct stack ST;

void create(ST *pst)
{
    assert(pst);
    pst->top = -1;     // top指向栈顶数据，此时栈中无数据，top值为-1
    pst->capacity = 0; // 栈此时容量为0
    pst->a = NULL;
}

void delete(ST *pst)
{
    assert(pst);
    free(pst->a);
    pst->a = NULL;
    pst->top = -1;
    pst->capacity = 0;
}

void push(ST *pst, int x)
{
    if ((pst->top) + 1 == pst->capacity) // 判别栈容量是否够用
    {
        int newcapacity = 0;
        if (pst->capacity == 0) // 当栈为空
        {
            newcapacity = 4;
        }
        else // 当栈不为空
        {
            newcapacity = (pst->capacity) * 2;
        }
        int *tmp = (int *)realloc(pst->a, newcapacity * sizeof(int)); // 重新分配a指针指向的数组空间至tmp指针，容量为两倍（一个capacity对应1个sizeof(int)，也就是4bit）
        if (tmp == NULL)
        {
            perror("realloc");
            return;
        }
        pst->a = tmp;                // 改变结构体a指针指向
        pst->capacity = newcapacity; // 改变结构体capacity值
    }
    pst->a[++(pst->top)] = x;
}

void pop(ST *pst)
{
    assert(pst);
    if (!STEmpty(pst))
    {
        --(pst->top);
    }
}

int gettop(ST *pst)
{
    assert(pst);
    assert(!STEmpty(pst));
    return pst->a[pst->top];
}

int STEmpty(ST *pst)
{
    assert(pst);
    if (pst->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int size(ST *pst)
{
    assert(pst);
    return ((pst->top) + 1);
}

void teststack()
{
    ST st;
    create(&st);
    push(&st, 1);
    push(&st, 2);
    push(&st, 3);
    pop(&st);
    while (!STEmpty(&st))
    {
        printf("%d", gettop(&st));
        pop(&st);
    }
}
int main()
{
    teststack();
    return 0;
}