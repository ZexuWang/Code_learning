/*329. 矩阵中的最长递增路径
给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。

 

示例 1：


输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
输出：4 
解释：最长递增路径为 [1, 2, 6, 9]。
示例 2：


输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
输出：4 
解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
示例 3：

输入：matrix = [[1]]
输出：1
 

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1*/

class Solution {
public:
    int n, m;
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        if (n < 1 || m < 1) {
            return 0;
        }

        vector<vector<int>> memo(n, vector<int> (m));
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++ j) {
                res = max(res, dfs(matrix, i, j, memo));
            }
        }
    return res;
    }

    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& memo) {
        if (memo[i][j] != 0) {
            return memo[i][j];
        }
        memo[i][j]++;

        for (int k = 0; k < 4; ++k){
            int new_i = i + dirs[k][0], new_j = j + dirs[k][1];
            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && matrix[new_i][new_j] > matrix[i][j]) {
                memo[i][j] = max(memo[i][j], dfs(matrix, new_i, new_j, memo) + 1);
            }
        }
         return memo[i][j];
    }

};
