void pre_order(BiTree root)
{
    Stack S;
    BiTree p;
    init_stack(&S);
    push(&S, root);
    while (!is_empty(&S))
    {
        pop(&S, &p);
        visit_node(p);
        if (p->right != NULL)
            push(&S, p->right);
        if (p->left != NULL)
            push(&S, p->left);
    }
}