/*47. 全排列 II
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

 

示例 1：

输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
示例 2：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

提示：

1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/
class Solution {
public:
    vector<bool> visited;//当前的节点是否被访问过
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> path;
        sort(nums.begin(), nums.end());
        visited.resize(nums.size());
        backtrace(nums, path, 0);
        return res;
    }
    void backtrace(vector<int>& nums, vector<int> path, int idx) {
        if (idx == nums.size()) {//表示长度，如果长度和nums相同，则可以压入res中
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            //因为此步的判断，需要先将nums进行排序
            // 如果当前位置访问过，则不在访问
            // 如果当前数字和上一个数字相同（在当前层相同则组合也相同）且上一数字未被访问，则访问上一数字而不访问当前数字
            if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])) continue;
            path.push_back(nums[i]);
            visited[i] = true;
            backtrace(nums, path, idx + 1);
            visited[i] = false;//退回后需要先将visited置成false，否则后续无法访问该位置
            path.pop_back();
        }
    }
};
