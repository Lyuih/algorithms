

# 942. 增减字符串匹配

## 题目描述
[LeetCode 942. 增减字符串匹配](https://leetcode.cn/problems/di-string-match/description/)

由范围 [0,n] 内所有整数组成的 n + 1 个整数的排列序列可以表示为长度为 n 的字符串 s ，其中:

如果 perm[i] < perm[i + 1] ，那么 s[i] == 'I' 
如果 perm[i] > perm[i + 1] ，那么 s[i] == 'D' 
给定一个字符串 s ，重构排列 perm 并返回它。如果有多个有效排列perm，则返回其中 任何一个 。
## 解题思路
- **核心算法**：贪心
- **思路**：
如果是I,就选当前排列中最小的数,下一个数肯定大于前一个数
相反就选当前排列中最大的数
## 代码实现 
```C++
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int l = 0,r = s.size();
        vector<int> ret;
        for(char c:s)
        {
            if(c == 'I')
            {
                ret.push_back(l++);
            }
            else
            {
                ret.push_back(r--);
            }
        }
        ret.push_back(l);
        return ret;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
