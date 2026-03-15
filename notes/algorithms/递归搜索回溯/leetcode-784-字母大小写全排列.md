
# LeetCode 784. 字母大小写全排列
## 题目描述
[LeetCode 784. 字母大小写全排列](https://leetcode.cn/problems/letter-case-permutation/description/)

给定一个字符串 s ，通过将字符串 s 中的每个字母转变大小写，我们可以获得一个新的字符串。

返回 所有可能得到的字符串集合 。以 任意顺序 返回输出。

 
 
## 解题思路
- **核心算法**：回溯
- **思路**：
选与不选变体，注意数字都不选

## 代码实现 (Python)
```C++
class Solution {
public:
    vector<string> ret;
    vector<string> letterCasePermutation(string s) {
        dfs(s);
        return ret;
    }
    void dfs(string s, int pos = 0, int i = 0) {
        if (pos == s.size()) {
            ret.push_back(s);
            return;
        }
        if (islower(s[i])) {
            s[i] = toupper(s[i]);
            dfs(s, pos + 1, i + 1);
            s[i] = tolower(s[i]);
            dfs(s, pos + 1, i + 1);

        } else if (isupper(s[i])) {
            s[i] = tolower(s[i]);
            dfs(s, pos + 1, i + 1);
            s[i] = toupper(s[i]);
            dfs(s, pos + 1, i + 1);

        } else {
            dfs(s, pos + 1, i + 1);
        }
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
