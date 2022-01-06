/*265. 粉刷房子 II
假如有一排房子，共 n 个，每个房子可以被粉刷成 k 种颜色中的一种，你需要粉刷所有的房子并且使其相邻的两个房子颜色不能相同。

当然，因为市场上不同颜色油漆的价格不同，所以房子粉刷成不同颜色的花费成本也是不同的。每个房子粉刷成不同颜色的花费是以一个 n x k 的矩阵来表示的。

例如，costs[0][0] 表示第 0 号房子粉刷成 0 号颜色的成本花费；costs[1][2] 表示第 1 号房子粉刷成 2 号颜色的成本花费，以此类推。请你计算出粉刷完所有房子最少的花费成本。

注意：

所有花费均为正整数。

示例：

输入: [[1,5,3],[2,9,4]]
输出: 5
解释: 将 0 号房子粉刷成 0 号颜色，1 号房子粉刷成 2 号颜色。最少花费: 1 + 4 = 5; 
     或者将 0 号房子粉刷成 2 号颜色，1 号房子粉刷成 0 号颜色。最少花费: 3 + 2 = 5. 
进阶：
您能否在 O(nk) 的时间复杂度下解决此问题？

*/

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        std::vector<std::vector<int>> dp(costs.size(), vector<int>(costs[0].size(), 0));
        // i is the # of house, j is color

        for (int i = 0; i < costs[0].size(); i++) {
            dp[0][i] = costs[0][i];
        }


        for (int i = 1; i < costs.size(); ++i) {
            for (int j = 0; j < costs[0].size(); ++ j) {
                int min_val = INT_MAX;
                for (int k = 0; k < costs[0].size(); ++k) {
                    if (j != k) {
                        min_val = min(min_val, dp[i - 1][k]);
                    }
                }
                dp[i][j] = min_val + costs[i][j];
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < costs[0].size(); ++i) {
            res = min(res, dp[costs.size() - 1][i]);
        }
        return res;
    }
};
