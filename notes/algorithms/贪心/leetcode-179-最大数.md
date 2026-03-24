# 179. 最大数

## 题目描述
[LeetCode 179. 最大数](https://leetcode.cn/problems/largest-number/description/)

给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。

注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。
## 解题思路
- **核心算法**：贪心
- **思路**：
让数字前位越大的数越要排前面，可以转化为排序问题，排序规则就是str(a)+str(b)>str(b)+str(a)
注意前缀零
## 代码实现 (Python)
```C++
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(),nums.end(),[](int a,int b){
            string s_a = to_string(a);
            string s_b = to_string(b);
            return s_a + s_b > s_b + s_a;
        });
        for(int num:nums)
        {
            res+=to_string(num);
        }
        if(res[0] == '0') return "0";
        return res;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
