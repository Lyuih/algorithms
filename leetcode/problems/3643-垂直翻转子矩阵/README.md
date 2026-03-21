# LeetCode 3643. 垂直翻转子矩阵

## 题目描述
[LeetCode 3643. 垂直翻转子矩阵](https://leetcode.cn/problems/flip-square-submatrix-vertically/description/?envType=daily-question&envId=2026-03-21)
给你一个 m x n 的整数矩阵 grid，以及三个整数 x、y 和 k。

整数 x 和 y 表示一个 正方形子矩阵 的左上角下标，整数 k 表示该正方形子矩阵的边长。

你的任务是垂直翻转子矩阵的行顺序。

返回更新后的矩阵。
## 解题思路
- **核心算法**：遍历

遍历交换

## 代码实现 (Python)
```c++
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i = x,ii = x+k-1;i<ii;++i,--ii)
        {
            for(int j = y;j<y+k;++j)
            {
                std::swap(grid[i][j],grid[ii][j]);
            }
        }
        return grid;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)

