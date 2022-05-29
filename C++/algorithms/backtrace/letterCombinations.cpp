/*17. 电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



 

示例 1：

输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
示例 2：

输入：digits = ""
输出：[]
示例 3：

输入：digits = "2"
输出：["a","b","c"]
 

提示：

0 <= digits.length <= 4
digits[i] 是范围 ['2', '9'] 的一个数字。
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;
        unordered_map<char, string> map = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string path;
        backtrace(digits, map, 0, path, res);
        return res;
    }
    void backtrace(string& digits, unordered_map<char, string> map, int start,
                    string& path, vector<string>& res) {
    if(start == digits.size()) {
        res.push_back(path);
        return;
    }
    string cur_string = map[digits[start]];
    for (auto& ch : cur_string) {
        path.push_back(ch);
        backtrace(digits, map, start + 1, path, res);
        path.pop_back();
    }
    }
};
