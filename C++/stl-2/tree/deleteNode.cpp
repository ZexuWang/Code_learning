/*450. 删除二叉搜索树中的节点
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：

首先找到需要删除的节点；
如果找到了，删除它。
 

示例 1:



输入：root = [5,3,6,2,4,null,7], key = 3
输出：[5,4,6,2,null,null,7]
解释：给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
另一个正确答案是 [5,2,6,null,4,null,7]。


示例 2:

输入: root = [5,3,6,2,4,null,7], key = 0
输出: [5,3,6,2,4,null,7]
解释: 二叉树不包含值为 0 的节点
示例 3:

输入: root = [], key = 0
输出: []
 

提示:

节点数的范围 [0, 104].
-105 <= Node.val <= 105
节点值唯一
root 是合法的二叉搜索树
-105 <= key <= 105*/

/*根据二叉搜索树的性质

如果目标节点大于当前节点值，则去右子树中删除；
如果目标节点小于当前节点值，则去左子树中删除；
如果目标节点就是当前节点，分为以下三种情况：
其无左子：其右子顶替其位置，删除了该节点；
其无右子：其左子顶替其位置，删除了该节点；
其左右子节点都有：其左子树转移到其右子树的最左节点的左子树上，然后右子树顶替其位置，由此删除了该节点。

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }

        if (root->val > key) {
            root->left = deleteNode(root->left, key);// 去右子树删除
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);// 去左子树删除
        } else {
            if (!root->left) {
                return root->right;// 情况1，欲删除节点无左子
            }
            if (!root->right) {
                return root->left;// 情况2，欲删除节点无右子
            }
            TreeNode* node = root->right;// 情况3，欲删除节点左右子都有 
            while (node->left) {
                node = node->left;// 寻找欲删除节点右子树的最左节点
            }
            node->left = root->left;// 将欲删除节点的左子树成为其右子树的最左节点的左子树
            root = root->right;// 欲删除节点的右子顶替其位置，节点被删除
        }
        return root;

    }
};

