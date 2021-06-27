/*给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

链接：https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        col = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < col; j++) {
                // 使用广度优先算法
                if (dfs_search(board, word, i, j,0)) return true;
                //广度优先递归，此时搜索从第1个word的索引开始搜索
            }
        }
        return false;

    }
private:
    int rows, col;
    bool dfs_search(vector<vector<char>>& board, string word, int i, int j, int k) {
        if (i >= rows || i < 0 || j >= col || j < 0) return false;
        if (k == word.size() - 1) return true;//搜索到最后索引的word值，此时还为true，则找到答案
        board[i][j] = '\0';
        bool res = dfs_search(board, word, i + 1,j,k+1) || dfs_search(board, word, i -1 ,j,k+1)
                || dfs_search(board, word, i,j + 1,k+1) || dfs_search(board, word, i ,j - 1,k+1);
        board[i][j] = word[k];
        return res;
        //当且仅当res为true时，表示从当前节点往下搜索可以搜到下一个索引对应的字符
    }
};