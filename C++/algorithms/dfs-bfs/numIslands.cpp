/*200. 岛屿数量
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

 

示例 1：

输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
示例 2：

输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] 的值为 '0' 或 '1'*/

class Solution {
public:
// 方法1:深度优先搜索
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int res = 0;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '1') {
                    ++res;
                    dfs(i, j, grid);
                }
            }
        }
        return res;
    }
    void dfs(const int& r, const int& c, vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r - 1][c] == '1') dfs(r - 1, c, grid);
        if (r + 1 < row && grid[r + 1][c] == '1') dfs(r + 1, c, grid);
        if (c - 1 >= 0 && grid[r][c - 1] == '1') dfs(r, c - 1, grid);
        if (c + 1 < col && grid[r][c + 1] == '1') dfs(r, c + 1, grid);
        return;
    }
// 方法2:广度优先搜索
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int res = 0;
        queue<std::pair<int, int>> neighbor;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '1') {
                    ++res;
                    grid[i][j] = '0';
                    neighbor.push({i, j});
                    while (!neighbor.empty()) {
                        int r = neighbor.front().first;
                        int c = neighbor.front().second;
                        neighbor.pop();
                        if (r - 1 >= 0 && grid[r - 1][c] == '1') {
                            grid[r - 1][c] = '0';
                            neighbor.push({r - 1, c});
                        }
                        if (r + 1 < row && grid[r + 1][c] == '1') {
                            grid[r + 1][c] = '0';
                            neighbor.push({r + 1, c});
                        }
                        if (c - 1 >= 0 && grid[r][c - 1] == '1'){
                            grid[r][c - 1] = '0';
                            neighbor.push({r, c- 1});
                        }
                        if (c + 1 < col && grid[r][c + 1] == '1') {
                            grid[r][c + 1] = '0';
                            neighbor.push({r, c + 1});
                        }

                    }
                }
            }
        }
        return res;
    }
};
