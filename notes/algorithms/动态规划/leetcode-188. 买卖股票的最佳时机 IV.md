


# 188. 买卖股票的最佳时机 IV

## 题目描述
[LeetCode 188. 买卖股票的最佳时机 IV](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/description/)

给你一个整数数组 prices 和一个整数 k ，其中 prices[i] 是某支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。也就是说，你最多可以买 k 次，卖 k 次。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
## 解题思路
- **核心算法**：动态规划
- **思路**：
多状态dp，买入，可交易，当前剩余交易次数


## 代码实现
```python
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n = len(prices)
        k = k+1
        dp = [[[-inf] * k for _ in range(2)] for _ in range(n)]
        dp[0][0][0] = -prices[0]
        dp[0][1][0] = 0
        ret = 0
        for i in range(1, n):
            for j in range(k):
                dp[i][0][j] = max(dp[i - 1][0][j], dp[i - 1][1][j] - prices[i])
                if j > 0:
                    dp[i][1][j] = max(dp[i - 1][1][j], dp[i - 1][0][j - 1] + prices[i])
                else:
                    dp[i][1][j] = dp[i - 1][1][j]
        ret = 0
        for i in range(k):
            ret = max(dp[n-1][1][i],ret)
        return ret
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
