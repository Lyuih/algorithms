# 1137. 第 N 个泰波那契数

## 题目描述

[LeetCode 1137. 第 N 个泰波那契数](https://leetcode.cn/problems/n-th-tribonacci-number/description/)

泰波那契序列 Tn 定义如下：

T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2

给你整数 n，请返回第 n 个泰波那契数 Tn 的值。

## 解题思路

- **核心算法**：动态规划
- **思路**：
  斐波那契变种

## 代码实现

```C++
class Solution {
public:
    int tribonacci(int n) {
        if (n <= 1)
            return n;
        else if (n == 2)
            return 1;
        int ret = 2;
        int prev_1 = 1;
        int prev_2 = 1;
        int prev_3 = 0;
        for (int i = 3; i <= n; ++i) {
            ret = prev_1 + prev_2 + prev_3;

            prev_3 = prev_2;
            prev_2 = prev_1;
            prev_1 = ret;
        }

        return ret;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
