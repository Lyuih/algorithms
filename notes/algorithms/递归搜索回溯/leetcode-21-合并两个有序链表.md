# LeetCode 21. 合并两个有序链表 

## 题目描述
[LeetCode 21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/description/)

将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

## 解题思路
- **核心算法**：递归
- **思路**：
  1. 确定递归终止条件为，其中一个节点为nullptr，返回非空节点。
  2. 确定函数功能，节点值小的指向节点值大的
  3. 确定等价关系，把问题拆分成更小的子问题，把当前节点值小的节点的下一个节点和当前节点值大的节点继续比较
- **复杂度分析**：
  - 时间复杂度：$O(n+m)$，只需遍历两条链表。
  - 空间复杂度：$O(n+m)$，递归压栈。

## 代码实现 (Python)
```C++
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 || !list2) return list1 ? list1 : list2;
        ListNode* small = list1->val <= list2->val ? list1 : list2;
        ListNode* big = list1->val > list2->val ? list1 : list2;
        small->next = mergeTwoLists(small->next,big);
        return small;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
