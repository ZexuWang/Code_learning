/*576. 出界的路径数
给你一个大小为 m x n 的网格和一个球。球的起始坐标为 [startRow, startColumn] 。你可以将球移到在四个方向上相邻的单元格内（可以穿过网格边界到达网格之外）。你 最多 可以移动 maxMove 次球。

给你五个整数 m、n、maxMove、startRow 以及 startColumn ，找出并返回可以将球移出边界的路径数量。因为答案可能非常大，返回对 109 + 7 取余 后的结果。

 

示例 1：


输入：m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
输出：6
示例 2：


输入：m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
输出：12
 

提示：

1 <= m, n <= 50
0 <= maxMove <= 50
0 <= startRow < m
0 <= startColumn < n*/

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        static constexpr int MOD = 1'000'000'007;
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int res = 0;
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(m, vector<int>(n)));
        dp[0][startRow][startColumn] = 1;
        for (int i = 0; i < maxMove; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < n; ++k) {
                    int temp = dp[i][j][k];
                    if (temp > 0) {
                        for (auto& dir : directions) {
                            int j_new = j + dir[0];
                            int k_new = k + dir[1];
                            if (j_new >= 0 && j_new < m && k_new >= 0 && k_new < n) {
                                dp[i + 1][j_new][k_new] = (dp[i + 1][j_new][k_new] + temp)%MOD;
                            } else {
                                res = (res + temp) % MOD;
                            }

                        }
                    }
                }
            }
        }
        return res;
    }
};
