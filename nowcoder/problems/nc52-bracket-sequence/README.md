# 牛客 NC52. 括号序列 (Bracket Sequence)

## 题目描述
[牛客 NC52. 括号序列](https://www.nowcoder.com/practice/37548a94d2704340adfbba623ad73b90)
给出一个仅包含 `'('`, `')'`, `'{'`, `'}'`, `'['`, `']'` 的字符串，判断字符串是否有效。

## 解题思路
- **核心算法**：栈 (Stack)
- **思路**：
  1. 遇到左括号时，将其对应的右括号入栈。
  2. 遇到右括号时，检查栈是否为空，或弹出栈顶元素是否与当前括号匹配。
  3. 最后检查栈是否为空。
- **复杂度分析**：
  - 时间复杂度：$O(n)$
  - 空间复杂度：$O(n)$

## 代码实现 (Java)
```java
import java.util.*;

public class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            if (c == '(') stack.push(')');
            else if (c == '[') stack.push(']');
            else if (c == '{') stack.push('}');
            else if (stack.isEmpty() || stack.pop() != c) return false;
        }
        return stack.isEmpty();
    }
}
```
