// 队列使用链式结构
#include <stdio.h>
#include <stdlib.h>

struct Queuenode
{
    int data;
    struct Queuenode *next;
};
typedef struct Queuenode Qnode;

struct Queuemessage // 这样更好的管理队列,改变结构体内的指针，相当于改变的是结构体，不需要使用二级指针
{
    int size;
    Qnode *phead;
    Qnode *ptail;
};
typedef struct Queuemessage Qmessage;

void createnode(Qmessage *pq, int x)
{
    pq->phead = (Qnode *)malloc(sizeof(int));
    (pq->phead)->next = NULL;
    (pq->phead)->data = x;
    pq->ptail = pq->phead;
    (pq->size) = 1;
}

void pushnode(Qmessage *pq, int x)
{
    Qnode *head = pq->phead;
    Qnode *newnode = (Qnode *)malloc(sizeof(int));
    (pq->ptail)->next = newnode;
    newnode->data = x;
    newnode->next = NULL;
    pq->ptail = newnode;
    pq->phead = head;
    (pq->size)++;
}

void popnode(Qmessage *pq)
{
    if (testempty(pq))
    {
        return;
    }
    else
    {
        Qnode *head = (pq->phead)->next;
        free(pq->phead);
        pq->phead = head;
        --(pq->size);

        if (pq->phead == NULL)
        {
            pq->ptail = NULL;
        }
    }
}

int gethead(Qmessage *pq)
{
    if (testempty(pq))
    {
        return -1;
    }
    else
    {
        int x = (pq->phead)->data;
        Qnode *head = pq->phead;
        pq->phead = (head)->next;
        free(head);
        if (pq->phead == NULL)
        {
            pq->ptail = NULL;
        }
        (pq->size)--;
        return x;
    }
}

int testempty(Qmessage *pq)
{
    if ((pq->size) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int getsize(Qmessage *pq)
{
    return pq->size;
}

void testqueue()
{
    Qmessage message = {0, NULL, NULL};
    Qmessage *pq = &message;

    createnode(pq, 0);
    pushnode(pq, 1);
    pushnode(pq, 2);
    pushnode(pq, 3);
    pushnode(pq, 4);
    pushnode(pq, 5);
    popnode(pq);
    printf("%d-", gethead(pq));
    printf("%d-", gethead(pq));
    printf("%d-", gethead(pq));
    printf("%d-", gethead(pq));
    printf("%d-", gethead(pq));
    printf("%d-", gethead(pq));
}

int main()
{
    testqueue();
    return 0;
}