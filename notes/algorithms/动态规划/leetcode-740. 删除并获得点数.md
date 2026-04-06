
# 740. 删除并获得点数

## 题目描述
[LeetCode 740. 删除并获得点数](https://leetcode.cn/problems/delete-and-earn/description/)

给你一个整数数组 nums ，你可以对它进行一些操作。

每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除 所有 等于 nums[i] - 1 和 nums[i] + 1 的元素。

开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。

 
## 解题思路
- **核心算法**：动态规划
- **思路**：
先哈希再打家劫舍

## 代码实现
```python
class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        cnt = [0]*10001
        for num in nums:
            cnt[num]+=num
        dp = [0]*10001
        dp[0] = cnt[0]
        dp[1] = max(cnt[0],cnt[1])
        for i in range(2,len(cnt)):
            dp[i] = max(dp[i-1],dp[i-2]+cnt[i])
        return dp[10000]
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
