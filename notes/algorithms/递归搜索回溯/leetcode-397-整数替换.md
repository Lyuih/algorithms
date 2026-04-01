# 397. 整数替换

## 题目描述

[LeetCode 397. 整数替换](https://leetcode.cn/problems/integer-replacement/description/)

给定一个正整数 n ，你可以做如下操作：

如果 n 是偶数，则用 n / 2替换 n 。
如果 n 是奇数，则可以用 n + 1或n - 1替换 n 。
返回 n 变为 1 所需的 最小替换次数 。

## 解题思路

- **核心算法** 记忆化搜索
- **思路**：
  当前n的最小替换数为,如果当前n为偶数n = dfs(n/2) 如果为奇数 n = min(dfs(n-1),dfs(n+1))
  用哈希表做记忆化

## 代码实现

```C++
class Solution {
public:
    unordered_map<long long, long long> cnt;

    int integerReplacement(int n) { return dfs(n); }
    long long dfs(long long n) {
        if (n == 1)
            return 0;
        if (cnt.count(n))
            return cnt[n];

        return (cnt[n] = (n % 2 == 0 ? dfs(n / 2) : min(dfs(n - 1),dfs(n + 1)))+1);
    }
};

// 7 6 3 2 1
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
