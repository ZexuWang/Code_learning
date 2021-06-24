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

/*
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
*/