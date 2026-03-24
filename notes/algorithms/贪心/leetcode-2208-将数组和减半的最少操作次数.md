# 2208. 将数组和减半的最少操作次数

## 题目描述
[LeetCode 2208. 将数组和减半的最少操作次数](https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/description/)

给你一个正整数数组 nums 。每一次操作中，你可以从 nums 中选择 任意 一个数并将它减小到 恰好 一半。（注意，在后续操作中你可以对减半过的数继续执行操作）

请你返回将 nums 数组和 至少 减少一半的 最少 操作数。
## 解题思路
- **核心算法**：贪心
- **思路**：
利用优先队列每次都取最大的数减半，注意使用double来解决精度问题。

## 代码实现 (Python)
```C++
class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = accumulate(nums.begin(),nums.end(),0.0);
        priority_queue<double> q;
        for(int num: nums)
        {
            q.push(num);
        }
        int ret = 0;
        double tar = sum/2;
        while(tar<sum)
        {
            ret+=1;
            double num = q.top();
            tar+=num/2;
            q.pop();
            q.push(num/2);
        }
        return ret;

    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
