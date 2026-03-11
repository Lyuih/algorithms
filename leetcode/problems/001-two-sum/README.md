# LeetCode 1. 两数之和 (Two Sum)

## 题目描述
[LeetCode 1. Two Sum](https://leetcode.cn/problems/two-sum/)
给定一个整数数组 `nums` 和一个整数目标值 `target`，请你在该数组中找出 **和为目标值** `target` 的那 **两个** 整数，并返回它们的数组下标。

## 解题思路
- **核心算法**：哈希表 (Hash Map)
- **思路**：
  1. 遍历数组，对于每个元素 `nums[i]`。
  2. 计算需要的补数 `complement = target - nums[i]`。
  3. 检查哈希表中是否存在 `complement`：
     - 若存在，返回 `[map.get(complement), i]`。
     - 若不存在，将 `{nums[i]: i}` 存入哈希表。
- **复杂度分析**：
  - 时间复杂度：$O(n)$，只需遍历一次数组。
  - 空间复杂度：$O(n)$，最坏情况下哈希表存储 $n$ 个元素。

## 代码实现 (Python)
```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in hashmap:
                return [hashmap[complement], i]
            hashmap[num] = i
```
