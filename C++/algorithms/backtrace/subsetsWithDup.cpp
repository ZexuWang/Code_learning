/*90. 子集 II
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

 

示例 1：

输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
 

提示：

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        dfs(nums, path, 0);
        return res;
    }
    void dfs(vector<int>& nums, vector<int> path, int step) {
        res.push_back(path);
        for (int i = step; i < nums.size(); ++i) {
            // 去重，由于在此步中需要比较i和i - 1，因此需要nums为有序数列，因此在开始时需要对nums进行排序
            // 数字相同导致的后续组合也相同，因此同一个数字在同一层中只需要有一次即可
            // 但相同的数字可以出现在下一层再次出现
            if (i > step && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            dfs(nums, path, i + 1);
            path.pop_back();
        }
    }
};
