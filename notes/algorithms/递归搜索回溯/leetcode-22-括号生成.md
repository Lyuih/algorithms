# LeetCode 22.括号生成

## 题目描述
[LeetCode 22.括号生成](https://leetcode.cn/problems/generate-parentheses/description/)

数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 
## 解题思路
- **核心算法**：回溯
- **思路**：
本质是判断一个空位是该选择'(' 还是 ')'呢。
可以转化为选或不选的问题，但是要注意的是如果要构成有效的括号，在选择‘)’前就一定要选择‘(’,以及要注意‘(’的使用。
然后就可以知道回溯的逻辑了，当没有选择‘(’前一定要选择‘(’，反之既可以选择‘(’也可以选择‘)’但是要注意‘(’的个数。
回溯的终止条件是耗尽左括号。


## 代码实现 (Python)
```C++
class Solution {
public:
vector<string> ret;
    vector<string> generateParenthesis(int n) {
        backtrack(n,"",n);
        return ret;
    }
    void backtrack(int n,string s,int count,int flag = 0,int pos = 0)
    {
        if(n*2 == pos)
        {
            ret.push_back(move(s));
            return;
        }
        if(flag==0)
        {
            if(count>0)
                backtrack(n,s+"(",count-1,flag+1,pos+1);
        }
        else
        {
            if(count>0)
                backtrack(n,s+"(",count-1,flag+1,pos+1);
            backtrack(n,s+")",count,flag-1,pos+1);
        }
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
