# 991. 坏了的计算器

## 题目描述

[LeetCode 991. 坏了的计算器](https://leetcode.cn/problems/broken-calculator/description/)

在显示着数字 startValue 的坏计算器上，我们可以执行以下两种操作：

双倍（Double）：将显示屏上的数字乘 2；
递减（Decrement）：将显示屏上的数字减 1 。
给定两个整数 startValue 和 target 。返回显示数字 target 所需的最小操作数。

## 解题思路

- **核心算法**：贪心
- **思路**：
  正难则反
  逆向思维
  当tar小于start时,tar+=1
  当大于时 如果tar为奇数 tar+=1,偶数 tar/=2 目的是为了更接近start

## 代码实现

```C++
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ret;
        for(;;)
        {
            if(target<startValue)
            {
                target+=1;
            }
            else if(target>startValue)
            {
                if(target%2==1) target+=1;
                else target/=2;
            }
            else
            {
                return ret;
            }
            ret+=1;
        }
        return -1;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
