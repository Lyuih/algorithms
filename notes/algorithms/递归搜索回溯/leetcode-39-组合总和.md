# LeetCode 39.组合总和

## 题目描述
[LeetCode 39.组合总和](https://leetcode.cn/problems/combination-sum/description/)

给你一个非负整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
 
## 解题思路
- **核心算法**：回溯
- **思路**：
选与不选，注意可重复，把当前遍历到的位置传下去即可

## 代码实现 (Python)
```C++
class Solution {
public:
vector<vector<int>> ret;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        dfs(candidates,target,v,0);
        return ret;
    }
    void dfs(vector<int>&candidates,int target,vector<int>&v,int sum,int i = 0)
    {
        if(sum>target) return;
        if(sum == target)
        {
            ret.push_back(v);
            return;
        }
        for(;i<candidates.size();++i)
        {
            v.push_back(candidates[i]);
            dfs(candidates,target,v,sum+candidates[i],i);
            v.pop_back();
        }
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
