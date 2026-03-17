
# LeetCode 526. 优美的排列
## 题目描述
[LeetCode 526. 优美的排列](https://leetcode.cn/problems/beautiful-arrangement/description/)

假设有从 1 到 n 的 n 个整数。用这些整数构造一个数组 perm（下标从 1 开始），只要满足下述条件 之一 ，该数组就是一个 优美的排列 ：

perm[i] 能够被 i 整除
i 能够被 perm[i] 整除
给你一个整数 n ，返回可以构造的 优美排列 的 数量 。
 
 
## 解题思路
- **核心算法**：回溯
- **思路**：
枚举数组每个位置选什么

## 代码实现 (Python)
```C++
class Solution {
public:
    vector<int> used;
    int countArrangement(int n) {
        int ret = 0;
        used.resize(n + 1, 0);
        dfs(n, ret);
        return ret;
    }
    void dfs(int n, int& ret, int pos = 1) {
        if (n + 1 == pos) {
            ret += 1;
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if (used[i] == 0 && (i % pos == 0 || pos % i == 0)) {
                used[i] = 1;
                dfs(n, ret, pos + 1);
                used[i] = 0;
            }
        }
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
