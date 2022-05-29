/*40. 组合总和 II
给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用 一次 。

注意：解集不能包含重复的组合。 

 

示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
输出:
[
[1,2,2],
[5]
]
 

提示:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrace(candidates, target, path, 0);
        return res;
    }
    void backtrace(vector<int>& candidates, int target, vector<int>& path, int step) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        // if (target < 0) {
        //     return;
        // }
        for (int i = step; i < candidates.size() && target - candidates[i] >= 0; ++i) {
            //由于数组已经经过排序，因此在此遇到更小的数字说明该数字已经被访问过，因此跳过
            if (i > step && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            backtrace(candidates, target - candidates[i], path, i + 1);//此处应该为i + 1而非step + 1
            path.pop_back();
        }
    }
};


