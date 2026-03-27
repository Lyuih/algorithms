
# 122. 买卖股票的最佳时机II

## 题目描述
[LeetCode 122. 买卖股票的最佳时机II](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/)

给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。然而，你可以在 同一天 多次买卖该股票，但要确保你持有的股票不超过一股。

返回 你能获得的 最大 利润 。
## 解题思路
- **核心算法**：贪心
- **思路**：
贪心点:能赚就赚,永远拿当前最低价

## 代码实现 
```C++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ret = 0;
        int prev = prices[0];
        for (int i = 1; i < n; ++i) {
            if (prices[i] > prev) {
                ret += (prices[i] - prev);
            }
            prev = prices[i];
        }
        return ret;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
