
# LeetCode 3653. 区间乘法查询后的异或 I

## 题目描述
[LeetCode 3653. 区间乘法查询后的异或 I](https://leetcode.cn/problems/xor-after-range-multiplication-queries-i/description/?envType=daily-question&envId=2026-04-08)
给你一个长度为 n 的整数数组 nums 和一个大小为 q 的二维整数数组 queries，其中 queries[i] = [li, ri, ki, vi]。

对于每个查询，按以下步骤执行操作：

设定 idx = li。
当 idx <= ri 时：
更新：nums[idx] = (nums[idx] * vi) % (109 + 7)
将 idx += ki。
在处理完所有查询后，返回数组 nums 中所有元素的 按位异或 结果。

 
## 解题思路
- **核心算法**：模拟


## 代码实现
```python
class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        mod = int(1e9+7)
        n = len(nums)
        m = len(queries)
        for querie in queries:
            l = querie[0]
            r = querie[1]
            k = querie[2]
            v = querie[3]
            for i in range(l,r+1,k):
                if i >= n :continue
                nums[i] = (nums[i]*v)%mod
        ret = 0
        for num in nums:
            ret = ret ^ num
        return ret
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)

