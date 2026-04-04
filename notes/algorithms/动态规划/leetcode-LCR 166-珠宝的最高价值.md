

# LCR 166. 珠宝的最高价值

## 题目描述

[LeetCode LCR 166. 珠宝的最高价值](https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/description/)

现有一个记作二维矩阵 frame 的珠宝架，其中 frame[i][j] 为该位置珠宝的价值。拿取珠宝的规则为：

只能从架子的左上角开始拿珠宝
每次可以移动到右侧或下侧的相邻位置
到达珠宝架子的右下角时，停止拿取
注意：珠宝的价值都是大于 0 的。除非这个架子上没有任何珠宝，比如 frame = [[0]]。





## 解题思路

- **核心算法**：动态规划
- **思路**：
动态规划
## 代码实现

```C++
class Solution {
public:
    int jewelleryValue(vector<vector<int>>& frame) {
        const int n = frame.size(), m = frame[0].size();
        vector dp(n+1, vector<int>(m+1));
        for(int i = 1;i<=n;++i)
        {
            for(int j = 1;j<=m;++j)
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1])+frame[i-1][j-1];
            }
        }
        return dp[n][m];
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
