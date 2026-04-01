# 1262. 可被三整除的最大和

## 题目描述

[LeetCode 1262. 可被三整除的最大和](https://leetcode.cn/problems/greatest-sum-divisible-by-three/description/)

给你一个整数数组 nums，请你找出并返回能被三整除的元素 最大和。

## 解题思路

- **核心算法**：贪心
- **思路**：
  先计算所有元素的和,如果sum%3==0直接返回
  如果sum%2==1 那么sum减去一个取模为1的数字,或者减去两个取模2的数字
  如果sum%2==2 那么sum减去一个取模为2的数字,或者减去两个取模1的数字

## 代码实现

```C++
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        const int n = nums.size();
        const int inf = 0x3f3f3f3f;
        // int a1 = inf,a2 = inf,b1 = inf,b2 = inf;
        vector<int> a,b;
        for(int i = 0;i<n;++i)
        {
            sum+=nums[i];
            if(nums[i]%3==1)
            {
                a.push_back(nums[i]);
            }
            else if(nums[i]%3==2)
            {
                b.push_back(nums[i]);
            }
        }
        while(a.size()<2) a.push_back(inf);
        while(b.size()<2) b.push_back(inf);
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(sum%3==0) return sum;
        else if(sum%3==1) return max(sum-a[0],sum-b[0]-b[1]);
        else return max(sum-a[0]-a[1],sum-b[0]);
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
