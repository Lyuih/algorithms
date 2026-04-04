# LeetCode 2087. 网格图中机器人回家的最小代价

## 题目描述

[LeetCode 2087. 网格图中机器人回家的最小代价](https://leetcode.cn/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/description/?envType=daily-question&envId=2026-04-04)
给你一个 m x n 的网格图，其中 (0, 0) 是最左上角的格子，(m - 1, n - 1) 是最右下角的格子。给你一个整数数组 startPos ，startPos = [startrow, startcol] 表示 初始 有一个 机器人 在格子 (startrow, startcol) 处。同时给你一个整数数组 homePos ，homePos = [homerow, homecol] 表示机器人的 家 在格子 (homerow, homecol) 处。

机器人需要回家。每一步它可以往四个方向移动：上，下，左，右，同时机器人不能移出边界。每一步移动都有一定代价。再给你两个下标从 0 开始的额整数数组：长度为 m 的数组 rowCosts 和长度为 n 的数组 colCosts 。

如果机器人往 上 或者往 下 移动到第 r 行 的格子，那么代价为 rowCosts[r] 。
如果机器人往 左 或者往 右 移动到第 c 列 的格子，那么代价为 colCosts[c] 。
请你返回机器人回家需要的 最小总代价 。

## 解题思路

- **核心算法**贪心
- **思路**：
  直接走,走最接近终点的路线

## 代码实现

```c++
class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        const int n = rowCosts.size(),m = colCosts.size();
        int ret = 0;
        int x = startPos[0],y = startPos[1];
        int x_e = homePos[0],y_e = homePos[1];
        while(x!=x_e)
        {
            if(x<x_e)
            {
                ret+=rowCosts[++x];
            }
            else
            {
                ret+=rowCosts[--x];
            }
        }
        while(y!=y_e)
        {
            if(y<y_e)
            {
                ret+=colCosts[++y];
            }
            else
            {
                ret+=colCosts[--y];
            }
        }
        return ret;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
