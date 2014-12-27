#### 题目

给定一个二叉树和一个数，判断在二叉树中是否存在一条从根结点到叶节点的路径，满足路径的和等于给定的数。

#### 示例

给定一下的二叉树以及`sum = 22`

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

返回 ture，因为存在 5->4->11->2 的和等于22。

#### 分析

二叉树中很多算法都可以使用递归操作，此题目也可以。

如上述二叉树，因为结点5有左右孩子，因此判断结点5的左右孩子是否存在一条路径的和为22-5=17；然后判断4结点，因为4结点只有左孩子，因此判断4的左孩子中是否有一条路径为17-4=11，同时判断结点8。。。以此类推。

#### 流程

    bool hasPathSum(TreeNode *root, int sum)
    {
        if (NULL == root)
            return false;

        if (NULL == root->left && NULL == root->right)
            return sum == root->val;

        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
