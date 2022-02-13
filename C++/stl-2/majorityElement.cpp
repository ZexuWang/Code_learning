/*169. 多数元素
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 

示例 1：

输入：[3,2,3]
输出：3
示例 2：

输入：[2,2,1,1,1,2,2]
输出：2
 

进阶：

尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // // method 1, sort the nums set and return the half value which might to be the answer
        // sort(nums.begin(), nums.end());
        // int n = nums.size()/2;
        // return nums[n];

        // // method 2, hash table
        // unordered_map<int, int> map; // first: num, second: # of apparence
        // for (auto& num : nums) {
        //     map[num]++;
        //     if (map[num] > nums.size() / 2) {
        //         return num;
        //     }
        // }
        // return -1;

        // method 3, Boyer-Moore
        int candidate = -1, count = 0;

        for(auto& num : nums) {
            if (count == 0) {
                candidate = num;
            }
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        return candidate;
    }
};
