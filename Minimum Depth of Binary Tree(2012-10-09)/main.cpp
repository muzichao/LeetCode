/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int minDepth(TreeNode *root)
{
    int iDepthLeft = 0;
    int iDepthRight = 0;

    if (NULL == root)
        return 0;
    else if (NULL == root->left)
    {
        return minDepth(root->right) + 1;
    }
    else if (NULL == root->right)
    {
        return minDepth(root->left) + 1;
    }
    else
    {
        iDepthLeft = minDepth(root->left);
        iDepthRight = minDepth(root->right);

        return  iDepthLeft <= iDepthRight ? iDepthLeft + 1 : iDepthRight + 1;
    }
}
