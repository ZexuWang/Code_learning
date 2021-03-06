/*56. 合并区间
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

 

示例 1：

输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2：

输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 

提示：

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // 排除极端情况
        if (n < 1) {
            return {};
        }
        sort(intervals.begin(), intervals.end());//将原interval以第一个元素升序排列

        vector<vector<int>> res;
        for (int i = 0; i < n; ++i) {
            int left = intervals[i][0], right = intervals[i][1];//找到每个区间的左右边界点
            if (res.empty() || left > res.back()[1]) {//若当前结果为空或者左侧边界点大于返回结果的右侧边界点，则不在区间内
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(res.back()[1], right);//否则，在区间内，且我们需要找到合适的新的右边界
            }
        }
        return res;
    }
};
