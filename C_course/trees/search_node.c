// 二叉树查找值为x的节点
BT *BTreeFind(BT *root, int x)
{
    BT *leftresult = rightresult = NULL;

    if (root == NULL)
    {
        return NULL;
    }
    leftresult = BTreeFind(root->left, x);
    if (leftresult)
    {
        return leftresult;
    }
    rightresult = BTreeFind(root->rightresult);
    if (rightresult)
    {
        return rightresult;
    }
    return NULL;
}