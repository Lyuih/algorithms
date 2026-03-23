# 375. 猜数字大小 II
## 题目描述
[LeetCode 375. 猜数字大小 II](https://leetcode.cn/problems/guess-number-higher-or-lower-ii/description/)

我们正在玩一个猜数游戏，游戏规则如下：

我从 1 到 n 之间选择一个数字。
你来猜我选了哪个数字。
如果你猜到正确的数字，就会 赢得游戏 。
如果你猜错了，那么我会告诉你，我选的数字比你的 更大或者更小 ，并且你需要继续猜数。
每当你猜了数字 x 并且猜错了的时候，你需要支付金额为 x 的现金。如果你花光了钱，就会 输掉游戏 。
给你一个特定的数字 n ，返回能够 确保你获胜 的最小现金数，不管我选择那个数字 。

 
## 解题思路
- **核心算法**：记忆化搜索
- **思路**：
利用记忆化来记录每一段区间的最优答案
dfs用来处理一段区间的最优路径里面的最大值
分段dfs得到答案

## 代码实现 (Python)
```C++
class Solution {
public:
int memo[201][201];
    int getMoneyAmount(int n) {
        return dfs(1,n);
    }
    int dfs(int l,int r)
    {
        if(l>=r) return 0;
        if(memo[l][r]!=0) return memo[l][r];
        int ret = INT_MAX;
        for(int i = l;i<=r;++i)
        {
            int a = dfs(l,i-1);
            int b = dfs(i+1,r);
            ret = min(ret,i+max(a,b));
        }
        return memo[l][r] = ret;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
