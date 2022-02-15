/*119. 杨辉三角 II
给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。



 

示例 1:

输入: rowIndex = 3
输出: [1,3,3,1]
示例 2:

输入: rowIndex = 0
输出: [1]
示例 3:

输入: rowIndex = 1
输出: [1,1]
 

提示:

0 <= rowIndex <= 33*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
    /*第 n 行的第 m 个数（从 0 开始编号）可表示为可以被表示为组合数 \mathcal{C}(n,m)，即为从 n 个不同元素中取 m 个元素的组合数。 */
    int n = rowIndex;
    vector<int> res(n + 1);

    res[0] = 1;
    for (int i = 1; i <= n; ++i) {
        res[i] = 1LL *res[i - 1] * (n - i + 1) / i;
    }
    return res;

    }
};
