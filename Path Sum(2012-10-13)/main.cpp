#include <iostream>
#include <stdlib.h>

using namespace std;

typedef int dataType;
struct TreeNode
{
    dataType val;
    TreeNode *left, *right;

    TreeNode (dataType value)
    {
        this->val = value;
        this->left = NULL;
        this->right = NULL;
    }
};

/************************************************************************/
/*函数名：InsertBinaryTree
/*功  能：节点插入二叉树
/*返回值：无
/************************************************************************/
void InsertBinaryTree(TreeNode *pSubRoot, TreeNode *pNode)
{
    if (NULL == pNode || NULL == pSubRoot)
        cout << "error!" << endl;

    // 小的在左子树
    if (pNode->val <= pSubRoot->val)
    {
        // 下个节点为空，则插入，否则继续寻找
        if (NULL == pSubRoot->left)
            pSubRoot->left = pNode;
        else
            InsertBinaryTree(pSubRoot->left, pNode);
    }
    else // 大的在右子树
    {
        // 下个节点为空，则插入，否则继续寻找
        if (NULL == pSubRoot->right)
            pSubRoot->right = pNode;
        else
            InsertBinaryTree(pSubRoot->right, pNode);
    }
}

/************************************************************************/
/*函数名：CreateBinaryTree
/*功  能：创建二叉树
/*返回值：无
/************************************************************************/
TreeNode *CreateBinaryTree(int iBTNodeNum)
{
    TreeNode *pRoot = NULL;
    TreeNode *pNode = NULL;

    srand(5);
    for (int i = 0; i < iBTNodeNum; ++i)
    {
        pNode = new TreeNode(rand() % 20);
        cout << pNode->val << " ";

        if (NULL == pRoot)
            pRoot = pNode;
        else
            InsertBinaryTree(pRoot, pNode);
    }
    cout << endl;

    return pRoot;
}



/**
 * 是否存在路径和为sum
 * @param  root 根结点
 * @param  sum  查找路径和
 * @return      true 或者 false
 */
bool hasPathSum(TreeNode *root, int sum)
{
    if (NULL == root)
        return false;

    if (NULL == root->left && NULL == root->right)
        return sum == root->val;

    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

int main()
{
    TreeNode *pRoot = CreateBinaryTree(7);

    cout << "Result : " << hasPathSum(pRoot, 29) << endl;

    return 0;
}
