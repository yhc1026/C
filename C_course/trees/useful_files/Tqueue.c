#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef BT *Qtype;

typedef struct Queuenode
{
    Qtype data;
    struct Qnode *next;
} Qnode;

typedef struct Queue
{
    Qnode *head;
    Qnode *tail;
    int size;
} Queue;

void createnode(Queue *Q, Qtype x)
{
    Q->head = NULL;
    Q->tail = NULL;
    Q->size = 0;
}

void destroy(Queue *Q)
{
    Qnode *Qhead = NULL;
    while (Q->head != NULL)
    {
        Qhead = Q->head;
        free(Q->head);
        Q->head = Qhead;
    }
    Q->head = Q->tail = NULL;
    Q->size = 0;
}

void Qpush(Queue *Q, Qtype x)
{
    Qnode *newnode = (Qnode *)malloc(sizeof(Qnode));
    newnode->next = NULL;
    newnode->data = x;
    if (Q->head == NULL)
    {
        Q->head = Q->tail = newnode;
    }
    else
    {
        Q->tail->next = newnode;
        Q->tail = newnode;
    }
    ++(Q->size);
}

void Qpull(Queue *Q)
{
    if (Q->head == NULL)
    {
        return;
    }
    Qnode *cur = Q->head->next;
    free(Q->head);
    Q->head = cur;
    (Q->size)--;
}

Qtype getfront(Queue *Q)
{

    Qtype x = Q->head->data;
    Qpull(Q);
    return x;
}

bool isempty(Queue *Q)
{
    if (Q->head == Q->tail && Q->head == NULL)
    {
        return true;
    }
    return false;
}
