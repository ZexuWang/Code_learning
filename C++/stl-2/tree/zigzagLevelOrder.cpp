/*103. 二叉树的锯齿形层序遍历
给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

 

示例 1：


输入：root = [3,9,20,null,null,15,7]
输出：[[3],[20,9],[15,7]]
示例 2：

输入：root = [1]
输出：[[1]]
示例 3：

输入：root = []
输出：[]
 

提示：

树中节点数目在范围 [0, 2000] 内
-100 <= Node.val <= 100*/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }

        std::queue<TreeNode*> node_que;
        node_que.push(root);
        bool left = true;// 用来标记当前遍历顺序

        while(!node_que.empty()) {
            std::deque<int> level_res;//利用双边队列来往队列前或后插入该层元素
            int n = node_que.size();//当前层的所有节点

            for (int i = 0; i < n; ++i) {
                auto node = node_que.front();
                node_que.pop();

                if(left) {//如果从左开始遍历，则从将答案存入deque尾
                    level_res.push_back(node->val);
                } else {
                    level_res.push_front(node->val);
                }

                if (node->left) {
                    node_que.push(node->left);
                }

                if (node->right) {
                    node_que.push(node->right);
                }
            }

            res.emplace_back(vector<int> {level_res.begin(),level_res.end()});//存储答案
            left = !left;
        }
        return res;
    }
};
