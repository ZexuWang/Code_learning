/*130. 被围绕的区域
给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 

示例 1：


输入：board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
示例 2：

输入：board = [["X"]]
输出：[["X"]]
 

提示：

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] 为 'X' 或 'O'*/

//方法1:深度优先搜索
/*本题的的思路就是沿着外围找到和外围的‘O’相连的‘O’， 并将这些没有被包围的标记*/
class Solution {
public:
    int row, col;
    void solve(vector<vector<char>>& board) {
        row = board.size();
        col = board[0].size();
        // 沿x、y方向对‘O’进行深度搜索
        for (int i = 0; i < row; ++i) {
            dfs(i, 0, board);
            dfs(i, col - 1, board);
        }
        for (int i = 0; i < col; ++i) {
            dfs(0, i, board);
            dfs(row - 1, i, board);
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }

    void dfs(int x, int y, vector<vector<char>>& board) {
        if (x >= row || x < 0 || y >= col || y < 0 || board[x][y] != 'O') {
            return;
        }
        board[x][y] = 'A';
        dfs(x - 1, y, board);
        dfs(x + 1, y, board);
        dfs(x, y - 1, board);
        dfs(x, y + 1, board);

    }
};

//方法2: 广度优先搜索
// 思路和深度优先搜索类似，也是从边缘的‘O’向内扩展寻找符合条件的点
class Solution {
public:
    int row, col;
    //节点扩展的四个方向
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void solve(vector<vector<char>>& board) {
        row = board.size();
        col = board[0].size();

        queue<pair<int,int>> que;
        //初始化处理，将四个边的点先放入队列中
        for (int i = 0; i < row; ++i) {
            if (board[i][0] == 'O') {
                que.emplace(i, 0);
            }
            if (board[i][col - 1] == 'O') {
                que.emplace(i, col - 1);
            }
        }

        for (int j = 0; j < col; ++j) {
            if (board[0][j] == 'O') {
                que.emplace(0, j);
            }
            if (board[row - 1][j] == 'O') {
                que.emplace(row - 1, j);
            }
        }
        //广度优先搜索
        while (!que.empty()) {
            auto front_element = que.front();
            int x = front_element.first;
            int y = front_element.second;
            board[x][y] = 'A';
            que.pop();
            for (auto& dir : directions) {
                int x_new = x + dir[0];
                int y_new = y + dir[1];
                if (x_new >= 0 && x_new < row && y_new >= 0 && y_new < col) {
                    if (board[x_new][y_new] == 'O') {
                        que.emplace(x_new, y_new);
                        board[x_new][y_new] = 'A';
                    }
                }
            }
        }
        //后处理
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
        
        return;
    }
};
