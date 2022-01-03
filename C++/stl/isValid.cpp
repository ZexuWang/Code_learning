/*20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
 

示例 1：

输入：s = "()"
输出：true
示例 2：

输入：s = "()[]{}"
输出：true
示例 3：

输入：s = "(]"
输出：false
示例 4：

输入：s = "([)]"
输出：false
示例 5：

输入：s = "{[]}"
输出：true
 

提示：

1 <= s.length <= 104
s 仅由括号 '()[]{}' 组成*/

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2) {
            return false;
        }
        unordered_map<char, char> map = {
            {')' , '('},
            {']' , '['},
            {'}' , '{'}
        };// 注意 key-value 的顺序为key为结束， value为开始

        stack<char> cur_char;
        for (auto ch : s) {
            if (map.count(ch)) {
                if (cur_char.empty() || cur_char.top() != map[ch]) {
                    return false;
                }
                cur_char.pop();
            } else {
                cur_char.push(ch);
            }
        }
        return cur_char.empty();

    }
};
