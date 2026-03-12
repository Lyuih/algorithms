# LeetCode 230.二叉搜索树中第 K 小的元素

## 题目描述
[LeetCode 230. 二叉搜索树中第 K 小的元素](https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/)

给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 小的元素（k 从 1 开始计数）。
 
## 解题思路
- **核心算法**：递归，中序遍历
- **思路**：
  利用二叉搜索树特性，中序遍历时为升序，也就是表示了第k小的元素就是中序遍历时经历的第k个节点
  1.定义两个全局变量，一个用来存储最终结果(ret)，一个用来计数当前为第几个节点(count)
  2.命count等于k，中序遍历，每遍历完一次左节点就让count-1，直到count==0时该节点就是需要的节点。
  3.剪枝，除去节点为空需要返回外，添加当count为0时也返回

- **复杂度分析**：
  - 时间复杂度：$O(n)$
  - 空间复杂度：$O(n)$

## 代码实现 (Python)
```C++
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        //可以二叉搜索树中序遍历是有序的特性
        count = k;
        dfs(root);
        return ret;
    }
    void dfs(TreeNode* root)
    {
        if(root==nullptr || count == 0) return;
        dfs(root->left);
        --count;
        if(count == 0) ret = root->val;
        dfs(root->right);
    }
    int ret,count;
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
