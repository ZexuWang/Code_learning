/*75. 颜色分类
给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

必须在不使用库的sort函数的情况下解决这个问题。

 

示例 1：

输入：nums = [2,0,2,1,1,0]
输出：[0,0,1,1,2,2]
示例 2：

输入：nums = [2,0,1]
输出：[0,1,2]
 

提示：

n == nums.length
1 <= n <= 300
nums[i] 为 0、1 或 2
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;

        if(n < 2) {
            return;
        }

        // // method 1, not using swap
        /*此方法是先找到0和1对应的下标位置，然后再重新将数组按照该顺序填入对应的0、1、2
        但并不符合题中要求的原地排序因此并不符合*/
        // for (int i = 0; i < n; ++i) {
        //     if (nums[i] == 0 && left <= n - 1) {
        //         left++;
        //     } else if (nums[i] == 2 && right >= left) {
        //         right--;
        //     }
        // }
        // for (int i = 0; i < n; ++i) {
        //     if (i < left) {
        //         nums[i] = 0;
        //     } else if (i <= right) {
        //         nums[i] = 1;
        //     } else {
        //         nums[i] = 2;
        //     }
        // }

        // method 2 using swap
        int p0 = 0, p1 = 0;//p0代表0对应的边界位置，p1代表1对应的边界位置
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                swap(nums[i], nums[p1]);//如果数字为1，则交换当前位置与p0的位置
                p1++;
            } else if (nums[i] == 0) {//如果数字为0，则先交换p0和当前的位置
                swap(nums[i],nums[p0]);
                // p0 < p1， 代表在p0和p1 - 1区间都是1，此时将p0和当前位置交换后，会把一个1交换到当前位置
                // 因此，在这个情况下，需要将当前位置在此和p1进行交换，将置换到后方的1在换回1的右侧边界
                if (p0 < p1) {
                    swap(nums[i], nums[p1]);
                }
                ++p0;
                ++p1;
            }
        }
        return;
    }
};
