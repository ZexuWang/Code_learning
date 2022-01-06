/*101. 对称二叉树
给定一个二叉树，检查它是否是镜像对称的。

 

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3*/

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
    // dfs
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return compare(root->left, root->right);
    }

    bool compare(TreeNode* left, TreeNode* right) {
        if (! left || !right) return (!left && !right);
        if (left->val != right->val) return false;
        return compare(left->right, right->left) && compare(left->left, right->right);
    }
    //bfs
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        if (!root->left || !root->right) {
            return !root->left && !root->right;
        }
        std::queue<TreeNode*> tree;
        tree.push(root);
        tree.push(root);
        while (!tree.empty()) {
            auto new_left = tree.front();
            tree.pop();
            auto new_right = tree.front();
            tree.pop();
            if (!new_right && !new_right) continue;
            if ((!new_left || !new_right) || (new_left->val != new_right->val)) {
                return false;
            }
            tree.push(new_left->left);
            tree.push(new_right->right);
            tree.push(new_left->right);
            tree.push(new_right->left);
        }
        return true;
    }

};
