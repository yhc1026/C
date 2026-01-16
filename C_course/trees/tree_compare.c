bool treecompare(BT *root1, BT *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }

    if (root1->data != root2->data)
    {
        return false;
    }
    return treecompare(root1->left, root2->left) && treecompare(root1->right, root2->right);
}