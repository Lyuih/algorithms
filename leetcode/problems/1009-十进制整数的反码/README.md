# LeetCode 1009. 十进制整数的反码

## 题目描述
[LeetCode 1. Two Sum](https://leetcode.cn/problems/two-sum/)
每个非负整数 N 都有其二进制表示。例如， 5 可以被表示为二进制 "101"，11 可以用二进制 "1011" 表示，依此类推。注意，除 N = 0 外，任何二进制表示中都不含前导零。
二进制的反码表示是将每个 1 改为 0 且每个 0 变为 1。例如，二进制数 "101" 的二进制反码为 "010"。
给你一个十进制数 N，请你返回其二进制表示的反码所对应的十进制整数。

 
## 解题思路
- **核心算法** 位运算
- **思路**：
  1. 创建一个掩码mask存储n所有有效位并置为
  2. 对n进行取反
  3. 将取反后的n和mask进行与运算得到结果
  4.注意特殊情况，当n=0时直接返回1.
- **复杂度分析**：
  - 时间复杂度：$O(1)$
  - 空间复杂度：$O(1)$

## 代码实现 (Python)
```C++
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int mask = 0;
        int tmp = n;
        for(int i = 0;tmp>1;++i)
        {
            mask = (mask | (1<<i));
            tmp>>=1;
        }
        return ((~n)&(mask));
    }
};
```
