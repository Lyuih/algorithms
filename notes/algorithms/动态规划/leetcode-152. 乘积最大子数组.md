# 152. 乘积最大子数组

## 题目描述
[LeetCode 152. 乘积最大子数组](https://leetcode.cn/problems/maximum-product-subarray/description/)
给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续 子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

测试用例的答案是一个 32-位 整数。

请注意，一个只包含一个元素的数组的乘积是这个元素的值。
 
## 解题思路
- **核心算法**：动态规划
- **思路**：
因为乘的特性，负负得正
要想知道当前最大乘积子数组，就要利用当前值去乘前面的最大值和最小值，这样才能得到最后的最大值

## 代码实现
```python
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        # 记录前面最小和最大数
        dp = [[0]*2 for _ in range(n)]
        dp[0][0] = nums[0]
        dp[0][1] = nums[0]
        ret = nums[0]
        for i in range(1,n):
            if nums[i]>=0:
                dp[i][0] = min(dp[i-1][0]*nums[i],nums[i])
                dp[i][1] = max(dp[i-1][1]*nums[i],nums[i])
            elif nums[i]<0:
                dp[i][0] = min(dp[i-1][1]*nums[i],nums[i])
                dp[i][1] = max(dp[i-1][0]*nums[i],nums[i])
            # else:
            #     dp[i][0] = dp[i][1] = 0
            ret = max(ret,dp[i][0],dp[i][1])
        return ret
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
