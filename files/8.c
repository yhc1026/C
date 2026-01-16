void Reverse(LinkNode *&L)
{
    LinkNode *pre = L;
    LinkNode *p = L->next->next;
    LinkNode *q = p->next;
    pre->next = NULL;
    while (q != NULL)
    {
        p->next = pre->next;
        pre->next = p;
        p = q;
        q = q->next;
    }
}