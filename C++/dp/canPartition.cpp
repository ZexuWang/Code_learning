/*416. 分割等和子集
给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

 

示例 1：

输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。
示例 2：

输入：nums = [1,2,3,5]
输出：false
解释：数组不能分割成两个元素和相等的子集。
 

提示：

1 <= nums.length <= 200
1 <= nums[i] <= 100*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // pre-process, find singular cases
        int n = nums.size();
        if (n < 2) {
            return false;
        }
        int sum = 0;
        for (auto& num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;
        // // method 1, use original amount of dp size for better understanding
        // vector<vector<bool>> dp(n, vector<bool>(target + 1));

        // if (nums[0] <= target) {
        //     dp[0][nums[0]] = true;
        // }
        // for (int i = 1; i < n; ++i) {
        //     for (int j = 0; j <= target; ++j) {
        //         if (j == nums[i]) {
        //             dp[i][j] = true;
        //         } else if (j > nums[i]) {
        //             dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
        //         } else {
        //             dp[i][j] = dp[i - 1][j];
        //         }
        //     }
        // }
        // return dp[n - 1][target];

        // // method 2, optimizing space
        vector<bool> dp(target + 1);
        dp[0] = true;// if we do not list any num, then 0 is reached
        if (nums[0] < target) {
            dp[nums[0]] = true;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = target; j >=0; --j) {
                if (j == nums[i]) {
                    dp[j] = true;
                } else if (j > nums[i]) {
                    dp[j] = dp[j] || dp[j - nums[i]];
                }
            }
        }
        return dp[target];
    }
};
