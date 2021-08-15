/*
剑指 Offer 59 - I. 滑动窗口的最大值
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 

提示：

你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> sliding_que;//定义双端队列
        std::vector<int> res;//结果向量
        int n = nums.size();
        if(n < k || k <= 0) return res;
       // 在滑动窗口没有形成时 
        for (int i = 0; i < k ; ++i) {
            while (!sliding_que.empty() && sliding_que.back() < nums[i]) {
                sliding_que.pop_back();//若现有的队列队尾比第i个数字大时，删除->保证队列单调递减
            }
            sliding_que.push_back(nums[i]);//将第i个数压入队列尾部
        }
        res.push_back(sliding_que.front());//第一个解即为队列的队首
        //滑动窗口形成后
        for (int i = k ; i < n ; ++i) {
            if (sliding_que.front() == nums[i - k]) {//窗口开始向右滑动，若此条件成立，则队首需要被滑动出去
                sliding_que.pop_front();
            };
            while (!sliding_que.empty() && sliding_que.back() < nums[i]) {
                sliding_que.pop_back();
            }
            sliding_que.push_back(nums[i]);
            res.push_back(sliding_que.front());
        }
    return res;
    }
};