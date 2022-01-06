/*102. 二叉树的层序遍历
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

 

示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层序遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
*/


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<vector<int>> res;
        std::queue<TreeNode*> tree;
        if (root == nullptr) {
            return res;
        }

        tree.push(root);
        while (!tree.empty()) {
            int len = tree.size();
            vector<int> cur;
            for (int i = 0; i < len; ++i) {
                TreeNode* node = tree.front();
                tree.pop();
                cur.push_back(node->val);
                if (node->left) {
                    tree.push(node->left);
                }
                if (node->right) {
                    tree.push(node->right);
                }
            }
            res.push_back(cur);
        }
    return res;


    }
};
