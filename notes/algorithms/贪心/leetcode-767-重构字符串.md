

# 767. 重构字符串

## 题目描述

[LeetCode 767. 重构字符串](https://leetcode.cn/problems/reorganize-string/description/)

给定一个字符串 s ，检查是否能重新排布其中的字母，使得两相邻的字符不同。

返回 s 的任意可能的重新排列。若不可行，返回空字符串 "" 。


## 解题思路

- **核心算法**：贪心
- **思路**：
 先排数量最大的字符,隔一个排一个

## 代码实现

```C++
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char,int> cnt;
        int max_num = 0;
        for(char ch:s)
        {
            cnt[ch]++;
            max_num = max(max_num,cnt[ch]);
        }

        if(max_num>(n+1)/2)
            return "";
        priority_queue<pair<int,char>> q;
        for(auto&pr:cnt)
        {
            //cout<<pr.second<<" "<<pr.first<<endl;
            q.push({pr.second,pr.first});
        }
        //堆顶一定是频率最大的字符
        string ans = s;
        //ans.resize(n);
        //cout<<ans<<endl;
        int i = 0,j = 1;
        while(!q.empty())
        {
            //cout<<"s:"<<s<
            pair<int,char> tmp = q.top();
            int a = tmp.first;
            char b = tmp.second;
            //cout<<a<<" "<<b<<endl;
            q.pop();
            for(;i<n&&a;i+=2)
            {
                ans[i] = b;
                a--;
            }
            if(i>=n)
            {
                for(;j<n&&a;j+=2)
                {
                    ans[j] = b;
                    a--;
                }
            }
            
        }
        return ans;

    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
