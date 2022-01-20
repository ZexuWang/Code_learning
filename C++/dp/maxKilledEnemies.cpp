/*361. 轰炸敌人
给你一个大小为 m x n 的矩阵 grid ，其中每个单元格都放置有一个字符：

'W' 表示一堵墙
'E' 表示一个敌人
'0'（数字 0）表示一个空位
返回你使用 一颗炸弹 可以击杀的最大敌人数目。你只能把炸弹放在一个空位里。

由于炸弹的威力不足以穿透墙体，炸弹只能击杀同一行和同一列没被墙体挡住的敌人。

 

示例 1：


输入：grid = [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
输出：3
示例 2：


输入：grid = [["W","W","W"],["0","0","0"],["E","E","E"]]
输出：1
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] 可以是 'W'、'E' 或 '0'
*/

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.size() < 1) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        int temp;
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; ++i) { // From left to right and from right to left
            temp = 0;
            for (int j = 0; j < n; ++j) {
                if(grid[i][j] == 'W') {
                    temp = 0;
                } else if (grid[i][j] == 'E') {
                    temp += 1;
                }
                dp[i][j] += temp;
            }
            temp = 0;
            for (int j = n - 1; j >= 0; --j){
                if(grid[i][j] == 'W') {
                    temp = 0;
                } else if (grid[i][j] == 'E') {
                    temp += 1;
                }
                dp[i][j] += temp;
            }
        }

        for (int j = 0; j < n; ++j) { // From top to buttom and from buttom to top
            temp = 0;
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] == 'W') {
                    temp = 0;
                } else if (grid[i][j] == 'E') {
                    temp += 1;
                }
                dp[i][j] += temp;
            }
            temp = 0;
            for (int i = m - 1; i >= 0; --i) {
                if (grid[i][j] == 'W') {
                    temp = 0;
                } else if (grid[i][j] == 'E') {
                    temp += 1;
                }
                dp[i][j] += temp;
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') {
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res;
    }
};
