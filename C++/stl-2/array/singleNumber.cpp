/*136. 只出现一次的数字
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1
示例 2:

输入: [4,1,2,1,2]
输出: 4*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // // method 1 using hash set
        // unordered_set<int> set;
        // int n = nums.size();

        // for (int i = 0; i < n; ++i) {
        //     auto p = set.emplace(nums[i]);
        //     if (!p.second) {
        //         set.erase(nums[i]);
        //     }
        // }
        // return *(set.begin());

        // method 2, using bitwise EXCLUSIVE OR (XOR)
        /*我们可以发现一个按位异或操作的性质：一个值和0进行按位异或操作所得为该值，相同的两个值进行异或操作，所得为0（甲 按位异或 0 得 甲，甲 按位异或 甲 得 0）。

根据这个性质，由于每个重复元素重复两次，故他们在遍历后将相互抵消，而唯一元素只出现一次，故将得到保留
*/
        int res = 0;
        for (auto& num : nums) {
            res ^= num;
        }
        return res;
    }
};
