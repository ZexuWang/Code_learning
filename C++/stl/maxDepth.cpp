/*104. 二叉树的最大深度
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。

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
    //dfs
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    // bfs
    int maxDepth(TreeNode* root) {
        std::queue<TreeNode*> tree;
        int level = 0;
        if (!root) {
            return level;
        }
        tree.push(root);
        while(!tree.empty()) {
            int len = tree.size();
            for (int i = 0; i < len; ++i) {
                TreeNode* node = tree.front();
                tree.pop();
                if (node->left) {
                    tree.push(node->left);
                }
                if (node->right) {
                    tree.push(node->right);
                }
            }
            ++ level;
        }
        return level;
    }
};
