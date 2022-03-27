/*297. 二叉树的序列化与反序列化
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

 

示例 1：


输入：root = [1,2,3,null,null,4,5]
输出：[1,2,3,null,null,4,5]
示例 2：

输入：root = []
输出：[]
示例 3：

输入：root = [1]
输出：[1]
示例 4：

输入：root = [1,2]
输出：[1,2]
 

提示：

树中结点数在范围 [0, 104] 内
-1000 <= Node.val <= 1000
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "[]";
        queue<TreeNode*> tree;
        tree.push(root);
        string res = "[";
        while(!tree.empty()) {
            TreeNode* cur = tree.front();
            tree.pop();
            if (cur != NULL)
            {
                res += to_string(cur->val);
                res += ",";
                tree.push(cur->left);
                tree.push(cur->right);
            } else res += "null,";
        }
        res += "]";
        return res;
    }

    std::vector<std::string> split(std::string& s, std::string delim)
    {
        std::vector< std::string > ret;
        size_t last = 0;
        size_t index=s.find_first_of(delim,last);
        while (index != std::string::npos)
        {
            ret.push_back(s.substr(last,index-last));
            last=index+1;
            index=s.find_first_of(delim,last);
        }
        if (index-last>0)
        {
            ret.push_back(s.substr(last,index-last));
        }
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="[]") return NULL;
        data.erase(data.begin());
        data.erase(--data.end());
        vector<string> vals = split(data,",");
        TreeNode* root = new TreeNode(atoi(vals[0].c_str()));
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        int i = 1;
        while(!myQueue.empty()) {
            TreeNode* node = myQueue.front();
            myQueue.pop();
            if(vals[i] != "null") {
                node->left = new TreeNode(atoi(vals[i].c_str()));
                myQueue.push(node->left);
            }
            i++;
            if(vals[i] != "null") {
                node->right = new TreeNode(atoi(vals[i].c_str()));
                myQueue.push(node->right);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
