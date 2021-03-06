#### 题目

给定两个字符串型的二进制数，用字符串表示两个二进制数的和？

#### 示例

输入：a = "111", b = "10"

输出："1001"

#### 分析

两个二进制数：

无进位：0 + 1 = 1 + 0 = 1, flag = 0

有进位：0 + 1 + flag = 1 + 0 + flag = 0, flag = 1

*******************

无进位：1 + 1 = 0, flag = 1

有进位：1 + 1 + flag = 1, flag = 0

*******************

无进位：0 + 0 = 0, flag = 0

有进位：0 + 0 + flag = 0, flag = 0

******************

一个二进制数：

有进位：1 + flag = 0, flag = 1

其他都为0

> 两个二进制数的位数可能不同，所以先处理公共部份，再处理非公共部份。

string 重载了许多操作符，包括 +, +=, <, =, , [], <<, >>等，正式这些操作符，对字符串操作非常方便。

#### 流程

1. 对公共部份进行相加
2. 对单独部份进行相加
3. 判断是否有额外的进位
