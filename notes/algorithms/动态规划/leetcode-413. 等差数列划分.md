
# 413. 等差数列划分

## 题目描述
[LeetCode 413. 等差数列划分](https://leetcode.cn/problems/arithmetic-slices/description/)

如果一个数列 至少有三个元素 ，并且任意两个相邻元素之差相同，则称该数列为等差数列。

例如，[1,3,5,7,9]、[7,7,7,7] 和 [3,-1,-5,-9] 都是等差数列。
给你一个整数数组 nums ，返回数组 nums 中所有为等差数组的 子数组 个数。

子数组 是数组中的一个连续序列。

 
## 解题思路
- **核心算法**：动态规划
- **思路**：
利用等差数列的特性解决问题
dp[i] 表示以nums[i]结尾的等差数列个数
## 代码实现
```python
class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        if n<3: return 0
        dp = [0]*n
        ret = 0
        dp[0] = dp[1] = 0
        for i in range(2,n):
            if nums[i]+nums[i-2] == nums[i-1]*2:
                dp[i] = dp[i-1]+1 
            ret+=dp[i]
        return ret
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
