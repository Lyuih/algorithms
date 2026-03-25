# LeetCode 3546. 等和矩阵分割 I

## 题目描述
[LeetCode 3546. 等和矩阵分割 I](https://leetcode.cn/problems/equal-sum-grid-partition-i/description/?envType=daily-question&envId=2026-03-25)
给你一个二维字符矩阵 grid，其中 grid[i][j] 可能是 'X'、'Y' 或 '.'，返回满足以下条件的子矩阵数量：

包含 grid[0][0]
'X' 和 'Y' 的频数相等。
至少包含一个 'X'。
## 解题思路
- **核心算法**：前缀和
前缀和
## 代码实现
```c++
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        const int n = grid.size(),m = grid[0].size();
        long long sum = accumulate(grid.begin(),grid.end(),0LL,[](long long total,const vector<int>&v){
            return total + accumulate(v.begin(),v.end(),0LL);
        });
        long long prev = 0LL;
        for(auto&v:grid)
        {
            for(int num:v)
            {
                prev+=num;
            }
            if(prev*2 == sum)
            {
                return true;
            }
        }
        prev = 0LL;
        for(int j = 0;j<m;++j)
        {
            for(int i = 0;i<n;++i)
            {
                prev+=grid[i][j];
            }
            if(prev*2 == sum) return true;
        }
        return false;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)

