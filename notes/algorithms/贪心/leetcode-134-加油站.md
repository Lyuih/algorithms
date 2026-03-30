
# 134. 加油站

## 题目描述
[LeetCode 134. 加油站](https://leetcode.cn/problems/gas-station/description/)

在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。

给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 。如果存在解，则 保证 它是 唯一 的。


## 解题思路
- **核心算法**：贪心
- **思路**：
枚举加油站,往后如果能成功循环则返回,不能成功循环这把当前指针指向最后失败的位置.
比如:
当前下标i,走了j步时无法满足要求
i = i+j+1

## 代码实现 
```C++
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int n = gas.size();
        for(int i = 0;i<n;++i)
        {
            int rest = 0;
            int j = 0;
            for(;j<n;++j)
            {
                int index = (i+j)%n;
                rest = rest - cost[index] + gas[index];
                if(rest<0) break;
            }
            if(rest>=0) return i;
            i = i+j;
        }
        return -1;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
