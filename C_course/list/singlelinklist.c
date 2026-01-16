#include <stdio.h>
#include <stdlib.h>

typedef struct SLTlink
{
    int data;
    struct SLTlink *next; // 链表节点为一个结构体，结构体中包含一个结构体指针元素，一般名称为next
};
typedef struct SLTlink SLT;

SLT *creatnode(int x)
{
    SLT *phead = (SLT *)malloc(sizeof(int));
    if (phead == NULL)
    {
        perror("malloc");
        return;
    }
    else
    {
        phead->data = x;
        phead->next = NULL;
        return phead;
    }
}

void SLTPrint(SLT *phead) // 打印链表
{
    SLT *cur = phead; // cur为一个临时指针，指向头节点的地址，头结点的地址为phead，通过cur来操作链表中的节点
    while (cur != NULL)
    {
        printf("%d->", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

void SLPushfront(SLT **phead, int x) // 头插法
{
    SLT *newnode = creatnode(x);
    newnode->next = *phead; // 本来phead指向原来的第一个节点，现在让newnode的指针获取phead指向的节点地址 //此处必须是phead，不能写NULL！
    *phead = newnode;       // phead要指向新的头节点的地址，也就是newnode的地址，因此将头节点地址复制给phead
}

void SLPushback(SLT **phead, int x)
{
    SLT *newnode = creatnode(x);
    if (*phead == NULL) // 解决尾插法空链表的问题
    {
        *phead = newnode;
    }
    else
    {
        while (*phead->next != NULL)
        {
            *phead = *phead->next;
        }
        *phead->next = newnode;
        *phead->data = x;
    }
}

void SLPopback(SLT **phead)
{
    if (*phead == NULL || *phead->next == NULL) // 检查头指针是否为空
    {
        return; // 头指针为空或者只有一个结点，则直接返回
    }

    while (*phead->!= NULL) // 找到倒数第二个结点
    {
        *phead = *phead->next;
    }
    SLT *tail = *phead; // 利用tail找到尾节点，同时保留phead的原始位置（倒数第二个节点），这样便于将倒数第二个节点的next置空
    tail = tail->next;
    free(tail); // 释放最后一个结点
    tail = NULL;
    *phead->next = NULL; // 将倒数第二个节点的next置空
}

void SLPopfront(SLT **head)
{
    if (*head == NULL || *head->next == NULL)
    {
        return;
    }
    else
    {
        SLT *phead = *head;
        phead = phead->next;
        free(*head);
        *head = phead;
    }
}

void TestSList1()
{
    SLT *plist = NULL;
    SLPushfront(&plist, 1);
    SLT *head = plist; // 因为代码缺陷，只能在这里临时使用一个head指针保存头节点地址
    SLPushfront(&plist, 2);
    SLPushfront(&plist, 3);
    SLPushfront(&plist, 4);
    SLPushfront(&plist, 5);
    SLTPrint(plist);
}

void TestSList2()
{
    SLT *plist = NULL;
    SLPushback(&plist, 1);
    SLPushback(&plist, 2);
    SLPushback(&plist, 3);
    SLPushback(&plist, 4);
    SLPushback(&plist, 5);
    SLTPrint(plist);
}

int main()
{
    TestSList1();
    return 0;
}