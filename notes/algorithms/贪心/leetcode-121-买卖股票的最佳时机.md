
# 121. 买卖股票的最佳时机

## 题目描述
[LeetCode 121. 买卖股票的最佳时机](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/)

给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
## 解题思路
- **核心算法**：贪心
- **思路**：
先求得后缀最大值求和，然后从前遍历找到最大的和差。

## 代码实现 
```C++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        vector<int> suf(n+1);
        for(int i = n-1;i>=0;--i)
        {
            suf[i] = max(suf[i+1],prices[i]);
        }
        int ret = 0;
        for(int i = 0;i<n;++i)
        {
            ret = max(ret,suf[i]-prices[i]);
        }
        return ret;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
