# 2418. 按身高排序

## 题目描述
[LeetCode 2418. 按身高排序](https://leetcode.cn/problems/sort-the-people/description/)

给你一个字符串数组 names ，和一个由 互不相同 的正整数组成的数组 heights 。两个数组的长度均为 n 。

对于每个下标 i，names[i] 和 heights[i] 表示第 i 个人的名字和身高。

请按身高 降序 顺序返回对应的名字数组 names 。
## 解题思路
- **核心算法**：贪心
- **思路**：
替代排序,利用一个数组了存储下标,然后根据身高来排序,但是此时下标对应的仍然是原来的位置.

## 代码实现 
```C++
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        const int n = names.size();
        vector<int> index(n);
        for(int i = 0;i<n;++i) index[i] = i;
        sort(index.begin(),index.end(),[&](int a,int b){
            return heights[a]>heights[b];
        });
        vector<string> ret(n);
        for(int i = 0;i<n;++i)
        {
            ret[i] = names[index[i]];
        }
        return ret;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
