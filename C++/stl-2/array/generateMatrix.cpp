/*59. 螺旋矩阵 II
给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

 

示例 1：


输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]
示例 2：

输入：n = 1
输出：[[1]]
 

提示：

1 <= n <= 20
通过次数158,044提交次数203,434*/

class Solution {
public:
    const vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> generateMatrix(int n) {
        // if (n == 1) {
        //     return n;
        // }
        int max_num = n * n;
        vector<vector<int>> res(n, vector<int> (n));
        int i = 0, j = 0;
        int dir_cur = 0;
        int k = 1;

        while (k <= max_num) {
            res[i][j] = k;
            k++;
            int i_new = i + dirs[dir_cur][0];
            int j_new = j + dirs[dir_cur][1];
            if (i_new < 0 || i_new >= n || j_new < 0 || j_new >= n || res[i_new][j_new] != 0) {
                dir_cur = (dir_cur + 1) % 4;
            }
            i = i + dirs[dir_cur][0];
            j = j + dirs[dir_cur][1];
        }
        return res;

    }
};
