# LeetCode 200. 岛屿数量

## 题目描述
[LeetCode 200. 岛屿数量](https://leetcode.cn/problems/number-of-islands/description/)

给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

## 解题思路
- **核心算法**：深度优先
- **思路**：
找到每一个岛屿开始深度优先遍历

## 代码实现 (Python)
```C++
class Solution {
public:
    const int dis[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int numIslands(vector<vector<char>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(grid[i][j] == '1')
                {
                    grid[i][j] = '2';
                    dfs(grid,i,j);
                    ret+=1;
                }
            }
        }
        return ret;
    }
    void dfs(vector<vector<char>>& grid,int a,int b)
    {
        const int n = grid.size(),m = grid[0].size();

        for(int i = 0; i<4;++i)
        {
            int x = a+dis[i][0];
            int y = b+dis[i][1];
            if(x>=0&&x<n&&y>=0&&y<m&&grid[x][y]=='1')
            {
                grid[x][y] = '2';
                dfs(grid,x,y);
            }
        }
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
