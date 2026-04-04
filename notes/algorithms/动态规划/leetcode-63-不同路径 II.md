
# 63. 不同路径 II

## 题目描述

[LeetCode 63. 不同路径 II](https://leetcode.cn/problems/unique-paths-ii/description/)

给定一个 m x n 的整数数组 grid。一个机器人初始位于 左上角（即 grid[0][0]）。机器人尝试移动到 右下角（即 grid[m - 1][n - 1]）。机器人每次只能向下或者向右移动一步。

网格中的障碍物和空位置分别用 1 和 0 来表示。机器人的移动路径中不能包含 任何 有障碍物的方格。

返回机器人能够到达右下角的不同路径数量。

测试用例保证答案小于等于 2 * 109。



## 解题思路

- **核心算法**：动态规划
- **思路**：
动态规划
## 代码实现

```C++
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int n = obstacleGrid.size(),m = obstacleGrid[0].size();
        vector dp(n,vector<int>(m));

        dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for(int i = 1;i<n;++i)
        {
            if(obstacleGrid[i][0] == 1) continue;
            dp[i][0] += dp[i-1][0];
        }
        for(int j = 1;j<m;++j)
        {
            if(obstacleGrid[0][j] == 1) continue;
            dp[0][j] += dp[0][j-1];
        }
        for(int i = 1;i<n;++i)
        {
            for(int j = 1;j<m;++j)
            {
                if(obstacleGrid[i][j] == 1) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
