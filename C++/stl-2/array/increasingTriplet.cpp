/*334. 递增的三元子序列
给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。

如果存在这样的三元组下标 (i, j, k) 且满足 i < j < k ，使得 nums[i] < nums[j] < nums[k] ，返回 true ；否则，返回 false 。*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int first = nums[0], second = INT_MAX;

        for (int i = 1; i < n; ++i) {
            if (nums[i] > second) {//如果找到比第二个数字大的数字，则寻找完成
                return true;
            } else if (nums[i] > first) {
                second = nums[i];//当当前数字 first < nums[i] <= second，将第二个数字更新为当前数字
            } else {
                first = nums[i];//更新first
            }
        }
        return false;

    }
};
