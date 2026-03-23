# 417. 太平洋大西洋水流问题

## 题目描述
[LeetCode 417. 太平洋大西洋水流问题](https://leetcode.cn/problems/pacific-atlantic-water-flow/description/)

有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。

这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c) 上单元格 高于海平面的高度 。

岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。

返回网格坐标 result 的 2D 列表 ，其中 result[i] = [ri, ci] 表示雨水从单元格 (ri, ci) 流动 既可流向太平洋也可流向大西洋 。
## 解题思路
- **核心算法**：深度优先
- **思路**：

从表格的所有边缘开始深度优先遍历，因为需要找到可以同时流行太平洋和大西洋的位置，我们可以分两种状态继续深度遍历，同时用两个数组分别记录下每种状态可以到达的位置，当这两种数组在同一位置都有到达的记录那就表示这是要求的位置。注意剪枝：遍历过的位置不要在遍历了

## 代码实现 (Python)
```C++
class Solution {
public:
    enum class STATE { RIGHT, DOWN, LEFT, UP, FINISH };
    const int dis[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> ret;
    vector<vector<bool>> used, memo_1, memo_2;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int n = heights.size(), m = heights[0].size();
        used.resize(n, vector<bool>(m, false));
        memo_1.resize(n, vector<bool>(m, 0));
        memo_2.resize(n, vector<bool>(m, 0));
        // 遍历太平洋边界
        for (int j = 0; j < m; ++j)
            dfs(heights, 0, j, STATE::RIGHT); // 第一行
        for (int i = 1; i < n; ++i)
            dfs(heights, i, 0, STATE::UP); // 第一列（排除(0,0)）

        // 遍历大西洋边界
        for (int j = 0; j < m; ++j)
            dfs(heights, n - 1, j, STATE::LEFT); // 最后一行
        for (int i = 0; i < n - 1; ++i)
            dfs(heights, i, m - 1, STATE::DOWN); // 最后一列（排除(n-1, m-1)）
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (memo_1[i][j] == 1 && memo_2[i][j] == 1) {
                    ret.push_back({i, j});
                }
            }
        }
        return ret;
    }
    void dfs(vector<vector<int>>& heights, int a, int b, STATE state) {
        const int n = heights.size(), m = heights[0].size();
        if((state==STATE::RIGHT||state==STATE::UP)&&memo_1[a][b] ||
            (state==STATE::DOWN||state==STATE::LEFT)&&memo_2[a][b])
            {
                return;
            }
        if (state == STATE::RIGHT || state == STATE::UP)
            memo_1[a][b] = 1;
        if (state == STATE::DOWN || state == STATE::LEFT)
            memo_2[a][b] = 1;
        for (int i = 0; i < 4; ++i) {
            int x = a + dis[i][0];
            int y = b + dis[i][1];
            if (x >= 0 && x < n && y >= 0 && y < m &&
                heights[x][y] >= heights[a][b]) {
                dfs(heights, x, y, state);
            }
        }
        // used[a][b] = false;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
