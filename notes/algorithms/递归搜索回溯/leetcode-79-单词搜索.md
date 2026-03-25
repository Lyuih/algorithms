# LeetCode 79.单词搜索

## 题目描述
[LeetCode 79.单词搜索](https://leetcode.cn/problems/word-search/description/)

给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

## 解题思路
- **核心算法**：回溯
- **思路**：
遍历二维数组所有单词入口，找到入口后开始回溯枚举所有可能（上下左右），只要程序走到单词结尾就是存在构成单词的单元格开始返回true，前面的递归函数接受到true就直接返回true，如果当前所有状态都枚举完成后还是没有结果就返回false

## 代码实现
```C++
class Solution {
public:
    int dis[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> used;

    bool exist(vector<vector<char>>& board, string word) {
        const int n = board.size(), m = board[0].size();
        used.resize(n,vector<int>(m,0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0]) {
                    used[i][j] = 1;
                    if (dfs(board, word, i, j) == true) {
                        return true;
                    }
                    used[i][j] = 0;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int a, int b,
             int pos = 1) {
        if (pos == word.size()) {
            return true;
        }
        const int n = board.size(), m = board[0].size();
        
        for (int i = 0; i < 4; ++i) {
            int x = a + dis[i][0];
            int y = b + dis[i][1];
            if (x >= 0 && x < n && y >= 0 && y < m &&
                board[x][y] == word[pos]&&used[x][y] == 0) {
                    used[x][y] = 1;
                if(dfs(board, word, x, y, pos + 1)) return true;
                    used[x][y] = 0;
            }
        }
        return false;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
