# LeetCode 257. 二叉树的所有路径

## 题目描述
[LeetCode 257. 二叉树的所有路径](https://leetcode.cn/problems/binary-tree-paths/description/)

给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。

叶子节点 是指没有子节点的节点。
## 解题思路
- **核心算法**：回溯
- **思路**：
前序遍历二叉树，定义一个数组存储结果(ret)，在定义一个空串充当临时对象(s)。
注意回溯函数参数里面的字符串不要用引用。
回溯时，当遇到空节点直接返回，如果是叶子节点表示一条路径存储到ret中
- **复杂度分析**：
  - 时间复杂度：$O(n)$
  - 空间复杂度：$O(n)$

## 代码实现 (Python)
```C++
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        dfs(root,ret,"");
        return ret;
    }
    void dfs(TreeNode* root,vector<string>& ret,string s)
    {
        if(!root) return;
        if(!root->left&&!root->right)
        {
            s.append(to_string(root->val));
            ret.push_back(move(s));
            return;
        }
        s.append(to_string(root->val)+"->");
        dfs(root->left,ret,s);
        dfs(root->right,ret,s);
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
