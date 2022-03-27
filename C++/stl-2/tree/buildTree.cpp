/*105. 从前序与中序遍历序列构造二叉树
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

 

示例 1:


输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出: [3,9,20,null,null,15,7]
示例 2:

输入: preorder = [-1], inorder = [-1]
输出: [-1]
 

提示:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder 和 inorder 均 无重复 元素
inorder 均出现在 preorder
preorder 保证 为二叉树的前序遍历序列
inorder 保证 为二叉树的中序遍历序列*/

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


// Method 1: 递归
private:
    std::unordered_map<int, int> inorder_idx;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // 构造哈希映射，帮助我们快速定位根节点
        for (int i = 0; i < n; ++i) {
            inorder_idx[inorder[i]] = i;
        }
        /*通过前序和中序的定义我们知道：
        前序：【根，【左】，【右】】
        中序：【【左】，根，【右】】
        */
        return bfs(preorder, inorder, 0, n - 1, 0, n - 1);
    }

    TreeNode* bfs(vector<int>& preorder, vector<int>& inorder, int pre_left, int pre_right, int in_left, int in_right) {
        if (pre_left > pre_right) {
            return nullptr;
        }

        int pre_root_idx = pre_left;// 前序遍历中的第一个节点就是根节点
        int in_root_idx = inorder_idx[preorder[pre_root_idx]];// 在中序遍历中定位根节点
        int left_length = in_root_idx - in_left;// 得到左子树中的节点数目
        TreeNode* root = new TreeNode(preorder[pre_root_idx]);// 先把根节点建立出来
        root->left = bfs(preorder, inorder, pre_left + 1, pre_left + left_length, in_left, in_left + left_length - 1);// 递归地构造左子树，并连接到根节点
        root->right = bfs(preorder, inorder, pre_left + left_length + 1, pre_right, in_root_idx + 1, in_right);// 递归地构造右子树，并连接到根节点
        return root;

       
//Method 2：迭代，详细解释见草稿第4页
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int in = 0, pre = 1;
        stack<TreeNode*> stk;
        stk.push(root);

        while (pre < preorder.size()) {
            TreeNode* cur = stk.top();
            if (inorder[in] != cur->val) {
                cur->left = new TreeNode(preorder[pre]);
                stk.push(cur->left);
                ++pre;
            } else {
                while (!stk.empty() && stk.top()->val == inorder[in]) {
                    ++in;
                    cur = stk.top();
                    stk.pop();
                }
                cur->right = new TreeNode(preorder[pre]);
                stk.push(cur->right);
                ++pre;
            }
        }
    return root;
    }
};


