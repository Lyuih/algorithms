# 509. 斐波那契数

## 题目描述
[LeetCode 509. 斐波那契数](https://leetcode.cn/problems/fibonacci-number/description/)

斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：

F(0) = 0，F(1) = 1
F(n) = F(n - 1) + F(n - 2)，其中 n > 1
给定 n ，请计算 F(n) 。
## 解题思路
- **核心算法**：记忆化搜索
- **思路**：

记忆化搜索

## 代码实现
```C++
class Solution {
public:
    int fib(int n) {
        vector<int> memo(n+1,-1);
        return dfs(memo,n);
    }
    int dfs(vector<int>&memo,int n)
    {
        if(n == 0 || n == 1) return n;
        if(memo[n]!=-1) return memo[n];
        return memo[n] = dfs(memo,n-1) + dfs(memo,n-2);
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
