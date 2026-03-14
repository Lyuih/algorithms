# LeetCode 1415. 长度为 n 的开心字符串中字典序第 k 小的字符串


## 题目描述
[1415. 长度为 n 的开心字符串中字典序第 k 小的字符串](https://leetcode.cn/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/)

一个 「开心字符串」定义为：

仅包含小写字母 ['a', 'b', 'c'].
对所有在 1 到 s.length - 1 之间的 i ，满足 s[i] != s[i + 1] （字符串的下标从 1 开始）。
比方说，字符串 "abc"，"ac"，"b" 和 "abcbabcbcb" 都是开心字符串，但是 "aa"，"baa" 和 "ababbc" 都不是开心字符串。

给你两个整数 n 和 k ，你需要将长度为 n 的所有开心字符串按字典序排序。

请你返回排序后的第 k 个开心字符串，如果长度为 n 的开心字符串少于 k 个，那么请你返回 空字符串 。

 
 
## 解题思路
- **核心算法**：回溯
- **思路**：
利用回溯一步一步构建起开心字符串，把构造看作一个n层的决策过程

- **复杂度分析**：
  - 时间复杂度：$O(k*n)$
  - 空间复杂度：$O(n)$

## 代码实现 (Python)
```C++
class Solution {
public:
string ret;
string s;
void backtrack(string tmp,int n,int k,int& pos)
{
    if(!ret.empty())
    {
        return;
    }
    if(tmp.size() == n)
    {
        pos+=1;
        if(pos == k)
        {
            ret = tmp;
        }
        return;
    }

    for(char c : s)
    {
        if(tmp.empty() || tmp.back()!=c)
        {
            backtrack(tmp+c,n,k,pos);
        }
    }

}
    string getHappyString(int n, int k) {
        string tmp;
        ret = tmp = "";
        s = "abc";
        int pos = 0;
        backtrack(tmp,n,k,pos);
        return ret;
    }
};

//abab < abac < abca 
```


github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
