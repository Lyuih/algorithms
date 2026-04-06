# 174. 地下城游戏

## 题目描述
[LeetCode 174. 地下城游戏](https://leetcode.cn/problems/dungeon-game/description/)

恶魔们抓住了公主并将她关在了地下城 dungeon 的 右下角 。地下城是由 m x n 个房间组成的二维网格。我们英勇的骑士最初被安置在 左上角 的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。

骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。

有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示骑士将损失健康点数）；其他房间要么是空的（房间里的值为 0），要么包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）。

为了尽快解救公主，骑士决定每次只 向右 或 向下 移动一步。

返回确保骑士能够拯救到公主所需的最低初始健康点数。

注意：任何房间都可能对骑士的健康点数造成威胁，也可能增加骑士的健康点数，包括骑士进入的左上角房间以及公主被监禁的右下角房间。
## 解题思路
- **核心算法**：动态规划
- **思路**：
由于后续的数值会影响到前面的dp数组
我们将dp[i][j] 定义为从下标i，j位置出发到达终点所需要的最小健康度
状态转移方程
dp[i][j] = max(1,min(dp[i+1][j],dp[i][j+1]-dungeon[i][j]))


## 代码实现
```python
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        # dp[i][j] 表示从i,j位置出发到达终点需要的健康度
        # 如果向右运动 dp[i][j] = x
        # x + dungeon[i][j] >= dp[i][j+1]
        # x = dp[i][j] - dungeon[i][j]
        n,m = len(dungeon),len(dungeon[0])
        dp = [[inf]*(m+1) for i in range(n+1)]
        dp[n][m-1] = dp[n-1][m] = 1
        for i in range(n-1,-1,-1):
            for j in range(m-1,-1,-1):
                dp[i][j] = min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j]
                dp[i][j] = max(1,dp[i][j])
        return dp[0][0]
```

github链接，我的做题之旅：[algorithms](https://github.com/Lyuih/algorithms)
