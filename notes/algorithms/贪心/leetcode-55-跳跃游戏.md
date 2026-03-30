# 55. 跳跃游戏

## 题目描述
[LeetCode 55. 跳跃游戏](https://leetcode.cn/problems/jump-game/description/)

给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。


## 解题思路
- **核心算法**：贪心
- **思路**：
每次都到理论可以往后的最长位置
## 代码实现 
```C++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1)
            return true;
        for (int i = 0; i < n;) {
            int r = i + nums[i];
            if (r >= n - 1)
                return true;
            int index = r;
            for (int j = i + 1; j <= r; ++j) {
                if (j + nums[j] >= n - 1)
                    return true;
                if (j + nums[j] > index + nums[index]) {
                    index = j;
                }
            }
            i = index;
            if (i < n && nums[i] == 0) {
                return false;
            }
        }
        return false;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
