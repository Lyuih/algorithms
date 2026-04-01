
# 1054. 距离相等的条形码

## 题目描述

[LeetCode 1054. 距离相等的条形码](https://leetcode.cn/problems/distant-barcodes/description/)

在一个仓库里，有一排条形码，其中第 i 个条形码为 barcodes[i]。

请你重新排列这些条形码，使其中任意两个相邻的条形码不能相等。 你可以返回任何满足该要求的答案，此题保证存在答案。



## 解题思路

- **核心算法**：贪心
- **思路**：
 先排数量最大的数字,隔一个排一个

## 代码实现

```C++
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> cnt;
        const int n = barcodes.size();
        for(int num:barcodes)
        {
            cnt[num]+=1;
        }
        vector<array<int,2>> nums;
        for(auto&[a,b]:cnt)
        {
            nums.emplace_back( std::array<int,2>{a, b} );
        }
        sort(nums.begin(),nums.end(),[](const auto&a,const auto&b){
            return a[1]>b[1];
        });
        int begin = 0,i = 0;
        for(auto&arr:nums)
        {
            int count = arr[1];
            while(count)
            {
            while(i<n&&count)
            {
                barcodes[i] = arr[0];
                count-=1;
                i+=2;
            }
            if(i>=n)
            {
                i = 1;
            }
            }

        }
        return barcodes;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
