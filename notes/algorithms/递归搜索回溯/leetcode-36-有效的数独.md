# LeetCode 36.有效的数独

## 题目描述
[LeetCode 36.有效的数独](https://leetcode.cn/problems/valid-sudoku/description/)

请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
 

注意：

一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。
空白格用 '.' 表示。
## 解题思路
- **核心算法**：哈希，数组
- **思路**：
利用三个数组，存储所有行、列、九宫格的状态。
就是遍历数组，修改三个数组的状态，一旦和规则冲突返回false

## 代码实现 (Python)
```C++
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][10];
        bool col[9][10];
        bool grid[3][3][10];
        for(int i = 0;i<9;++i)
        {
            for(int j = 0;j<9;++j)
            {
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                if(row[i][num] || col[j][num] || grid[i/3][j/3][num])
                {
                    return false;
                }
                row[i][num] = col[j][num] = grid[i/3][j/3][num] = true;
            }
        }
        return true;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
