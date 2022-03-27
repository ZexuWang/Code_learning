/*560. 和为 K 的子数组
给你一个整数数组 nums 和一个整数 k ，请你统计并返回该数组中和为 k 的连续子数组的个数。

 

示例 1：

输入：nums = [1,1,1], k = 2
输出：2
示例 2：

输入：nums = [1,2,3], k = 3
输出：2*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;// 建立哈希map，key为he，值为出现的次数
        int sum = 0;//一开始的和为0
        int res = 0;//开始的返回值为0
        /*
        从0到i的合为sum[i]， 对于一个小于i的j来说，nums[j] 到nums[i]的和为 sum[i] - sum[j - 1]
        因此，当我们找到符合条件的连续数组j和i就有
        k = sum[i] - sum[j - 1] ---> sum[j - 1] = sum[i] - k
        因此，我们在map中加入{sum[i], sum[i]的出现频率}，那么如果我们在map中找到sum[i] - k，
        就表明，我们已经找到了满足条件的[j - 1]， 那么满足条件的[j - 1]的个数需要被加到结果中
        map[0] = 1表示，如果这个数字本身等于k，那么肯定是满足条件的
        如果有多个等于k的数字（比如nums[i+1] = k），那么我们通过累加sum[i]，
        再在下一个循环中判断sum[i + 1] - k = sum[i]，就会再次得到满足条件的答案
        */
        map[0] = 1;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (map.count(sum - k)) {
                res += map[sum - k];
            }
            map[sum]++;
        }
        return res;

    }
};

