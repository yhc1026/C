#include "D:\codeC\vscodeC\C_course\C-course\C_course\trees\useful_files\TBTree.c"
#include "D:\codeC\vscodeC\C_course\C-course\C_course\trees\useful_files\Tqueue.c"
#include <stdbool.h>

bool iscompleteBtree(BT *root)
{
    if (root == NULL)
    {
        return true;
    }
    Queue Q;
    createnode(&Q, 0);
    Qpush(&Q, root);
    int flag = 1;
    while (!isempty(&Q))
    {
        Qtype x = getfront(&Q);
        if (x)
        {
            Qpush(&Q, x->left);
            Qpush(&Q, x->right);

            if (flag == 0)
            {
                return false;
            }
        }
        else
        {
            flag = 0;
        }
    }
    return true;
}

int main()
{
    BT *root = createtree();
    if (iscompleteBtree(root))
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
}