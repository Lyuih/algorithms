

# 978. 最长湍流子数组

## 题目描述
[LeetCode 978. 最长湍流子数组](https://leetcode.cn/problems/longest-turbulent-subarray/description/)

给定一个整数数组 arr ，返回 arr 的 最大湍流子数组的长度 。

如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是 湍流子数组 。

更正式地来说，当 arr 的子数组 A[i], A[i+1], ..., A[j] 满足仅满足下列条件时，我们称其为湍流子数组：

若 i <= k < j ：
当 k 为奇数时， A[k] > A[k+1]，且
当 k 为偶数时，A[k] < A[k+1]；
或 若 i <= k < j ：
当 k 为偶数时，A[k] > A[k+1] ，且
当 k 为奇数时， A[k] < A[k+1]。

 
## 解题思路
- **核心算法**：动态规划
- **思路**：
一种情况为   < >
另一种情况为 > <
可以使用dp解决，两种状态，一种状态可以由另一种状态得到

## 代码实现
```python
class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        n = len(arr)
        dp = [[1] * 2 for _ in range(n)]
        ret = 1
        for i in range(1, n):
            if arr[i] > arr[i-1]:
                dp[i][0] = dp[i-1][1]+1
            elif arr[i] < arr[i-1]:
                dp[i][1] = dp[i-1][0]+1
            ret = max(ret,dp[i][0],dp[i][1])
        return ret

```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
