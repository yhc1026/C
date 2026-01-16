void split(LinkNode *&L, LinkNode *&L1, LinkNode *&L2)
{
    LinkNode *p = L->next;
    LinkNode *q = (LinkNode *)malloc(sizeof(LinkNode));
    q = L->next->next;
    while (p != NULL && q != NULL)
    {
        P->next = q->next;
        p = q->next;
        q->next = p->next;
        q = p->next;
        L1 = L;
        L2->next = q;
    }
}
