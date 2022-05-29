/*22. 括号生成
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

示例 1：

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
示例 2：

输入：n = 1
输出：["()"]
 

提示：

1 <= n <= 8
*/

class Solution {
public:
    vector<string> res;
    string path;
    vector<string> generateParenthesis(int n) {
        int left = 0, right = 0;
        backtrace(left, right, n);
        return res;
    }
    void backtrace(int left, int right, int n) {
        if (path.size() == 2 * n) {
            res.push_back(path);
            return;
        }
        if (right < left) {
            path.push_back(')');
            backtrace(left, right + 1, n);
            path.pop_back();
        }
        if (left < n) {
            path.push_back('(');
            backtrace(left + 1, right, n);
            path.pop_back();
        }
    }
};
