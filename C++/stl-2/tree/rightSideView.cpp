/*199. 二叉树的右视图
给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

 

示例 1:



输入: [1,2,3,null,5,null,4]
输出: [1,3,4]
示例 2:

输入: [1,null,3]
输出: [1,3]
示例 3:

输入: []
输出: []
 

提示:

二叉树的节点个数的范围是 [0,100]
-100 <= Node.val <= 100 */

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
    // method 1, dfs
    vector<int> res;
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode* node, int depth) {
        if (!node) {
            return;
        }
        if (depth == res.size()) {
            res.push_back(node->val);
        }
        depth++;
        dfs(node->right, depth);//先从右子树开始找，找到则填满这一层的val
        dfs(node->left, depth);//否则再找左子树
    }

    // method 2, bfs
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        std::queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
                if (i == size - 1) {//每层只取最有一个值插入
                    res.push_back(node->val);
                }
            }
        }
        return res;
    }
};
