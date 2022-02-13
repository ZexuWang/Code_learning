/*494. 目标和
给你一个整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

 

示例 1：

输入：nums = [1,1,1,1,1], target = 3
输出：5
解释：一共有 5 种方法让最终目标和为 3 。
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
示例 2：

输入：nums = [1], target = 1
输出：1
 

提示：

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000*/


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0, n = nums.size();

        for (auto& num : nums) {
            sum += num;
        }

        if ((sum - target) % 2 != 0 || sum -target < 0) {
            return 0;
        }
        int neg = (sum - target) / 2;
        // // method 1, direct dp without space optimization
        // vector<vector<int>> dp(n + 1, vector<int>(neg + 1));
        // dp[0][0] = 1;

        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 0; j <= neg; ++j) {
        //         if (j >= nums[i - 1]) {
        //             dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
        //         } else {
        //             dp[i][j] = dp[i - 1][j];
        //         }
        //     }
        // }
        // return dp[n][neg];

        // method 2, dp with space optimization
        vector<int> dp(neg + 1);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = neg; j >= 0; --j) {
                if (j >= nums[i]) {
                    dp[j] += dp[j - nums[i]];
                }
            }
        }
        return dp[neg];
    }
};
