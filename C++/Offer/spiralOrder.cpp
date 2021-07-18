/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

 

示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
*/


class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        if (matrix.empty()) return {};
        vector<int> res;
        int l = 0;                      //左边界
        int r = matrix[0].size() - 1;   //右边界
        int t = 0;                      //上边界
        int b = matrix.size() - 1;      //下边界
        while (true)
        {
            //left -> right, 从最上层的最左侧开始向右
            for (int i = l; i <= r; i++) res.push_back(matrix[t][i]);
            if (++t > b) break;
            //top -> bottom，从最上层的最右侧开始向下
            for (int i = t; i <= b; i++) res.push_back(matrix[i][r]);
            if (--r < l) break;
            //right -> left， 从最下层的最右侧开始向左
            for (int i = r; i >= l; i--) res.push_back(matrix[b][i]);
            if (--b < t) break;
            //bottom -> top，从最下层的最下开始向上
            for (int i = b; i >= t; i--) res.push_back(matrix[i][l]);
            if (++l > r) break;
        }
        return res;
    }
};