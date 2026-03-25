# 376. 摆动序列

## 题目描述
[LeetCode 376. 摆动序列](https://leetcode.cn/problems/wiggle-subsequence/description/)

如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列 。第一个差（如果存在的话）可能是正数或负数。仅有一个元素或者含两个不等元素的序列也视作摆动序列。

例如， [1, 7, 4, 9, 2, 5] 是一个 摆动序列 ，因为差值 (6, -3, 5, -7, 3) 是正负交替出现的。

相反，[1, 4, 7, 2, 5] 和 [1, 7, 4, 5, 5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。
子序列 可以通过从原始序列中删除一些（也可以不删除）元素来获得，剩下的元素保持其原始顺序。

给你一个整数数组 nums ，返回 nums 中作为 摆动序列 的 最长子序列的长度 。
## 解题思路
- **核心算法**：贪心
- **思路**：

以三个元素组成的子序列为例，其形状决定了摆动序列的贡献：

水平型 (1, 1, 1)：无波动，贡献长度为 1。
单调型 (1, 2, 3 或 3, 2, 1)：仅有一个波动方向，贡献长度为 2。
峰谷型 (1, 2, 1 或 2, 1, 2)：存在一次完整的方向转折（U型或倒U型），贡献长度为 3。

贪心策略：
要使子序列最长，本质上是统计原序列中**极值点（波峰和波谷）**的数量。我们只在大趋势发生转折时（即 left 差异与 right 差异异号时）才计入结果，从而忽略单调上升或下降过程中的中间点、以及平坦的重复点。

## 代码实现 
```C++
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        const int n = nums.size();
        if(n<2) return n;
        int ret = 0,left = 0;
        for(int i = 0;i<n-1;++i)
        {
            int right = nums[i+1]-nums[i];
            if(right == 0) continue;
            if(right*left<=0) ret+=1;
            left = right;
        }
        return ret+1;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
