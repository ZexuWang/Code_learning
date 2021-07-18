/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

 

示例：

输入：nums = [1,2,3,4]
输出：[1,3,2,4] 
注：[3,1,2,4] 也是正确的答案之一。
*/

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] % 2 != 0) {
                left ++;
                continue;
            }
            if (nums[right] %2 ==0) {
                right --;
                continue;
            }
            std::swap(nums[left],nums[right]);
        }
        return nums;
    }
};