# 62. 不同路径
## 题目描述
[LeetCode 62. 不同路径](https://leetcode.cn/problems/unique-paths/description/)

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？
## 解题思路
- **核心算法**：记忆化搜索
- **思路**：

记忆化搜索,注意结束条件，为0就返回0，都为1（起点）返回1

## 代码实现
```C++
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m+1,vector<int>(n+1,-1));
        return dfs(memo,m,n);
    }
    int dfs(vector<vector<int>>&memo,int a,int b)
    {
        if(a == 0 || b == 0)
        {
            return 0;
        }
        if(a == 1 && b == 1)
        {
            memo[a][b] = 1;
            return 1;
        }
        if(memo[a][b]!=-1) return memo[a][b];
        return memo[a][b] = dfs(memo,a-1,b) + dfs(memo,a,b-1);
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
