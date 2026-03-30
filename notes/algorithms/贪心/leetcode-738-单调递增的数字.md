# 738. 单调递增的数字

## 题目描述

[LeetCode 738. 单调递增的数字](https://leetcode.cn/problems/monotone-increasing-digits/description/)

当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。

给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。

## 解题思路

- **核心算法**：贪心
- **思路**：
  往后找第一个不满足单调递增要求的数字,然后往前把与当前数字相同的第一个数字-1,第一个数字后面的数字全部变为9

## 代码实现

```C++
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int index = -1;
        for(int i = 0;i<s.size()-1;++i)
        {
            if(s[i]>s[i+1])
            {
                index = i;
                break;
            }
        }
        if(index == -1) return n;
        int i;
        for(i = index;i-1>=0&&s[i-1]==s[index];--i)
        {
            ;
        }
        s[i]  = s[i] - 1;
        for(i = i+1;i<s.size();++i) s[i] = '9';
        return stoi(s);

    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
