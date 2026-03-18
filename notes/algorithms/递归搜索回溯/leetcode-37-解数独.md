# LeetCode 37.解数独

## 题目描述
[LeetCode 37.解数独](https://leetcode.cn/problems/sudoku-solver/description/)

编写一个程序，通过填充空格来解决数独问题。

数独的解法需 遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。

## 解题思路
- **核心算法**：哈希，数组，回溯
- **思路**：
在36题的基础上添加回溯
利用三个数组，存储所有行、列、九宫格的状态。
存储完完状态后开始回溯遍历所有的可能
注意返回条件，只有运行到board都被填上数字（此时一定是该数独的解）后返回解，然后递归返回，前面的递归函数接受到true保留该状态直接返回，为false则继续往下执行，直到该位置的所有可能被填完返回false。
## 代码实现 (Python)
```C++
class Solution {
public:
    int col[9][10], row[9][10], grid[3][3][10];
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    row[i][num] = col[j][num] = grid[i / 3][j / 3][num] = true;
                }
            }
        }
        dfs(board);
    }
    bool dfs(vector<vector<char>>& board) {

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (int num = 1; num < 10; ++num) {
                        if (!row[i][num] && !col[j][num] &&
                            !grid[i / 3][j / 3][num]) {
                            row[i][num] = col[j][num] =
                                grid[i / 3][j / 3][num] = true;
                            board[i][j] = '0' + num;
                            if(dfs(board)) return true;
                            row[i][num] = col[j][num] =
                                grid[i / 3][j / 3][num] = false;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
