

# 918. 环形子数组的最大和

## 题目描述
[LeetCode 918. 环形子数组的最大和](https://leetcode.cn/problems/maximum-sum-circular-subarray/description/)
给定一个长度为 n 的环形整数数组 nums ，返回 nums 的非空 子数组 的最大可能和 。

环形数组 意味着数组的末端将会与开头相连呈环状。形式上， nums[i] 的下一个元素是 nums[(i + 1) % n] ， nums[i] 的前一个元素是 nums[(i - 1 + n) % n] 。

子数组 最多只能包含固定缓冲区 nums 中的每个元素一次。形式上，对于子数组 nums[i], nums[i + 1], ..., nums[j] ，不存在 i <= k1, k2 <= j 其中 k1 % n == k2 % n 。

 
## 解题思路
- **核心算法**：动态规划
- **思路**：
两种情况，全选，不全选
因为是环形，sum(nums) - 不选的子数组就为 选择的子数组
要让选择的子数组最大，不选的子数组就最小
特殊情况，数组全为负数，直接减的话最大子数组长度就为0了，不能不选的，所以如果数组和等于最小子数组和的话返回最大的子数组和即可


## 代码实现
```python
class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        n = len(nums)
        dp_max, dp_min = [0] * n, [0] * n
        dp_max[0] = dp_min[0] = nums[0]
        max_num = min_num = nums[0]
        for i in range(1, n):
            dp_max[i] = max(dp_max[i - 1] + nums[i], nums[i])
            dp_min[i] = min(dp_min[i - 1] + nums[i], nums[i])
            max_num = max(max_num, dp_max[i])
            min_num = min(min_num, dp_min[i])
        sum_num = sum(nums)
        return max_num if sum_num == min_num else max(max_num, sum_num - min_num)
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
