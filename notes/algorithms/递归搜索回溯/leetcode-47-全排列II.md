# LeetCode 47. 全排列II

## 题目描述
[LeetCode 47. 全排列II](https://leetcode.cn/problems/permutations-ii/)
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

 
 
## 解题思路
- **核心算法**：回溯
- **思路**：
  1. 确定递归终止条件为，当存储当前排序数组元素个数等于目标数组元素个数时，把当前排序数组插入到放回数组中
  2. 回溯过程中每次都遍历目标数组但是利用used数组记录当前记录过的位置，如果记录过就跳过，因为是回溯后面都要把状态恢复回去。
  3. 在全排列I的基础上加个去重操作在第2步中，在每个递归函数中创建一个set对象来管理是否存在重复的数字。

- **复杂度分析**：
  - 时间复杂度：$O(n*n!)$
  - 空间复杂度：$O(n)$

## 代码实现 (Python)
```C++
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> used;
    void backtrack(vector<int>& nums, vector<int>& tmp) {
        if (tmp.size() == nums.size()) {
            ret.push_back(tmp);
            return;
        }
        set<int> st;
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] == 0 && !st.count(nums[i])) {
                used[i] = 1;
                st.insert(nums[i]);
                tmp.push_back(nums[i]);
                backtrack(nums, tmp);
                tmp.pop_back();
                used[i] = 0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        used.resize(nums.size(), 0);
        vector<int> tmp;
        backtrack(nums, tmp);
        return ret;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
