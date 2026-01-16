// 实现链表的创建，插入和删除

struct SListT // 创建链表
{
    int data;
    struct SListT *next;
};
typedef struct SListT SLT;

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

SLT *creatnode()
{
    SLT *phead = (SLT *)malloc(sizeof(SLT));
    if (phead == NULL)
    {
        perror("malloc");
        return NULL;
    }
    phead->data = 0;
    phead->next = NULL;
    return phead;
}

void pushfront(SLT **phead, SLT **head, int x)
{
    *phead = *head;
    SLT *front = (SLT *)malloc(sizeof(SLT));
    if (front == NULL)
    {
        perror("malloc");
        return;
    }
    front->data = x;
    front->next = *phead;
    *phead = front;
    *head = front;
}

void pushback(SLT **phead, int x)
{
    while ((*phead)->next != NULL)
    {
        *phead = (*phead)->next;
    }
    SLT *back = (SLT *)malloc(sizeof(SLT));
    if (back == NULL)
    {
        perror("malloc");
        return;
    }
    back->data = x;
    back->next = NULL;
    (*phead)->next = back;
}

void popfront(SLT **head)
{
    SLT *phead = *head;
    phead = phead->next;
    (*head)->next = NULL;
    free(*head);
    (*head) = NULL;
    (*head) = phead;
}

void popback(SLT **phead)
{
    if ((*phead) == NULL)
    {
        assert(0);
    }
    else
    {
        SLT *tail = *phead;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        while ((*phead)->next != tail)
        {
            *phead = (*phead)->next;
        }
        (*phead)->next = NULL;
        free(tail);
        tail = NULL;
    }
}

void printlist(SLT *head)
{
    while (head != NULL)
    {
        printf("%d-", head->data);
        head = head->next;
    }
    printf("\n");
}

void testlist()
{
    int x = 0;
    SLT *plist = NULL;
    plist = creatnode();
    SLT *head = plist;

    pushback(&plist, 1);
    pushback(&plist, 2);
    pushback(&plist, 3);
    pushback(&plist, 4);
    pushback(&plist, 5);
    insert(&head, 1, 6);
    erase(&head, 6);
    printlist(head);
}

void searchnode(SLT *head, int x)
{
    SLT *plist = NULL;
    while (head->next != NULL && head->data != x)
    {
        plist = head;
        head = head->next;
    }
    printf("%p\n", plist->next);
    return;
}

void insert(SLT **head, int x, int y)
{
    SLT *phead = *head;
    if (*head == NULL)
    {
        return;
    }
    else
    {
        while ((*head)->next != NULL && (*head)->data != x)
        {
            *head = (*head)->next;
        }
        if ((*head)->next == NULL)
        {
            SLT *node = (SLT *)malloc(sizeof(int));
            node->next = NULL;
            (*head)->next = node;
            node->data = y;
        }
        else
        {
            SLT *node = (SLT *)malloc(sizeof(int));
            node->next = (*head)->next;
            (*head)->next = node;
            node->data = y;
        }
    }
    *head = phead;
}

void erase(SLT **head, int x)
{
    SLT *prev = *head;
    SLT *next = *head;
    SLT *phead = *head;
    *head = (*head)->next;
    if (*head == NULL)
    {
        return;
    }
    else
    {
        while ((*head)->next != NULL && (*head)->data != x)
        {
            prev = *head;
            *head = (*head)->next;
        }
        if ((*head)->next != NULL)
        {
            next = (*head)->next;
        }
        else
        {
            next = NULL;
        }
    }
    free(*head);
    *head = phead;
    prev->next = next;
}

int main()
{
    testlist();
    return 0;
}