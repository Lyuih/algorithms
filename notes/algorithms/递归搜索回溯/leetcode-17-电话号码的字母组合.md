# 17. 电话号码的字母组合

## 题目描述
[17. 电话号码的字母组合](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/)
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 
## 解题思路
- **核心算法**：回溯
- **思路**：
先利用一个数组记录下所有的按键对应的数字。
利用回溯的思想，对目录字符串进行遍历，(注意不要重复遍历)。再循环中再根据当前字符对应数字找到对应的数字串，遍历数字串。
递归的终止条件为临时存储字符串长度等于目标字符串长度。
- **复杂度分析**：
  - 时间复杂度：$O(3^m*4^n)$
  - 空间复杂度：$O(m+n)$

## 代码实现 (Python)
```C++
class Solution {
public:
vector<string> strs = {"",    "",    "abc",  "def", "ghi",
                           "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        dfs(digits,"");
        return ret;
    }
    void dfs(string& digits,string s,int i = 0)
    {
        if(s.size() == digits.size())
        {
            ret.push_back(move(s));
            return;
        }
        for(;i < digits.size();++i)
        {
            string tmp = strs[digits[i]-'0'];
            for(char c:tmp)
            {
                dfs(digits,s+c,i+1);
            }
        }
    }
    vector<string> ret;
};
```


github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
