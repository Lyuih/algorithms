# LeetCode 206. 反转链表 

## 题目描述
[LeetCode 206. 反转链表](https://leetcode.cn/problems/reverse-linked-list/description/)

给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 
## 解题思路
- **核心算法**：递归
- **思路**：
  1. 确定递归终止条件为，如果当前节点为空或者当前节点下一个节点为空，则返回。
  2. 确定等价关系，把问题拆分成更小的子问题，反转当前节点的下一个节点,存储最后一个节点作为返回的头节点
  3. 确定函数功能，当前节点的下一个节点的下一个节点要指向当前节点，这样才能完成当前节点的反转，然后把当前节点的下一个节点置空。

- **复杂度分析**：
  - 时间复杂度：$O(n)$，只需遍历一条链表。
  - 空间复杂度：$O(n)$，递归压栈。

## 代码实现 (Python)
```C++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* prev = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return prev;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
