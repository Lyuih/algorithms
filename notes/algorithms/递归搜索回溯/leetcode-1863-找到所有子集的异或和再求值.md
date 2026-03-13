# LeetCode 1863. 找出所有子集的异或总和再求和

## 题目描述
[LeetCode 1863. 找出所有子集的异或总和再求和](https://leetcode.cn/problems/sum-of-all-subset-xor-totals/description/)
一个数组的 异或总和 定义为数组中所有元素按位 XOR 的结果；如果数组为 空 ，则异或总和为 0 。

例如，数组 [2,5,6] 的 异或总和 为 2 XOR 5 XOR 6 = 1 。
给你一个数组 nums ，请你求出 nums 中每个 子集 的 异或总和 ，计算并返回这些值相加之 和 。

注意：在本题中，元素 相同 的不同子集应 多次 计数。

数组 a 是数组 b 的一个 子集 的前提条件是：从 b 删除几个（也可能不删除）元素能够得到 a 。

 
 
## 解题思路
- **核心算法**：回溯
- **思路**：
思路几乎与子集相同

- **复杂度分析**：
  - 时间复杂度：$O(n*2^n)$
  - 空间复杂度：$O(n*2^n)$

## 代码实现 (Python)
```C++
class Solution {
public:
int ret;
    void backtrack(vector<int>& nums,vector<int>&tmp, int pos)
    {
        if(pos >= nums.size())
        {
            int num = 0;
            for(int&x:tmp)
            {
                num = num^x;
            }
            ret+=num;
            return;
        }
        tmp.push_back(nums[pos]);
        backtrack(nums,tmp,pos+1);
        tmp.pop_back();
        backtrack(nums,tmp,pos+1);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<int> tmp;
        backtrack(nums,tmp,0);
        return ret;
    }
};
```


github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
