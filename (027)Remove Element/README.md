#### 题目

给定一个数组和一个元素，删除数组中的所有该元素并返回新数组的长度。

> PS：在原始数组操作，不要额外的分配数组空间。并且使用常量内存空间。

#### 示例

输入：`A= [1, 3, 2, 3]，3`
输出：`A= [1, 2], 长度为2`

#### 分析

可以使用两个索引，一个表示在原数组中的位置，一个表示在新数组的位置。如果原数组中的某个元素不等于给定元素，则加入新数组。


#### 流程

1. 初始化，两个索引分别指向数组的起始位置。
2. 遍历，如果原数组元素不等于给定元素，则在新数组加入该元素。
