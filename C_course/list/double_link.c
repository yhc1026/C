// 双向带头链表，一个节点的指针域有prev和next两个指针，指向该节点的前后节点。如果链表只有一个节点，则prev和next都指向他自己
// 相对于单链表，双链表不用二级指针，不需要遍历整个链表，链表的空或非空在插入节点时没有区别

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct DList
{
    struct DLisT *prev;
    struct DLisT *next;
    int data;
};
typedef struct DList DLT;

void createnode(DLT **phead)
{
    *phead = (DLT *)malloc(sizeof(int));
    (*phead)->next = *phead;
    (*phead)->prev = *phead;
    (*phead)->data = 0;
}

void pushback(DLT *phead, int x)
{
    DLT *node = (DLT *)malloc(sizeof(int));
    DLT *tail = phead->prev;
    tail->next = node;
    node->prev = tail;
    phead->prev = node;
    node->next = phead;
    node->data = x;
}

void pushfront(DLT *phead, int x)
{
    DLT *node = (DLT *)malloc(sizeof(int));
    DLT *cur = phead->next;
    phead->next = node;
    node->prev = phead;
    cur->prev = node;
    node->next = cur;
    node->data = x;
}

void print(DLT *phead)
{
    DLT *head = phead;
    phead = phead->next;
    while ((phead) != head)
    {
        printf("%d-", (phead->data));
        phead = phead->next;
    }
}

void insert(DLT *phead, int x, int y) // 还需要修改
{
    DLT *head = phead;
    phead = phead->next;
    while (phead->data != x && phead->next != head)
    {
        phead = phead->next;
    }
    DLT *node = (DLT *)malloc(sizeof(int));
    DLT *next = phead->next;
    node->prev = phead;
    node->next = next;
    next->prev = node;
    phead->next = node;
    node->data = y;
}

void delete(DLT *phead, int x)
{
    DLT *head = phead;
    phead = phead->next;
    while (phead->next != head && phead->data != x)
    {
        phead = phead->next;
    }
    DLT *prev = phead->prev;
    DLT *next = phead->next;
    prev->next = next;
    next->prev = prev;
    free(phead);
}

void testlist()
{
    DLT *phead = NULL;
    DLT *ptail = NULL;
    createnode(&phead);
    pushfront(phead, 1);
    pushfront(phead, 2);
    pushfront(phead, 3);
    pushfront(phead, 4);
    delete (phead, 4);
    print(phead);
}

int main()
{
    testlist();
    return 0;
}