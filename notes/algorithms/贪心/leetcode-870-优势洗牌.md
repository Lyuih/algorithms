
# 870. 优势洗牌

## 题目描述
[LeetCode 870. 优势洗牌](https://leetcode.cn/problems/advantage-shuffle/description/)

给定两个长度相等的数组 nums1 和 nums2，nums1 相对于 nums2 的优势可以用满足 nums1[i] > nums2[i] 的索引 i 的数目来描述。

返回 nums1 的 任意 排列，使其相对于 nums2 的优势最大化。
## 解题思路
- **核心算法**：贪心
- **思路**：
本质田忌赛马,对两个数组排序后(第二个用下标数组替代排序)
如果num1当前最小的数字大于num2当前最小的数字,那就选择这个数字配对,相反就配对nums2当前最大的数字
## 代码实现 
```C++
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size();
        vector<int> index(n);
        for (int i = 0; i < n; ++i)
            index[i] = i;
        sort(nums1.begin(), nums1.end());
        sort(index.begin(), index.end(),
             [&](int a, int b) { return nums2[a] < nums2[b]; });
        vector<int> ret(n);
        int l = 0,r = n-1;
        for(int num:nums1)
        {
            if(num>nums2[index[l]])
            {
                ret[index[l++]] = num;
            }
            else
            {
                ret[index[r--]] = num;
            }
        }
        return ret;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
