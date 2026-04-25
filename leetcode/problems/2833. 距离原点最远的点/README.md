# 2833. 距离原点最远的点

## 题目描述

[2833. 距离原点最远的点](https://leetcode.cn/problems/furthest-point-from-origin/description/)
给你一个长度为 n 的字符串 moves ，该字符串仅由字符 'L'、'R' 和 '\_' 组成。字符串表示你在一条原点为 0 的数轴上的若干次移动。

你的初始位置就在原点（0），第 i 次移动过程中，你可以根据对应字符选择移动方向：

如果 moves[i] = 'L' 或 moves[i] = '_' ，可以选择向左移动一个单位距离
如果 moves[i] = 'R' 或 moves[i] = '_' ，可以选择向右移动一个单位距离
移动 n 次之后，请你找出可以到达的距离原点 最远 的点，并返回 从原点到这一点的距离 。

## 解题思路

- **核心算法** 模拟
- **思路**：

## 代码实现

```python
class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        n = len(moves)
        L,R = 0,0
        for c in moves:
            if c == 'R':
                R+=1
            elif c=='L':
                L+=1
        return n-L-R + max(L,R) - min(L,R)
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
