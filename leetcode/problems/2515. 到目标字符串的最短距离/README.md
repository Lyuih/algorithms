# LeetCode 2515. 到目标字符串的最短距离

## 题目描述
[LeetCode 2515. 到目标字符串的最短距离](https://leetcode.cn/problems/shortest-distance-to-target-string-in-a-circular-array/description/?envType=daily-question&envId=2026-04-15)
给你一个下标从 0 开始的 环形 字符串数组 words 和一个字符串 target 。环形数组 意味着数组首尾相连。

形式上， words[i] 的下一个元素是 words[(i + 1) % n] ，而 words[i] 的前一个元素是 words[(i - 1 + n) % n] ，其中 n 是 words 的长度。
从 startIndex 开始，你一次可以用 1 步移动到下一个或者前一个单词。

返回到达目标字符串 target 所需的最短距离。如果 words 中不存在字符串 target ，返回 -1 。
## 解题思路
- **核心算法**：遍历
- **思路**：

## 代码实现
```python
class Solution:
    def closestTarget(self, words: List[str], target: str, startIndex: int) -> int:
        ret,cur = inf,startIndex
        for _ in range(len(words)):
            if words[cur] == target:
                ret = min(ret,abs(cur-startIndex),len(words)-abs(cur-startIndex))
            cur = (cur+1)%len(words)
        return -1 if ret == inf else ret
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)

