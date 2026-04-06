


# 309. 买卖股票的最佳时机含冷冻期

## 题目描述
[LeetCode 309. 买卖股票的最佳时机含冷冻期](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/)
给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
## 解题思路
- **核心算法**：动态规划
- **思路**：
多状态dp，分三个状态：买入，可交易，冷静期
理解这三个状态间的转化即可

## 代码实现
```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        '''
        三种状态:买入 可交易 冷静
        '''
        n = len(prices)
        dp1,dp2,dp3 = [0]*n,[0]*n,[0]*n
        dp1[0],dp2[0],dp3[0] = -prices[0],0,0
        for i in range(1,n):
            dp1[i] = max(dp1[i-1],dp2[i-1]-prices[i])
            dp2[i] = max(dp3[i-1],dp2[i-1])
            dp3[i] = dp1[i-1]+prices[i]
        return max(dp1[n-1],dp2[n-1],dp3[n-1])
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
