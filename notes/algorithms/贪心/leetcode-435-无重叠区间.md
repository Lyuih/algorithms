# 435. 无重叠区间

## 题目描述

[LeetCode 435. 无重叠区间](https://leetcode.cn/problems/non-overlapping-intervals/description/)

给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回 需要移除区间的最小数量，使剩余区间互不重叠 。

注意 只在一点上接触的区间是 不重叠的。例如 [1, 2] 和 [2, 3] 是不重叠的。
## 解题思路

- **核心算法**：贪心
- **思路**：
  先对区间按左区间排序
  把可能包裹其他区间的区间全删除
  一重叠就删除,右区间保存最短的右区间

## 代码实现

```C++
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](const auto&a,const auto&b){
            return a[0]<b[0];
        });
        int ret = 0;
        int l = intervals[0][0],r = intervals[0][1];
        for(int i = 0;i<n;++i)
        {
            if(r<=intervals[i][0])
            {
                r = intervals[i][1];
            }
            else
            {
                ret+=1;
                r = min(r,intervals[i][1]);
            }
        }
        return ret-1;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
