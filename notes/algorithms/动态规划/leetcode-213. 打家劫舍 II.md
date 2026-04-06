

# 213. 打家劫舍 II

## 题目描述
[LeetCode 213. 打家劫舍 II](https://leetcode.cn/problems/house-robber-ii/description/)

你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
## 解题思路
- **核心算法**：动态规划
- **思路**：
因为变成了环形，偷了第一个就不能偷最后一个。
所以我们可以分情况讨论，偷了第一个那么它能到的范围就是n-2
不偷第一个它能到达的范围就n-1

## 代码实现
```C++
class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        vector<int> dp1(n), dp2(n);
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        dp2[1] = nums[1];
        for (int i = 2; i < n; ++i) {
            if (i < n - 1) {
                dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
            }
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
        }
        return max(dp1[n - 2], dp2[n - 1]);
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
