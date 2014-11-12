int maxDepth(TreeNode *root)
{
    int iDepth = 0;
    int iDepthLeft = 0;
    int iDepthRight = 0;

    if (NULL == root)
        return 0;
    else
    {
        iDepthLeft = maxDepth(root->left);
        iDepthRight = maxDepth(root->right);

        return  iDepthLeft >= iDepthRight ? iDepthLeft + 1 : iDepthRight + 1;
    }
}
