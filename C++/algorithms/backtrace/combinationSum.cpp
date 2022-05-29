/*39. 组合总和
给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。

candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

对于给定的输入，保证和为 target 的不同组合数少于 150 个。

 

示例 1：

输入：candidates = [2,3,6,7], target = 7
输出：[[2,2,3],[7]]
解释：
2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
7 也是一个候选， 7 = 7 。
仅有这两种组合。
示例 2：

输入: candidates = [2,3,5], target = 8
输出: [[2,2,2,2],[2,3,3],[3,5]]
示例 3：

输入: candidates = [2], target = 1
输出: []
 

提示：

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
candidate 中的每个元素都 互不相同
1 <= target <= 500
*/

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        backtrace(candidates, target, path, 0);
        return res;
    }
    void backtrace(vector<int>& candidates, int target, vector<int>& path, int step) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = 0; i < candidates.size(); ++i) {
            //由于数组已经经过排序，因此在此遇到更小的数字说明该数字已经被访问过，因此跳过
            if (!path.empty() && candidates[i] < path.back()) continue;
            path.push_back(candidates[i]);
            target -= candidates[i];
            backtrace(candidates, target, path, step + 1);
            target += candidates[i];
            path.pop_back();
        }
    }
};
