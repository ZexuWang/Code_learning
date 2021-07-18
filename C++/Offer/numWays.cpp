/*
剑指 Offer 10- II. 青蛙跳台阶问题

一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：

输入：n = 2
输出：2
示例 2：

输入：n = 7
输出：21
示例 3：

输入：n = 0
输出：1
提示：

0 <= n <= 100
*/
class Solution {
public:
    int numWays(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        // 方法1
        // // 1. 定义初始状态
        // int pre = 1;
        // int cur = 2;
        // // 3. 定义状态转移
        // for (int i = 3; i <= n ; i++) {
        //     int res = pre + cur;
        //     res %= 1000000007;
        //     pre = cur;
        //     cur = res;
        // }
        // // 4. 返回最终值
        // return cur;
        //方法2
        // 1. 定义状态向量，dp[i] 表示的是数字 i 的斐波那契数
        std::vector<int> dp(n + 1);
        // 2. 定义初始状态
        dp[1] = 1;
        dp[2] = 2;
        // 3. 定义状态转移
        for (int i = 3; i <= n ; i++) {
            dp[i] = dp[i-1] + dp[i-2];
            dp[i] %= 1000000007;
        }
        // 4. 返回最终值
        return dp[n];

    }
};