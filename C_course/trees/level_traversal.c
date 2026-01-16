// 利用队列
// 程序无法运行是因为TQueue.c类型不匹配
#include "D:\codeC\vscodeC\C_course\C-course\C_course\trees\binary_tree.c"
#include "D:\codeC\vscodeC\C_course\C-course\C_course\trees\useful_files\Tqueue.c"

void leveltraversal(BT *root)
{
    Queue Q;
    createnode(*Q, root);
    if (root)
    {
        Qpush(&Q, root);
    }
    while (!isempty(&Q))
    {
        BT *node = getfront(&Q);
        printf("%d", node->data);
    }
    if (node->left)
    {
        Qpush(&Q, node->left);
    }
    if (node->right)
    {
        Qpush(&Q->right);
    }
}