

# 931. 下降路径最小和

## 题目描述

[LeetCode 931. 下降路径最小和](https://leetcode.cn/problems/minimum-falling-path-sum/description/)

给你一个 n x n 的 方形 整数数组 matrix ，请你找出并返回通过 matrix 的下降路径 的 最小和 。

下降路径 可以从第一行中的任何元素开始，并从每一行中选择一个元素。在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。具体来说，位置 (row, col) 的下一个元素应当是 (row + 1, col - 1)、(row + 1, col) 或者 (row + 1, col + 1) 。



## 解题思路

- **核心算法**：动态规划
- **思路**：
多一行辅助数组,仅限第一行除第一个列元素全初始为为0,其他初始化为inf

## 代码实现

```C++
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        const int n = matrix.size(), m = matrix[0].size();
        vector dp(n + 2, vector<int>(m + 2,INT_MAX));
        for(int j = 1;j<=m;++j) dp[0][j] = 0;
        for(int i = 1;i<=n;++i)
        {
            for(int j = 1;j<=m;++j)
            {
                dp[i][j] = min(min(dp[i-1][j],dp[i-1][j-1]),dp[i-1][j+1])+matrix[i-1][j-1];
            }
        }
        int ret = *min_element(dp[n].begin(),dp[n].end());
        return ret;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
