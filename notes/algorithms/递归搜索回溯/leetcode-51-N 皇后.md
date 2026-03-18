# LeetCode 51.N皇后
## 题目描述
[LeetCode 51.N皇后](https://leetcode.cn/problems/n-queens/)

按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。

n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 
## 解题思路
- **核心算法**：回溯
- **思路**：
因为题目的要求也就以为着每行只会有一个皇后，我们可以以行为单位，枚举每行皇后的正确位置，每选定一个皇后前都要检测该位置是否违规。枚举所有可能。

## 代码实现 (Python)
```C++
class Solution {
public:
    vector<vector<string>> ret;
    vector<vector<int>> used;
    vector<vector<string>> solveNQueens(int n) {
        // used.resize(n,vector<int>(n,0));
        vector<string> vs(n, string(n, '.'));
        dfs(n, vs);
        return ret;
    }

    bool check(vector<string>& vs, int i, int j, int n) {
        for (int jj = 0; jj < n; ++jj) {
            if (vs[i][jj] == 'Q') {
                return false;
            }
        }
        for (int ii = 0; ii < n; ++ii) {
            if (vs[ii][j] == 'Q') {
                return false;
            }
        }
        for (int ii = i, jj = j; ii < n && jj < n; ++ii, ++jj) {
            if (vs[ii][jj] == 'Q') {
                return false;
            }
        }
        for (int ii = i, jj = j; ii >= 0 && jj >= 0; --ii, --jj) {
            if (vs[ii][jj] == 'Q') {
                return false;
            }
        }
        for (int ii = i, jj = j; ii < n && jj >= 0; ++ii, --jj) {
            if (vs[ii][jj] == 'Q') {
                return false;
            }
        }
        for (int ii = i, jj = j; ii >= 0 && jj < n; --ii, ++jj) {
            if (vs[ii][jj] == 'Q') {
                return false;
            }
        }

        return true;
    }
    void dfs(const int n, vector<string>& vs, int pos = 0) {
        if (pos == n) {
            ret.push_back(vs);
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (check(vs, pos, j, n)) {
                vs[pos][j] = 'Q';
                dfs(n, vs, pos + 1);
                vs[pos][j] = '.';
            }
        }
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
