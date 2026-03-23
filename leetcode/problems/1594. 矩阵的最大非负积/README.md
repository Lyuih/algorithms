# LeetCode 1594. 矩阵的最大非负积

## 题目描述
[LeetCode 1594. 矩阵的最大非负积](https://leetcode.cn/problems/maximum-non-negative-product-in-a-matrix/description/?envType=daily-question&envId=2026-03-23)
给你一个大小为 m x n 的矩阵 grid 。最初，你位于左上角 (0, 0) ，每一步，你可以在矩阵中 向右 或 向下 移动。

在从左上角 (0, 0) 开始到右下角 (m - 1, n - 1) 结束的所有路径中，找出具有 最大非负积 的路径。路径的积是沿路径访问的单元格中所有整数的乘积。

返回 最大非负积 对 109 + 7 取余 的结果。如果最大积为 负数 ，则返回 -1 。

注意，取余是在得到最大积之后执行的。
## 解题思路 
- **核心算法**：记忆化搜索
- **思路**：
想要得到最大积，只知道上一个位置的最大值是不够的还要知道上一个位置的最小值（如果当前位置为负数）。
为了得到终点位置的最大积，我们需要不断地搜索终点位置前一个位置地最大积和最小积，利用记忆化可以快速剪去重复分支

## 代码实现 (Python)
```c++
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        vector<vector<array<long long, 2>>> memo(
            n, vector<array<long long, 2>>(m, {LLONG_MIN, LLONG_MIN}));
        long long ret = dfs(grid, memo, n - 1, m - 1).at(1);
        return ret < 0 ? -1 : ret % 1'000'000'007;
    }
    array<long long, 2> dfs(vector<vector<int>>& grid,
                            vector<vector<array<long long, 2>>>& memo, int a,
                            int b) {
        long long x = grid[a][b];
        if (a == 0 && b == 0)
            return {x, x};
        if (memo[a][b][0] != LLONG_MIN)
            return memo[a][b];

        long long res_min = LLONG_MAX;
        long long res_max = LLONG_MIN;
        if (a > 0) {
            auto [mn, mx] = dfs(grid, memo, a - 1, b);
            res_min = min(mn * x, mx * x);
            res_max = max(mn * x, mx * x);
        }
        if (b > 0) {
            auto [mn, mx] = dfs(grid, memo, a, b - 1);
            res_min = min({mn * x, mx * x, res_min});
            res_max = max({mn * x, mx * x, res_max});
        }
        return memo[a][b] = {res_min, res_max};
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)

