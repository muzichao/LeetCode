#### 题目

给定链表，从头开始，每两个结点一组，然后分别交换每组中结点的位置，并返回头节点。

> PS: 使用常量内存空间，仅交换结点，不修改结点内的值。

#### 示例

输入：` `
输出：` `

输入：`1`
输出：`1`

输入：`1->2->3`
输出：`2->1->3`

输入：`1->2->3->4`
输出：`2->1->4->3`

#### 分析

1. 如果链表为空，或者只有一个结点，直接返回即可
2. 如果有奇数个结点，那么最后一组只有一个结点，不用交换。此时，如示例3，1结点的下一个结点指向了3结点。
3. 如果有偶数个结点，则每一组分别交换。此时，如示例4，1结点的下一个结点指向了4结点。

#### 流程

1. 判断是否为空或者只有1个结点？是，则返回头指针；不是，则让令头指针指向第二个结点。
2. 判断是否为空或者只有1个结点？是，则返回头指针；不是，继续。一个指针指向当前组的结点(1->2->)；另一个指针指向下一组的结点(3->或3->4->)。
3. 当前组结点的第二个结点指向第一个结点(1->2->1)
4. 如果下一组只有一个结点或者为空，则当前组的第一个结点指向下一组的该结点(2->1->3)或者指向空；如果下一组有两个结点，则当前组的第一个结点指向下一组的第二个结点(2->1->4)
5. 把第二组结点作为当前结点。跳转到第2步。