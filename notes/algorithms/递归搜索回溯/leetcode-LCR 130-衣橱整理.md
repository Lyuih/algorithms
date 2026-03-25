# LCR 130. 衣橱整理

## 题目描述
[LeetCode LCR 130. 衣橱整理](https://leetcode.cn/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/description/)

家居整理师将待整理衣橱划分为 m x n 的二维矩阵 grid，其中 grid[i][j] 代表一个需要整理的格子。整理师自 grid[0][0] 开始 逐行逐列 地整理每个格子。

整理规则为：在整理过程中，可以选择 向右移动一格 或 向下移动一格，但不能移动到衣柜之外。同时，不需要整理 digit(i) + digit(j) > cnt 的格子，其中 digit(x) 表示数字 x 的各数位之和。

请返回整理师 总共需要整理多少个格子。
## 解题思路
- **核心算法**：深度优先
- **思路**：

深度优先

## 代码实现
```C++
class Solution {
public:
    vector<vector<int>> used;
    int dis[4][2] = {{1, 0}, {0, 1}};

    int wardrobeFinishing(int m, int n, int cnt) {
        used.resize(m + 10, vector<int>(n + 10, 0));
        int sum = 0;
        used[m][n] = 1;
        dfs(m,n,0,0,cnt,sum);
        return sum;
    }
    void dfs(int m,int n,int a,int b,int cnt,int& sum)
    {
        sum+=1;
        for(int i = 0;i<2;++i)
        {
            int x = a+dis[i][0];
            int y = b+dis[i][1];
            if(x>=0&&x<m&&y>=0&&y<n&&used[x][y]==0&&check(x,y,cnt))
            {
                used[x][y] = 1;
                dfs(m,n,x,y,cnt,sum);
            }
        }
    }
    bool check(int x,int y,int cnt)
    {
        int sum = 0;
        while(x)
        {
            sum += x%10;
            x/=10;
        }
        while(y)
        {
            sum += y%10;
            y/=10;
        }
        return sum <= cnt;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
