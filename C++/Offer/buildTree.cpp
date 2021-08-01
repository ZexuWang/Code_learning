/*
剑指 Offer 07. 重建二叉树
输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。

假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

 

示例 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
示例 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //将中序遍历存入哈希表中
        for (int i = 0; i < inorder.size(); i++) {
            map_inorder[inorder[i]] = i;//则在map_inorder中，key i对应inordermap中index为i的数
        }
        return recursive_build(preorder, inorder, 0, 0, inorder.size() - 1);
    }
private:
    unordered_map<int, int> map_inorder;
    TreeNode* recursive_build(vector<int>& preorder, vector<int>& inorder, int pre_root, int in_left, int in_right) {
        if (in_left > in_right) return nullptr;
        //建立新的根节点，此根节点以前序的根节点为根结点
        TreeNode* root = new TreeNode(preorder[pre_root]);
        //找到根结点在中序序列中的位置
        int in_root = map_inorder[preorder[pre_root]];
        //此时我们有中序下的： 左子树 | 根结点 | 右子树，且有根结点的index in_root
        /* 
        对于左子树，我们可以通过前序遍历得知其根节点在前序遍历中为 pre_root + 1  
        (前序遍历完根结点后就会到齐子节点的根结点)
         中序遍历的左边界为 in_left
         中序遍历的右边界为 in_root - 1 
         */
        root->left = recursive_build(preorder, inorder, pre_root + 1, in_left, in_root - 1);
        /*
        对于右子树，其前序遍历的根结点位于 根结点(pre_root) + 左子树长度(in_root - in_left) + 1 
        中序遍历的左边界为 in_root + 1
        中序遍历的右边界为 in_right 
        */
        root->right = recursive_build(preorder, inorder, pre_root + in_root - in_left + 1, in_root + 1, in_right);
        return root;
    }
};