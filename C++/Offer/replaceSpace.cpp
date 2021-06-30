/*
剑指 Offer 05. 替换空格
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
*/

/*
输入：s = "We are happy."
输出："We%20are%20happy."
*/

class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for (auto& s_element : s){
            if (s_element == ' ') {
                res.push_back('%');
                res.push_back('2');
                res.push_back('0');
            }else {
                res.push_back(s_element);
            }
        }
        return res;
    }
};