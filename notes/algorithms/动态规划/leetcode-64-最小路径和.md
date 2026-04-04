# 64. 最小路径和

## 题目描述

[LeetCode 664. 最小路径和](https://leetcode.cn/problems/minimum-path-sum/description/)

给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

## 解题思路

- **核心算法**：动态规划
- **思路**：
  动态规划

## 代码实现

```C++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        vector dp(n + 1, vector<int>(m + 1,INT_MAX));
        dp[0][1] = dp[1][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1];
            }
        }
        return dp[n][m];
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
