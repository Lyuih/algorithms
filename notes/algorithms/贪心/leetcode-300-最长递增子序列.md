# 300. 最长递增子序列

## 题目描述
[LeetCode 300. 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/description/)

给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
## 解题思路
- **核心算法**：贪心
- **思路**：
利用一个数组arr存储当前最长递增子序列，遍历原数组nums，利用二分查找当前元素在数组arr的情况，如果发现当前元素大于数组arr中的全部元素，把这个元素加入数组arr，如果存在大于等于当前元素的值，把大于等于当前元素的值替换为当前元素，最后数组arr元素的个数就是最长递增子序列的数目

数组 arr[i] 存储的是：所有长度为 i+1 的递增子序列中，末尾元素最小的那个值。
虽然 arr 最终存储的元素顺序可能与原数组不一致，但它维持的长度始终是正确的。
贪心点：通过二分替换，我们尽可能地让子序列的末尾元素变小，从而“潜力更大”，能接纳后续更多的元素。
本质：这种方法实际上是在维护一个“最有潜力的递增序列快照”，而不是在找具体的某个子序列。

## 代码实现 
```C++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        vector<int> arr;
        for(int num:nums)
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
        }
        return arr.size();
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
