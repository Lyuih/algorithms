# 529. 扫雷游戏

## 题目描述
[LeetCode 529. 扫雷游戏](https://leetcode.cn/problems/minesweeper/description/)

让我们一起来玩扫雷游戏！

给你一个大小为 m x n 二维字符矩阵 board ，表示扫雷游戏的盘面，其中：

'M' 代表一个 未挖出的 地雷，
'E' 代表一个 未挖出的 空方块，
'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的 已挖出的 空白方块，
数字（'1' 到 '8'）表示有多少地雷与这块 已挖出的 方块相邻，
'X' 则表示一个 已挖出的 地雷。
给你一个整数数组 click ，其中 click = [clickr, clickc] 表示在所有 未挖出的 方块（'M' 或者 'E'）中的下一个点击位置（clickr 是行下标，clickc 是列下标）。

根据以下规则，返回相应位置被点击后对应的盘面：

如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X' 。
如果一个 没有相邻地雷 的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的 未挖出 方块都应该被递归地揭露。
如果一个 至少与一个地雷相邻 的空方块（'E'）被挖出，修改它为数字（'1' 到 '8' ），表示相邻地雷的数量。
如果在此次点击中，若无更多方块可被揭露，则返回盘面。
## 解题思路
- **核心算法**：深度优先
- **思路**：

区分每种位置，只有位'B'才需要展开，展开是周围8个格子

## 代码实现
```C++
class Solution {
public:
    vector<vector<char>> ret;
    vector<vector<int>> used;

    int dis[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dis2[8][2] = {{1, 0}, {-1, 0}, {0, 1},  {0, -1},
                      {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                     vector<int>& click) {
        const int n = board.size(), m = board[0].size();
        used.resize(n + 10, vector<int>(m + 10, 0));
        used[click[0]][click[1]] = 1;
        dfs(board, click[0], click[1]);
        return board;
    }
    void dfs(vector<vector<char>>& board, int a, int b) {
        if (board[a][b] == 'M') {
            board[a][b] = 'X';
            return;
        }
        const int n = board.size(), m = board[0].size();

        if (board[a][b] == 'E') {

            // 遍历周围是否有雷
            int mine = 0;
            for (int i = 0; i < 8; ++i) {
                int x = a + dis2[i][0];
                int y = b + dis2[i][1];
                if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 'M')
                    mine += 1;
            }
            if (mine != 0) {
                board[a][b] = mine + '0';
            } else {
                // 递归处理周围的空格
                board[a][b] = 'B';
                for (int i = 0; i < 8; ++i) {
                    int x = a + dis2[i][0];
                    int y = b + dis2[i][1];
                    if (x >= 0 && x < n && y >= 0 && y < m && used[x][y] == 0) {
                        used[x][y] = 1;
                        dfs(board, x, y);
                    }
                }
            }
        }
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
