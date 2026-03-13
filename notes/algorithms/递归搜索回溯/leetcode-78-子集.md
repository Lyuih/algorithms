# LeetCode 78. 子集

## 题目描述
[LeetCode 78. 子集](https://leetcode.cn/problems/subsets/description/)
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

 
 
## 解题思路
- **核心算法**：回溯
- **思路**：
利用回溯的思想可以很好解决子集问题，每次的递归调用函数本质都是一个子集（递归函数内部遍历时不要从头遍历），插入对象在当前函数的递归调用结束后恢复原状。

- **复杂度分析**：
  - 时间复杂度：$O(n*2^n)$
  - 空间复杂度：$O(n*2^n)$

## 代码实现 (Python)
```C++
class Solution {
public:
vector<vector<int>> ret;
    void backtrack(vector<int>& nums,vector<int>& tmp,int i = 0)
    {
        ret.push_back(tmp);
        for(; i<nums.size();++i)
        {
            tmp.push_back(nums[i]);
            backtrack(nums,tmp,i+1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // ret.push_back({});
        vector<int> tmp;
        backtrack(nums,tmp);
        return ret;
    }
};
```


## 解题思路
- **核心算法**：回溯
- **思路**：
利用回溯思想，把目标数组元素变成选与不选问题，递归结束条件为递归层数到达目标数组长度。
- **复杂度分析**：
  - 时间复杂度：$O(n*2^n)$
  - 空间复杂度：$O(n*2^n)$

## 代码实现 (Python)
```C++
class Solution {
    vector<vector<int>> ret;
    vector<int> path;

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ret;
    }
    void dfs(vector<int>& nums, int pos) {
        if (pos == nums.size()) {
            ret.push_back(path);
            return;
        }
        // 选
        path.push_back(nums[pos]);
        dfs(nums, pos + 1);
        path.pop_back(); // 恢复现场
        // 不选
        dfs(nums, pos + 1);
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)


