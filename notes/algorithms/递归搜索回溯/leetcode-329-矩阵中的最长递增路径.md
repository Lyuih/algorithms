# 329. 矩阵中的最长递增路径
## 题目描述
[LeetCode 329. 矩阵中的最长递增路径](https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/description/)

给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。

## 解题思路
- **核心算法**：回溯+记忆化
- **思路**：
对矩阵所有位置继续回溯求最长递增路径+记忆化剪枝

## 代码实现
```C++
class Solution {
public:
const int dis[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
vector<vector<int>> used;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const int n = matrix.size(),m = matrix[0].size();
        vector<vector<int>> memo(n,vector<int>(m,-1));   
        used.resize(n,vector<int>(m,0));
        int ret = 0;
        for(int i = 0;i<n;++i)
        {
            for(int j = 0;j < m;++j)
            {
                ret = max(ret,dfs(matrix,memo,i,j));
            }
        }     
        return ret;
    }
    int dfs(vector<vector<int>>& matrix,vector<vector<int>>&memo,int a,int b)
    {
        if(memo[a][b]!=-1) return memo[a][b];
        const int n = matrix.size(),m = matrix[0].size();
        used[a][b] = 1; 
        int ret = 1;
        for(int i = 0;i<4;++i)
        {
            int x = a+dis[i][0];
            int y = b+dis[i][1];
            if(x>=0&&x<n&&y>=0&&y<m&&used[x][y]==0&&matrix[x][y]>matrix[a][b])
            {
                ret = max(ret,1+dfs(matrix,memo,x,y));
            }
        }
        used[a][b] = 0; 
        return memo[a][b] = ret;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
