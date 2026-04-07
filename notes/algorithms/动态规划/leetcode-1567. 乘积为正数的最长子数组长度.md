


# 1567. 乘积为正数的最长子数组长度

## 题目描述
[LeetCode 1567. 乘积为正数的最长子数组长度](https://leetcode.cn/problems/maximum-length-of-subarray-with-positive-product/description/)
给你一个整数数组 nums ，请你求出乘积为正数的最长子数组的长度。

一个数组的子数组是由原数组中零个或者更多个连续数字组成的数组。

请你返回乘积为正数的最长子数组长度。
## 解题思路
- **核心算法**：动态规划
- **思路**：
求的是正数的乘积最长子数组的长度，注意0的存在
还有定义两个数组，一个为最长乘积为负数的长度，一个为最长乘积为正数的长度
注意两个数组在当前元素为正负时候的转化

## 代码实现
```python
class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        n = len(nums)
        # 记录前面最小和最大数
        dp = [[0] * 2 for _ in range(n)]
        dp[0][0] = 1 if nums[0] < 0 else 0
        dp[0][1] = 1 if nums[0] > 0 else 0
        ret = dp[0][1]
        for i in range(1, n):
            if nums[i] > 0:
                dp[i][0] = (dp[i - 1][0]+1 if dp[i - 1][0] != 0 else 0)
                dp[i][1] = (dp[i - 1][1]+1 if dp[i - 1][1] != 0 else 1)
            elif nums[i] < 0:
                dp[i][0] = (dp[i - 1][1]+1 if dp[i - 1][1] != 0 else 1)
                dp[i][1] = (dp[i - 1][0]+1 if dp[i - 1][0] != 0 else 0)
            ret = max(ret, dp[i][1])
        return ret

```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
