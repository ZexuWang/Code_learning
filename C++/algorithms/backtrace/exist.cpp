/*79. 单词搜索
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

示例 1：


输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
示例 2：


输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
输出：true
示例 3：


输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
输出：false
 

提示：

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board 和 word 仅由大小写英文字母组成*/

class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool backtrace(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string& word, int k) {
        if (board[i][j] != word[k]) {
            return false;
        } else if (k == word.length() - 1) {
            return true;
        }
        visited[i][j] = true;
        bool result = false;
        for (const auto& dir: dirs) {
            int ni = i + dir[0], nj = j + dir[1];
            if (ni >= 0 && ni < board.size() && nj >= 0 && nj < board[0].size()) {
                if (!visited[ni][nj]) {
                    bool flag = backtrace(board, visited, ni, nj, word, k + 1);
                    if (flag) {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int x = board.size(), y = board[0].size();
        vector<vector<bool>> visited(x, vector<bool>(y));
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                bool ret = backtrace(board, visited, i, j, word, 0);
                if (ret) {
                    return true;
                }
            }
        }
        return false;
    }
};
