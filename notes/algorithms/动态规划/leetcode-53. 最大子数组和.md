

# 53. 最大子数组和

## 题目描述
[LeetCode 53. 最大子数组和](https://leetcode.cn/problems/maximum-subarray/description/)
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组是数组中的一个连续部分。
## 解题思路
- **核心算法**：动态规划
- **思路**：
状态转移方程
dp[i] = max(dp[i-1]+nums[i],nums[i])
每次只维护当前最大的子数组和
## 代码实现
```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0]*n
        dp[0] = nums[0]
        ret = dp[0]
        for i in range(1,n):
            dp[i] = max(dp[i-1]+nums[i],nums[i])
            ret = max(ret,dp[i])
        return ret
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
