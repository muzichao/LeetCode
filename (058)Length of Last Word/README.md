#### 题目

给定由大写，小写字母和空格组成的字符串，返回最后一个单词的长度。如果不存在最后一个单词，返回0。

#### 测试用例

1. ""
2. " "
3. "a"
4. " a"
5. " a "
6. "a  b  "
7. "ab cd"

#### 分析

字符串包含三种类型：

1. 字母(一个和或多个连续)
2. 空格(一个和或多个连续)
3. 结束符('\0')

#### 流程

1. 从第一个字符开始
2. 判断是否是结束符
3. 单词长度初始为0
4. 查找连续的字母(下一个为空格或结束符)
5. 查找连续的空格(下一个为字母或结束符)
6. 跳转到2



