# LeetCode 3070. 元素和小于等于 k 的子矩阵的数目

## 题目描述
[LeetCode 3070. 元素和小于等于 k 的子矩阵的数目](https://leetcode.cn/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/description/?envType=daily-question&envId=2026-03-18)
给你一个下标从 0 开始的整数矩阵 grid 和一个整数 k。

返回包含 grid 左上角元素、元素和小于或等于 k 的 子矩阵的数目。
## 解题思路
- **核心算法**：二维前缀和
- **思路**：
    二维前缀和
- **复杂度分析**：
  - 时间复杂度：$O(n*m)$，只需遍历一次数组。
  - 空间复杂度：$O(n*m)$，前缀数组开销

## 代码实现
```c++
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        const int n = grid.size(), m = grid[0].size();
        vector<vector<int>> suffix(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                suffix[i][j] = suffix[i - 1][j] +
                               suffix[i][j - 1] - suffix[i - 1][j - 1] +
                               grid[i - 1][j - 1];
            }
        }
        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (suffix[i][j] <= k) {
                    ret += 1;
                }
            }
        }
        return ret;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)

