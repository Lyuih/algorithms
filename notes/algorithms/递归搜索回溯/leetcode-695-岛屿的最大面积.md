# LeetCode 695. 岛屿的最大面积

## 题目描述
[LeetCode 695. 岛屿的最大面积](https://leetcode.cn/problems/max-area-of-island/description/)

给你一个大小为 m x n 的二进制矩阵 grid 。

岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

岛屿的面积是岛上值为 1 的单元格的数目。

计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。

## 解题思路
- **核心算法**：深度优先
- **思路**：
找到每一个岛屿开始深度优先遍历

## 代码实现
```C++
class Solution {
public:
    const int dis[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(grid[i][j] == 1)
                {
                    grid[i][j] = 2;
                    int tmp = 1;
                    dfs(grid,i,j,tmp);
                    ret = max(ret,tmp);
                }
            }
        }
        return ret;
    }
    void dfs(vector<vector<int>>& grid,int a,int b,int& num)
    {
        const int n = grid.size(),m = grid[0].size();

        for(int i = 0; i<4;++i)
        {
            int x = a+dis[i][0];
            int y = b+dis[i][1];
            if(x>=0&&x<n&&y>=0&&y<m&&grid[x][y]==1)
            {
                grid[x][y] = 2;
                num+=1;
                dfs(grid,x,y,num);
            }
        }
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
