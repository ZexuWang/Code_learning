/*113. 路径总和 II
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

叶子节点 是指没有子节点的节点。

 

示例 1：


输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：[[5,4,11,2],[5,8,4,5]]
示例 2：


输入：root = [1,2,3], targetSum = 5
输出：[]
示例 3：

输入：root = [1,2], targetSum = 0
输出：[]
 

提示：

树中节点总数在范围 [0, 5000] 内
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    //method 1, dfs
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return res;
    }

    void dfs(TreeNode* root, int targetSum) {
        if (!root) {
            return;
        }
        path.push_back(root->val);
        targetSum -= root->val;

        if (!root->left && !root->right && targetSum == 0) {
            res.push_back(path);
        }
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        path.pop_back();
    }

    // method 2, bfs
    vector<vector<int>> res;
    unordered_map<TreeNode*, TreeNode*> parent;// key: 当前node， val：父节点

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return res;
        }

        queue<TreeNode*> q_node;
        queue<int> q_sum;
        q_node.push(root);
        q_sum.push(0);

        while(!q_node.empty()) {
            TreeNode* node = q_node.front();
            q_node.pop();

            int sum = q_sum.front() + node->val;
            q_sum.pop();

            if (!node->left && !node->right) {
                if (sum == targetSum) {
                    get_path(node);
                }
            } else {
                if (node->left) {
                    parent[node->left] = node;
                    q_node.push(node->left);
                    q_sum.push(sum);
                }
                if (node->right) {
                    parent[node->right] = node;
                    q_node.push(node->right);
                    q_sum.push(sum);
                }
            }
        }
        return res;
    }

    void get_path(TreeNode* node) {
        vector<int> path;
        while (node) {
            path.push_back(node->val);
            node = parent[node];
        }
        reverse(path.begin(), path.end());
        res.push_back(path);
    }
};
