#### 题目

给定一个m x n的矩阵，如果某个元素为0，则令该元素所在的行和列为0。

#### 示例

输入：

    2 3 4 1 5 1
    5 5 4 4 5 4
    3 2 0 5 0 0
    0 2 0 1 5 3
    3 5 3 2 5 0

输出：

    0 3 0 1 0 0
    0 5 0 4 0 0
    0 0 0 0 0 0
    0 0 0 0 0 0
    0 0 0 0 0 0

#### 分析

如果边查找边修改，修改的结果会影响后序的查找，所以可以先查找，保存查找结果，然后遍历修改。

#### 流程

1. 声明两个数组
2. 一个标记哪些行有0； 一个标记哪些列有0
3. 遍历，把标记的行置为0；
4. 遍历，把标记的列置为0
