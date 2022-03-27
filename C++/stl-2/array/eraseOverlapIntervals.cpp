/*435. 无重叠区间
给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回 需要移除区间的最小数量，使剩余区间互不重叠 。
*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // // method 1:动态规划
        // int n = intervals.size();

        // if (n < 2) {
        //     return 0;
        // }
	// // 将给定的intervals以第一个元素递增排序
        // sort (intervals.begin(), intervals.end(), [] (const auto& a, const auto& b) {
        //     return a[0] < b[0];
        // });
	// // 给定一个dp数组，dp(i)表示遍历到元素i时无重叠区间的个数,初始值设定为1是因为在极端状况下，所有interval都相同，那么无重叠区间也有一个
        // vector<int> dp(n, 1);
        // int max_num = 0;

        // for (int i = 1; i < n; ++i) {
        //     for (int j = 0; j < i; ++j) {
        //         if (intervals[j][1] <= intervals[i][0]) {//由于第一个元素时升序排列的，第二个元素满足此条件则说明有重叠
        //             dp[i] = max(dp[j] + 1, dp[i]);
        //         }
        //     }
        // }
        // return n - *max_element(dp.begin(), dp.end());

        // method 2 greedy
	// 思路和1很类似，找到没有重叠的区间个数，再用总长度减去这个个数得到有重叠的个数
        if (intervals.empty()) {
            return 0;
        }
        // 将数组按照右侧数据的大小排序
        sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
            return u[1] < v[1];
        });

        int n = intervals.size();
        int right = intervals[0][1];
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] >= right) {
                ++ans;// 如果当前的左侧比右侧大，则没有重叠
                right = intervals[i][1];
            }
        }
        return n - ans;
    }
};
