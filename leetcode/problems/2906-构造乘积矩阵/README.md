# LeetCode 2906. 构造乘积矩阵

## 题目描述
[LeetCode 2906. 构造乘积矩阵](https://leetcode.cn/problems/construct-product-matrix/description/?envType=daily-question&envId=2026-03-24)
给你一个下标从 0 开始、大小为 n * m 的二维整数矩阵 grid ，定义一个下标从 0 开始、大小为 n * m 的的二维矩阵 p。如果满足以下条件，则称 p 为 grid 的 乘积矩阵 ：

对于每个元素 p[i][j] ，它的值等于除了 grid[i][j] 外所有元素的乘积。乘积对 12345 取余数。
返回 grid 的乘积矩阵。
## 解题思路
- **核心算法**：前缀积
- **思路**：
转化为一维前缀积，结果数组当前位置的结果位前一个位置的前缀积乘当前位置后一个位置的后缀积

## 代码实现 (Python)
```c++
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        const int len = n * m;
        const int mod = 12345;
        vector pre(len + 1, 1);
        vector<int> arr;
        arr.reserve(len);
        for (auto& v : grid) {
            for (int num : v) {
                arr.push_back(num);
            }
        }
        for (int i = 1; i <= len; ++i) {
            pre[i] = ((pre[i-1] % mod) * (arr[i - 1] % mod)) % mod;
        }
        vector ret(n, vector<int>(m));
        long long suf = 1LL;
        int cur = len;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                ret[i][j] = ((pre[cur - 1] % mod) * (suf % mod)) % mod;
                suf = ((suf % mod) * (grid[i][j] % mod)) % mod;
                cur-=1;
            }
        }
        return ret;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)

