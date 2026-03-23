# 300. 最长递增子序列

## 题目描述
[LeetCode 300. 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/description/)

给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
## 解题思路
- **核心算法**：动态规划
- **思路**：
想要知道数组大小为n的最长递增子序列就要知道数组大小为n-1的最长递增子序列长度，然后再遍历整个n-1大小的数组，找出其中比当前位置小的最长递增子序列。

## 代码实现 (Python)
```C++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        vector<int> dp(n);
        for(int i = 0; i < n;++i)
        {
            dp[i] = 1;
            for(int j = 0; j <i;++j)
            {
                if(nums[j] < nums[i])
                {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
    return *max_element(dp.begin(), dp.end());

    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
