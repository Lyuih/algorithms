# LeetCode 24. 两两交换链表中的节点 

## 题目描述
[LeetCode 24. 两两交换链表中的节点](https://leetcode.cn/problems/swap-nodes-in-pairs/description/)

给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
 
## 解题思路
- **核心算法**：递归
- **思路**：
  1. 确定递归终止条件为，如果当前剩余节点数量小于2两个直接返回，不需要交换了
  2. 确定等价关系，把问题拆分成更小的子问题，继续交换当前节点的下一个的下一个节点，并存储交换成果后的头节点。
  3. 确定函数功能，交换当前的两个节点，并处理递归成果的节点

- **复杂度分析**：
  - 时间复杂度：$O(n)$，只需遍历一条链表。
  - 空间复杂度：$O(n)$，递归压栈。

## 代码实现 (Python)
```C++
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* tmp = swapPairs(head->next->next);
        ListNode* next = head->next;
        next->next = head;
        head->next = tmp;
        return next;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
