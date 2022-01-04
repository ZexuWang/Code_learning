/*145. 二叉树的后序遍历
给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [3,2,1]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？*/

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
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> res;
        std::stack<TreeNode*> stk;
        TreeNode* prev = nullptr;
        while(root != nullptr || !stk.empty()) {
            while(root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root  = stk.top();
            stk.pop();

            if (root->right == nullptr || root->right == prev) {
                res.push_back(root->val);
                prev = root;
                root = nullptr;
            } else {
                stk.push(root);
                root = root->right;
            }
        }
        return res;

    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> res;
        postorder(root, res);
        return res;
    }

    void postorder(TreeNode* root, std::vector<int>& res) {
        if (root == nullptr) {
            return;
        }

        postorder(root->left,res);
        postorder(root->right,res);
        res.push_back(root->val);

    }
};
