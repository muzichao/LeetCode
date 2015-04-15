/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> iResult;

    stack<TreeNode*> sNode;
    TreeNode *currentNode = root;

    while (!sNode.empty() || NULL != currentNode)
    {
        while (NULL != currentNode)
        {
            iResult.push_back(currentNode->val);
            sNode.push(currentNode);
            currentNode = currentNode->left;
        }
        if (!sNode.empty())
        {
            currentNode = sNode.top();
            sNode.pop();
            currentNode = currentNode->right;
        }
    }
    return iResult;
}


/************************************************************************/
/*函数名：PreOrderBinaryTree
/*功  能：前序遍历二叉树：根-左-右
/*返回值：无
/************************************************************************/
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> iResult;
    // 先判断是否为空，不为空再遍历
    if (NULL != root)
    {
        PreOrderBinaryTree(root, iResult);
    }

    return iResult;
}
vector<int> PreOrderBinaryTree(TreeNode *root, vector<int> &iResult)
{
    if (NULL != root)
    {
        // 先输出根节点，然后遍历左节点，遍历右节点
        iResult.push_back(root->val);

        PreOrderBinaryTree(root->left);
        PreOrderBinaryTree(root->right);
    }

    return iResult;
}
