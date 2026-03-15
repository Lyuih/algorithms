# LeetCode 77.组合
## 题目描述
[LeetCode 77.组合](https://leetcode.cn/problems/combinations/description/)

给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。
 
## 解题思路
- **核心算法**：回溯
- **思路**：
选与不选

## 代码实现 (Python)
```C++
class Solution {
public:
vector<vector<int>> ret;
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        zuhe(n,k,v);
        return ret;
    }
    void zuhe(int n,int k,vector<int>& v,int i = 1)
    {
        if(k == 0)
        {
            ret.push_back(v);
            return;
        }
        for(;i<=n-k+1;++i)
        {
            v.push_back(i);
            zuhe(n,k-1,v,i+1);
            v.pop_back();
        }
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
