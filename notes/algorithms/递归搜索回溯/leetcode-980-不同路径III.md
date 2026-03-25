# LeetCode 980. 不同路径 III

## 题目描述
[LeetCode 980. 不同路径 III](https://leetcode.cn/problems/unique-paths-iii/description/)

在二维网格 grid 上，有 4 种类型的方格：

1 表示起始方格。且只有一个起始方格。
2 表示结束方格，且只有一个结束方格。
0 表示我们可以走过的空方格。
-1 表示我们无法跨越的障碍。
返回在四个方向（上、下、左、右）上行走时，从起始方格到结束方格的不同路径的数目。

每一个无障碍方格都要通过一次，但是一条路径中不能重复通过同一个方格。

## 解题思路
- **核心算法**：回溯
- **思路**：
遍历数组找到入口并记录数组0的数量
开始回溯遍历，结束条件为走到数字2处，但要注意是否走过了所有数字0的位置。

## 代码实现
```C++
class Solution {
public:
const int dis[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
vector<vector<int>> used;
int ret = 0;
    int uniquePathsIII(vector<vector<int>>& grid) {
        const int n = grid.size(),m = grid[0].size();
        used.resize(n,vector<int>(m,0));
        int zero = 0;
        int x,y;
        for(int i = 0; i <n;++i)
        {
            for(int j = 0;j<m;++j)
            {
                if(grid[i][j] == 1)
                {
                    x = i;
                    y = j;
                }
                else if(grid[i][j] == 0)
                {
                    zero+=1;
                }
            }
        }
        used[x][y] = 1;
        dfs(grid,x,y,zero);
        return ret;
    }
    void dfs(vector<vector<int>>& grid,int a,int b,int zero)
    {
        if(grid[a][b] == 2)
        {
            // cout<<zero<<endl;
            if(zero == -1)
                ret+=1;
            return;
        }
        const int n = grid.size(),m = grid[0].size();

        for(int i = 0; i<4;++i)
        {
            int x = a+dis[i][0];
            int y = b+dis[i][1];
            if(x>=0&&x<n&&y>=0&&y<m&&used[x][y]==0&&grid[x][y]!=-1)
            {
                used[x][y] = 1;
                dfs(grid,x,y,zero-1);
                used[x][y] = 0;
            }
        }
    }

};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
