
# 334. 递增的三元子序列

## 题目描述
[LeetCode 334. 递增的三元子序列](https://leetcode.cn/problems/increasing-triplet-subsequence/description/)

给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。

如果存在这样的三元组下标 (i, j, k) 且满足 i < j < k ，使得 nums[i] < nums[j] < nums[k] ，返回 true ；否则，返回 false 。

 
## 解题思路
- **核心算法**：贪心
- **思路**：

类似最长递增子序列

## 代码实现 
```C++
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        const int n = nums.size();
        vector<int> arr;
        for(int num : nums)
        {
            auto it = lower_bound(arr.begin(),arr.end(),num);
            if(it == arr.end())
            {
                arr.push_back(num);
            }
            else
            {
                *it = num;
            }
            if(arr.size()>2) return true;
        }
        return false;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
