# LeetCode 1219.黄金矿工

## 题目描述
[LeetCode 1219.黄金矿工](https://leetcode.cn/problems/path-with-maximum-gold/description/)

你要开发一座金矿，地质勘测学家已经探明了这座金矿中的资源分布，并用大小为 m * n 的网格 grid 进行了标注。每个单元格中的整数就表示这一单元格中的黄金数量；如果该单元格是空的，那么就是 0。

为了使收益最大化，矿工需要按以下规则来开采黄金：

每当矿工进入一个单元，就会收集该单元格中的所有黄金。
矿工每次可以从当前位置向上下左右四个方向走。
每个单元格只能被开采（进入）一次。
不得开采（进入）黄金数目为 0 的单元格。
矿工可以从网格中 任意一个 有黄金的单元格出发或者是停止。

## 解题思路
- **核心算法**：回溯
- **思路**：
遍历二维数组所有单词入口，找到入口后开始回溯枚举所有可能（上下左右），通过临时变量记录从当前入口可以得到的最多黄金，ret在和tmp继续比较保存黄金数大的

## 代码实现
```C++
class Solution {
public:
    int dis[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> used;

    int ret;
    int getMaximumGold(vector<vector<int>>& board) {
        ret = 0;

        const int n = board.size(), m = board[0].size();
        used.resize(n, vector<int>(m, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] != 0) {
                    used[i][j] = 1;
                    int tmp = board[i][j];
                    dfs(board, i, j, tmp,board[i][j]);
                    ret = max(ret, tmp);
                    used[i][j] = 0;
                }
            }
        }
        return ret;
    }
    void dfs(vector<vector<int>>& board, int a, int b, int& tmp, int sum) {
        const int n = board.size(), m = board[0].size();

        for (int i = 0; i < 4; ++i) {
            int x = a + dis[i][0];
            int y = b + dis[i][1];
            if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] != 0 &&
                used[x][y] == 0) {
                tmp = std::max(tmp, sum + board[x][y]);

                used[x][y] = 1;
                dfs(board, x, y,tmp, sum + board[x][y]);
                used[x][y] = 0;
            }
        }
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
