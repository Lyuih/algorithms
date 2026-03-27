
# 409. 最长回文串

## 题目描述
[LeetCode 409. 最长回文串](https://leetcode.cn/problems/longest-palindrome/description/)

给定一个包含大写字母和小写字母的字符串 s ，返回 通过这些字母构造成的 最长的 回文串 的长度。

在构造过程中，请注意 区分大小写 。比如 "Aa" 不能当做一个回文字符串。
## 解题思路
- **核心算法**：贪心
- **思路**：
对于相同字母数为偶数的全要,奇数的要奇数数减1,如果存在奇数最后加1
## 代码实现 
```C++
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> cnt;
        for(char c:s)
        {
            cnt[c]+=1;
        }
        int mx = 0;
        int ret = 0;
        int flag = 0;
        for(auto&[a,b]:cnt)
        {
            if(b%2==0)
            {
                ret+=b;
            }
            else
            {
                flag = 1;
                ret += b-1;
            }
        }
        return ret+flag;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
