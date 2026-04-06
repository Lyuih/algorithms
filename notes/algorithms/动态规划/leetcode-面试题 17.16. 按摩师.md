
# 面试题 17.16. 按摩师

## 题目描述
[LeetCode 面试题 17.16. 按摩师](https://leetcode.cn/problems/the-masseuse-lcci/description/)

一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。

注意：本题相对原题稍作改动
## 解题思路
- **核心算法**：动态规划
- **思路**：
打家劫舍

## 代码实现
```C++
class Solution {
public:
    int massage(vector<int>& nums) {
        const int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2;i<n;++i)
        {
            dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[n-1];
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
