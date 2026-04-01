# 452. 用最少数量的箭引爆气球

## 题目描述

[LeetCode 452. 用最少数量的箭引爆气球](https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/description/)

有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 points ，其中points[i] = [xstart, xend] 表示水平直径在 xstart 和 xend之间的气球。你不知道气球的确切 y 坐标。

一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足 xstart ≤ x ≤ xend，则该气球会被 引爆 。可以射出的弓箭的数量 没有限制 。 弓箭一旦被射出之后，可以无限地前进。

给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。

## 解题思路

- **核心算法**：贪心
- **思路**：
  先对区间按左区间排序
  把可能包裹其他区间的区间全删除
  一重叠就删除,右区间保存最短的右区间

  思路同 435. 无重叠区间
  最后返回n-ret,把未重叠的区间去了

## 代码实现

```C++
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        const int n = points.size();
        sort(points.begin(),points.end(),[](const auto&a,const auto&b){
            return a[0]<b[0];
        });
        int l = points[0][0],r = points[0][1];
        int ret = 0;
        for(int i = 1;i<n;++i)
        {
            if(r<points[i][0])
            {
                r = points[i][1];
            }
            else
            {
                ret+=1;
                r =  min(r,points[i][1]);
            }
        }
        return n - ret;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
