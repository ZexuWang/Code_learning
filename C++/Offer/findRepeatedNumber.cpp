/*
剑指 Offer 03. 数组中重复的数字

找出数组中重复的数字。


在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int,int> a;//建立一个名为a的哈希表
        for (auto& num: nums) {
            if (a[num] > 0) {
                return num;//当这个数字已经在哈希表中存在时，返回这个数字
            } else {
                a[num]++;//否则将该数字加入哈希表中
            }
        }
        return -1;
    }
};