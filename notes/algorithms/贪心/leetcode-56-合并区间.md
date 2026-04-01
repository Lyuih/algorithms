# 56. 合并区间

## 题目描述

[LeetCode 56. 合并区间](https://leetcode.cn/problems/merge-intervals/description/)

以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

## 解题思路

- **核心算法**：贪心
- **思路**：
  合并区间,先对区间按左区间排序
  排完序后贪心的寻找一个区间的右区间最远的
  当右区间与当前区间的左区间比较,如果小于左区间,那么就不需要合并,把前面的区间加入返回数组
  如果小于等于当前右区间,把右区间与当前区间的右区间进行比较,保存大的
  注意最后出循环最后一个区间没有加入

## 代码实现

```C++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](const auto&a,const auto&b){
            return a[0]<b[0];
        });
        vector<vector<int>> ret;
        int l = intervals[0][0],r = intervals[0][1];
        for(int i = 0;i<n;++i)
        {
            if(r<intervals[i][0])
            {
                ret.push_back({l,r});
                l = intervals[i][0];
                r = intervals[i][1];
            }
            else
            {
                r = max(r,intervals[i][1]);
            }
        }
        ret.push_back({l,r});
        return ret;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
