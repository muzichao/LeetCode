#### 题目

典型的Fibnacci序列问题：有n阶楼梯，每次只能爬1阶或者2阶，一共有多少种走法？

#### 分析

最后一次肯定是由第n-1或者第n-2个台阶到达第n阶台阶，所以f(n) = f(n-1) + f(n-2)
Fibnacci序列可以使用递归法和递推法，但是递归法效率太低，所以考虑使用递推法。

#### 流程

1. 初始化f(1) = 1; f(2) = 2;
2. 更新，f(n) = f(n-1) + f(n-2)