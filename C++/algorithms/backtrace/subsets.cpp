/*78. 子集
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

 

示例 1：

输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
 

提示：

1 <= nums.length <= 10
-10 <= nums[i] <= 10
nums 中的所有元素 互不相同*/

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        dfs(nums, path, 0);
        return res;
    }
    void dfs(vector<int>& nums, vector<int> path, int step) {
        res.push_back(path);//每次都将当前的路径压入最后的答案中
        for (int i = step; i < nums.size(); ++i) {
            path.push_back(nums[i]);//选择当前位置
            dfs(nums, path, i + 1);//继续向深处搜索，此步为核心步，需要多理解
            path.pop_back();//退出到上一步继续搜索
        }
    }
};
