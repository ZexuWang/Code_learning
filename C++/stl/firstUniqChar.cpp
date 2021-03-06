/*387. 字符串中的第一个唯一字符
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

 

示例：

s = "leetcode"
返回 0

s = "loveleetcode"
返回 2*/

class Solution {
public:
    int firstUniqChar(string s) {
        int result  = -1;
        int length = s.size();
        std::unordered_map<char, int> map;
        for (char ch : s) {
            ++map[ch];
        }
        for (int i = 0; i < length; ++i) {
            if(map[s[i]] == 1) {
                return i;
                }
        }
    return -1;
    }
};
