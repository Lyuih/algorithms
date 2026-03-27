# 455. 分发饼干

## 题目描述
[LeetCode 455. 分发饼干](https://leetcode.cn/problems/assign-cookies/description/)

假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。

对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是满足尽可能多的孩子，并输出这个最大数值。
## 解题思路
- **核心算法**：贪心
- **思路**：
对g和s进行排序
如果当前最小的饼干能满足当前味袋最小的人就分配给他,不能满足就继续用下一块饼干.直到饼干用完会在人分配完
## 代码实现 
```C++
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        const int n = g.size(),m = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cur_1 = 0,cur_2 = 0,ret= 0;
        for(;cur_2<m&&cur_1<n;)
        {
            if(s[cur_2]>=g[cur_1])
            {
                ret+=1;
                cur_2+=1;
                cur_1+=1;
            }
            else
            {
                cur_2+=1;
            }
        }
        return ret;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
