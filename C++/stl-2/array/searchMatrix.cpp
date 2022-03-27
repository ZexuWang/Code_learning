/*240. 搜索二维矩阵 II
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
	/*因为元素的特性，我们可以在每一行比较target和该行最后一个元素的大小*/
        for (int i = 0; i < m; ++i) {
            if (target > matrix[i][n - 1]) {
                continue;//表示target不在这一行
            }
            auto it = lower_bound(matrix[i].begin(), matrix[i].end(), target);//表示target可能在这一行，在此行寻找
            if (it != matrix[i].end() && *it == target) {
                return true;
            }
        }
        return false;

    }
};
