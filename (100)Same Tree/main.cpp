/**
 * Given two binary trees, write a function to
 * check if they are equal or not.
 *
 * Two binary trees are considered equal if they
 * are structurally identical and the nodes have
 * the same value.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (NULL == p && NULL == q)
        return true;
    else if ((NULL != p && NULL == q) || (NULL == p && NULL != q))
        return false;
    else if (p->val != q->val)
        return false;
    else
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
