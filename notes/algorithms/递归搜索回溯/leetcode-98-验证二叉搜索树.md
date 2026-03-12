# LeetCode 98. 验证二次搜索树 

## 题目描述
[LeetCode 24. 验证二次搜索树](https://leetcode.cn/problems/validate-binary-search-tree/description/)
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：

节点的左子树只包含 严格小于 当前节点的数。
节点的右子树只包含 严格大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
 
## 解题思路
- **核心算法**：递归，中序遍历
- **思路**：
  1. 确定递归终止条件为，如果当前节点为空则返回真
  2. 使用中序遍历，判断当前节点是否大于前一个节点，如果大于继续遍历否则返回假

- **复杂度分析**：
  - 时间复杂度：$O(n)$
  - 空间复杂度：$O(n)$

## 代码实现 (Python)
```C++
class Solution {
public:
long long pre = LONG_LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        bool a = isValidBST(root->left);
        if(!a) return false;
        if(root->val <= pre)
        {
            return false;
        }
        pre = root->val;
        return isValidBST(root->right);
    }
};
```
## 解题思路
- **核心算法**：递归，前序遍历
- **思路**：
  1. 确定递归终止条件为，如果当前节点为空则返回真
  2. 使用前序遍历，增加两个缺省参数，分别表示当前节点上的最小值和最大值。

- **复杂度分析**：
  - 时间复杂度：$O(n)$
  - 空间复杂度：$O(n)$

```c++
class Solution {
public:
    bool isValidBST(TreeNode* root,long long left = LLONG_MIN,long long right = LLONG_MAX) {
        if(!root) return true;
        long long x = root->val;
        return left<x&&x<right&&isValidBST(root->left,left,x)&&isValidBST(root->right,x,right);
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
