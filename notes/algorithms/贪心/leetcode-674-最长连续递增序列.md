
# 674. 最长连续递增序列


## 题目描述
[LeetCode 674. 最长连续递增序列](https://leetcode.cn/problems/longest-continuous-increasing-subsequence/description/)

给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。

连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。

 
## 解题思路
- **核心算法**：贪心
- **思路**：

直接找，断了重新来

## 代码实现 
```C++
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ret = 1;
        const int n = nums.size();
        int tmp = 1;
        for(int i = 0;i<n-1;++i)
        {
            if(nums[i+1]>nums[i])
            {
                tmp+=1;
            }
            else
            {
                ret = max(ret,tmp);
                tmp = 1;
            }
        }
        ret = max(ret,tmp);
        return ret;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
