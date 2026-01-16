void sort(LinkNode *&L)
{
    LinkNode *pre = L;
    LinkNode *p = pre->next->next;
    LinkNode *q = p->next;
    pre->next->next = NULL;

    while (p != NULL)
    {
        if (pre->next->data < p->data)
        {
            while (pre->next != NULL && pre->Next->data < p->data)
            {
                pre = pre->next;
            }
        }
        p->next = pre->next;
        pre->next = p;
        p = q;
        q = q->next;
    }
}
