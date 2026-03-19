# LeetCode 3212. 统计 X 和 Y 频数相等的子矩阵数量

## 题目描述
[LeetCode 3212. 统计 X 和 Y 频数相等的子矩阵数量](https://leetcode.cn/problems/count-submatrices-with-equal-frequency-of-x-and-y/description/?envType=daily-question&envId=2026-03-19)
给你一个二维字符矩阵 grid，其中 grid[i][j] 可能是 'X'、'Y' 或 '.'，返回满足以下条件的子矩阵数量：

包含 grid[0][0]
'X' 和 'Y' 的频数相等。
至少包含一个 'X'。
## 解题思路
- **核心算法**：二维前缀和
二维数组前缀和，假设X是1，Y是-1，.是0。求出前缀和，但是要注意必须含有X，再利用一个二维数组存储当前是否包含了X。
最后遍历二维前缀和，判断当前子矩阵和是否等于0且包含X。
## 代码实现 (Python)
```c++
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        vector<vector<int>> suffix(n + 1, vector<int>(m + 1, 0)),
            vaild(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (grid[i-1][j-1] == '.') {
                    suffix[i][j] = suffix[i - 1][j] + suffix[i][j - 1] -
                                   suffix[i - 1][j - 1];
                    vaild[i][j] =
                        (vaild[i - 1][j] | vaild[i][j - 1] | vaild[i - 1][j - 1]);
                }
                 else {
                    suffix[i][j] = suffix[i - 1][j] + suffix[i][j - 1] -
                                   suffix[i - 1][j - 1] +
                                   ((grid[i - 1][j - 1] == 'X') ? 1 : -1);
                    vaild[i][j] = 1;
                }
                // cout<<suffix[i][j]<<' ';
            }
            // cout<<'\n';
        }
        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if(vaild[i][j] == 1 && suffix[i][j] == 0)
                {
                    ret += 1;
                }
            }
        }
        return ret;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)

