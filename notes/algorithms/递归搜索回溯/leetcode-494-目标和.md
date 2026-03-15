# LeetCode 494.目标和
## 题目描述
[LeetCode 494.目标和](https://leetcode.cn/problems/target-sum/description/)

给你一个非负整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
 
## 解题思路
- **核心算法**：回溯
- **思路**：
选与不选变体加或者减，注意减枝，当当前和加上当前后缀和小于目标值或者当前和剪去后缀和大于目标值，直接跳过。

## 代码实现 (Python)
```C++
class Solution {
public:
    vector<int> suffix_sum;
    int findTargetSumWays(vector<int>& nums, int target) {
        int ret = 0;
        suffix_sum.resize(nums.size()+1,0);
        for(int i = nums.size()-1;i>=0;--i)
        {
            suffix_sum[i] = suffix_sum[i+1]+nums[i];
        }
        dfs(nums,target,ret);
        return ret;
    }
    void dfs(vector<int>&nums,int target,int& ret,int sum = 0,int pos = 0)
    {
        if(pos == nums.size())
        {
            if(sum == target)
                ret+=1;
            return;
        }
        if(sum+suffix_sum[pos]<target || sum-(suffix_sum[pos])>target)
        {
            return;
        }
        
        dfs(nums,target,ret,sum+nums[pos],pos+1);
        dfs(nums,target,ret,sum-nums[pos],pos+1);
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
