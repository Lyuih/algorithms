# LeetCode 2946. 循环移位后的矩阵相似检查

## 题目描述
[LeetCode 2946. 循环移位后的矩阵相似检查](https://leetcode.cn/problems/matrix-similarity-after-cyclic-shifts/description/?envType=daily-question&envId=2026-03-27)

给你一个下标从 0 开始且大小为 m x n 的整数矩阵 mat 和一个整数 k 。矩阵行的下标是从 0 开始的。

进行下面操作 k 次：

偶数行（0, 2, 4, ...）循环向左移动。


奇数行（1, 3, 5, ...）循环向右移动。


如果经过 k 步后的最终修改矩阵与原始矩阵相同，则返回 true，否则返回 false。

## 解题思路
- **核心算法** 数学 取模
- **思路**：
    k = k%m(m = 列数)
    k>m是没有没有意义的,因为还会循环回原地,直接取模得到有效k
    遍历数组,对数组的每个元素得到他的最终位置(利用一个临时数组存储)
    最后比较临时数组和原数组是否相同


## 代码实现
```c++
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        const int n = mat.size(),m = mat[0].size();
        k %= m;
        vector tmp(n,vector<int>(m));
        for(int i = 0;i<n;++i)
        {
            for(int j = 0;j<m;++j)
            {
                if(mat[i][j]%2!=0)
                {
                    tmp[i][(j+k)%m] = mat[i][j]; 
                }
                else
                {
                    tmp[i][(j-k+m)%m] = mat[i][j];
                }
            }
        }
        return tmp == mat;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)

