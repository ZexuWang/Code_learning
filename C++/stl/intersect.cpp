/*
 *350. 两个数组的交集 II
给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。

 

示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2,2]
示例 2:

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[4,9]
 

提示：

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000

 *
 * */

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if (nums1.size() < 1 || nums2.size() < 1) {
            return result;
        }
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);// always ensure that nums1 is shorter in length
        }
        std::unordered_map<int, int> map;
        for (const auto& num : nums1) {
            ++map[num];// num is the key and value is how many times does the num shows up
        }
        for (const auto& num : nums2) {
            if (map[num] != 0) {
                result.push_back(num);
                --map[num];
            }
        }
    return result;
    }
};
