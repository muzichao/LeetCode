#### 题目

给定一个字符串，包含'(', ')', '{', '}', '[' 和 ']'这六种括号，判断字符串是否有效。

> PS: 括号的顺序必须准确。"()" 和 "()[]{}" 都是有效字符串，但是 "(]" and "([)]" 是无效的。

#### 示例

输入：`(a[bc]de{fab})`

输出：`true`

输入：`()`

输出：`true`

输入：`abcd`

输出：`true`

输入：`(abd]`

输出：`false`


输入：`(abd]`

输出：`false`

输入：`[dbd(abd]eg)`

输出：`false`

#### 流程

1. 从头开始遍历字符串
2. 遇到左括号，入栈
3. 遇到右括号
    1. 判断栈是否为空？空，返回`false`。否则继续
    2. 判断栈顶字符是否匹配？不匹配，返回`false`；匹配，栈顶元素出栈，转到下一字符。
