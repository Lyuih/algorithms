
# 1005. K 次取反后最大化的数组和

## 题目描述
[LeetCode 1005. K 次取反后最大化的数组和](https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/description/)

给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：

选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
重复这个过程恰好 k 次。可以多次选择同一个下标 i 。

以这种方式修改数组后，返回数组 可能的最大和 。
## 解题思路
- **核心算法**：贪心
- **思路**：
利用优先队列,每次都处理当前最小的数

## 代码实现 
```C++
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        const int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> h;
        for (int num : nums)
            h.push(num);
        while(k) {
            int top = h.top();
            h.pop();

            if (top == 0)
                break;
            else if (top < 0) {
                top = -top;
                h.push(top);
            } else {
                if (k % 2 != 0) {
                    top = -top;
                    h.push(top);
                    break;
                }
                else
                {
                    h.push(top);
                    break;
                }
            }
            k-=1;
        }
        int sum = 0;
        while (!h.empty()) {
            sum += h.top();
            h.pop();
        }
        return sum;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
