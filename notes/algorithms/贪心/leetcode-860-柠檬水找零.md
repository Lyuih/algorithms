# 860. 柠檬水找零

## 题目描述
[LeetCode 860. 柠檬水找零](https://leetcode.cn/problems/lemonade-change/description/)

在柠檬水摊上，每一杯柠檬水的售价为 5 美元。顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。

每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。

注意，一开始你手头没有任何零钱。

给你一个整数数组 bills ，其中 bills[i] 是第 i 位顾客付的账。如果你能给每位顾客正确找零，返回 true ，否则返回 false 。
## 解题思路
- **核心算法**：贪心
- **思路**：
如果客人付5元，无需找零
如果客人付10元，需要找零
如果客人付20元，需要找零，而优先找零10元，因为10元只能在客人付20元时才有效果

## 代码实现 (Python)
```C++
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0,ten = 0;
        for(int num :bills)
        {
            if(num == 5) five+=1;
            else if(num == 10)
            {
                if(five<1) return false;
                five-=1;
                ten+=1;
            }
            else
            {
                if(ten>=1&&five>=1)
                {
                    ten-=1;
                    five-=1;
                }
                else
                {
                    if(five<3) return false;
                    five-=3;
                }
            }
        }
        return true;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
