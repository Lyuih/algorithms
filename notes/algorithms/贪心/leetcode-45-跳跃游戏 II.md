# 45. 跳跃游戏 II

## 题目描述
[LeetCode 45. 跳跃游戏 II](https://leetcode.cn/problems/jump-game-ii/description/)

给定一个长度为 n 的 0 索引整数数组 nums。初始位置在下标 0。

每个元素 nums[i] 表示从索引 i 向后跳转的最大长度。换句话说，如果你在索引 i 处，你可以跳转到任意 (i + j) 处：

0 <= j <= nums[i] 且
i + j < n
返回到达 n - 1 的最小跳跃次数。测试用例保证可以到达 n - 1。
## 解题思路
- **核心算法**：贪心
- **思路**：
每次都到理论可以往后的最长位置
## 代码实现 
```C++
class Solution {
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();
        int ret = 0;
        for (int i = 0; i < n - 1;) {
            int m = i + nums[i];
            if (m >= n - 1) {
                ret += 1;
                break;
            }
            int next = m;
            int tmp = m;
            for (int j = i + 1; j <= m && j < n; ++j) {
                if (j + nums[j] > tmp) {
                    tmp = j + nums[j];
                    next = j;
                }
            }
            ret += 1;
            i = next;
        }
        return ret;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
