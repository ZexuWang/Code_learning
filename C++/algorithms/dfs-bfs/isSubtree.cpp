/*572. 另一棵树的子树
给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在，返回 true ；否则，返回 false 。

二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。

 

示例 1：


输入：root = [3,4,5,1,2], subRoot = [4,1,2]
输出：true
示例 2：


输入：root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
输出：false
 

提示：

root 树上的节点数量范围是 [1, 2000]
subRoot 树上的节点数量范围是 [1, 1000]
-104 <= root.val <= 104
-104 <= subRoot.val <= 104*/

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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot);
    }
    /* dfs 和 final的区别主要在于：
    dfs仍然向深处搜索，即便当前的节点值相同，但仍保留了搜索更深root找到解的能力
    final则为最终判断，即只是以深度优先的方法判断root和subRoot二者完全相同，而不再考虑root的更深层
    两个trick的case可以帮助理解：
    1. [1,1]，[1]。此时dfs从第一个节点开始就满足了值相等的情况，但我们一是判断final二者是否完全相同，二是在dfs中继续向更深的节点查找是否有符合条件的子节点
    2. [3,4,5,1,null,2]，[3,1,2]。如果在1种我们只是单纯地在dfs中修改，即：
    if (root->val == subRoot->val) {
        return (final(root->left, subRoot->left) && final(root->right, subRoot->right))
                || (dfs(root->left,subRoot) || dfs(root->right, subRoot));
        }
    那么对于这个case，就会错误地返回true。原因就是dfs继续在深处找到了相同且同为叶子结点的1， 2 两个节点而忽略了中间节点的不相同；
    因此在最终判断的时候我们引入final判断，即：只关心二者是否相同，而不再向更深处搜索
        */
    bool dfs(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (root && !subRoot) return false;
        if (!root && subRoot) return false;

        if (root->val == subRoot->val) {
            return (final(root->left, subRoot->left) && final(root->right, subRoot->right))
                || (dfs(root->left,subRoot) || dfs(root->right, subRoot));
        }
        return dfs(root->left, subRoot) || dfs(root->right, subRoot);
    }
    bool final (TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (!root && subRoot) return false;
        if (root && !subRoot) return false;

        if (root ->val != subRoot->val) return false;
        return final(root->left, subRoot->left) && final(root->right, subRoot->right);
    }
};
