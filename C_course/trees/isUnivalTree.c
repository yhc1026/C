// 判断是否为单值二叉树

#include "binary_tree.c"
bool isUnivalTree(TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left != NULL && root->data != root->left->data)
    {
        return false;
    }
    if (root->right != NULL && root->data != root->right->data)
    {
        return false;
    }
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}