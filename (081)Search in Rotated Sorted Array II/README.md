#### 题目

假设一个有序数组在某个结点存在反转（例如：0 0 1 2 4 5 6 7 变成 4 5 6 7 0 0 1 2）。给定一个数target，如果反转后的数组中存在target，则返回true，否则返回false。

> PS：假设数组中可以有相同元素。


#### 示例

输入：`[1, 3], 2`
输出：`false`

输入：`[1, 1, 2, 3], 2`
输出：`ture`

输入：`[1, 1, 1, 3, 1], 3`
输出：`true`

输入：`[1, 3, 1, 1, 1], 3`
输出：`true`


#### 分析

方法1:

从起始位置开始遍历整个数组，查找是否存在与target相同的元素？有，返回true；无，返回false。

方法2：

方法1中没有利用数组的有序性，对应有序数组可以用二分法查找，但是此时的数组不是完全有序的，所以要进行一些预处理。找到合适的查找区间，在查找区间里使用二分法查找。

> 注意：由于存在重复元素，所以二分查找可能存在一些问题。如：查找区间`[1, 3, 1, 1, 1]`，由于中值为1，等于左边界和右边界，就无法判断下一个区间是左区间还是有区间。此时有个很巧妙方法，令左边界加1，令右边界减1，此时不影响查找结果。

#### 流程

1. 判断是否有转折？
    1. 有，跳转到2
    2. 无，整个数组为查找区间，跳转到4
2. 使用二分法查找转折点的位置
3. 确定查找区间，判断需要查找的数属于转折点之前的区间还是转折点之后的区间，或者不在数组区间里。
4. 在查找区间里使用二分法查找目标数。
5. 找到，返回true；否则，返回false

