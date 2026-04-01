# 面试题 08.01. 三步问题

## 题目描述

[LeetCode 面试题 08.01. 三步问题](https://leetcode.cn/problems/three-steps-problem-lcci/description/)

三步问题。有个小孩正在上楼梯，楼梯有 n 阶台阶，小孩一次可以上 1 阶、2 阶或 3 阶。实现一种方法，计算小孩有多少种上楼梯的方式。结果可能很大，你需要对结果模 1000000007。

## 解题思路

- **核心算法**：动态规划
- **思路**：
  就是青蛙跳台阶

## 代码实现

```C++
class Solution {
public:
    const int mod = (1e9 + 7);
    int waysToStep(int n) {
        #define int long long
        if (n <= 2)
            return n;
        else if (n == 3)
            return 4;
        int ret = 0;
        int prev_1 = 4;
        int prev_2 = 2;
        int prev_3 = 1;
        for (int i = 4; i <= n; ++i) {
            ret = (prev_1%mod + prev_2%mod + prev_3%mod)%mod;
            prev_3 = prev_2%mod;
            prev_2 = prev_1%mod;
            prev_1 = ret;
        }
        #undef int
        return ret;
    }
};

/*
1 2 3
1 2 4

*/
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
