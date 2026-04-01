# 746. 使用最小花费爬楼梯

## 题目描述

[LeetCode 746. 使用最小花费爬楼梯](https://leetcode.cn/problems/min-cost-climbing-stairs/description/)

给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。

你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。

请你计算并返回达到楼梯顶部的最低花费。

## 解题思路

- **核心算法**：动态规划
- **思路**：
  定义dp[i] 表示 当前花费最小到大此位置
  dp[i] 的结果 可以根据dp[i-1]和dp[i-2]得到
  状态转移方程: dp[i] = min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
  因为问题问得是到达顶楼,这里的顶楼为 n

## 代码实现

```C++
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int n = cost.size();
        vector<int> dp(n);
        for(int i = 2;i<n;++i)
        {
            dp[i] = min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return min(dp[n-1]+cost[n-1],dp[n-2]+cost[n-2]);
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
