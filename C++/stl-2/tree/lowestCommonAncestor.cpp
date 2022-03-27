/*236. 二叉树的最近公共祖先
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

 

示例 1：


输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出：3
解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
示例 2：


输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出：5
解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。
示例 3：

输入：root = [1,2], p = 1, q = 2
输出：1
 

提示：

树中节点数目在范围 [2, 105] 内。
-109 <= Node.val <= 109
所有 Node.val 互不相同 。
p != q
p 和 q 均存在于给定的二叉树中。*/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
        终止条件：
        1. 当越过叶节点，则直接返回 null
        2. 当 root 等于 p,q ，则直接返回 root
        */
        if (!root || root == p || root == q) return root;
        //开启递归左子节点，返回值记为 left
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        //开启递归右子节点，返回值记为 right
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        //当 left 和 right 同时为空 ：说明 root 的左 / 右子树中都不包含 p, q ，返回 null
        if (!left && !right) return nullptr;
        //当 left 为空 ，right 不为空 ：p,q 都不在 root 的左子树中，直接返回 right
        // 分两种情况：
        // 1. p,q 其中一个在 root 的 右子树 中，此时 right 指向 p（假设为 p ）；
        // 2. p,q 两节点都在 root 的 右子树 中，此时的 right 指向 最近公共祖先节点
        if (!left) return right;
        //当 leftleft 不为空 ， rightright 为空，情况与上述相同
        if (!right) return left;
        //当 left 和 right 同时不为空 ：说明 p,q 分列在 root 的 异侧 （分别在 左 / 右子树），因此 root 为最近公共祖先，返回 root
        return root;
    }
};
