/*290. 单词规律
给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

 

示例1:

输入: pattern = "abba", str = "dog cat cat dog"
输出: true
示例 2:

输入:pattern = "abba", str = "dog cat cat fish"
输出: false
示例 3:

输入: pattern = "aaaa", str = "dog cat cat dog"
输出: false
 

提示:

1 <= pattern.length <= 300
pattern 只包含小写英文字母
1 <= s.length <= 3000
s 只包含小写英文字母和 ' '
s 不包含 任何前导或尾随对空格
s 中每个单词都被 单个空格 分隔*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
	
	//将代表不同单词的字符串转换成每个元素代表一个单词的字符串向量
        for (auto& ch: s) {
            if (ch != ' ') {
                word.push_back(ch);
            } else {
                words.push_back(word);
                word = {};
            }
        }
        words.push_back(word);
        // cout<< pattern.size();
	// 如果patter的大小和单词个数不相等，则不正确
        if (words.size() != pattern.size()) {
            return false;
        }

        unordered_map<string, char> map_str;// key为单词，val为对应的patter
        unordered_map<char, string> map_char;//key为pattern， val为对应的单词
        for (int i = 0; i < words.size(); ++i) {
            if (map_str.count(words[i]) && map_str[words[i]] != pattern[i]) {//在哈希表中可以找到words[i]的前提下，这个words[i]和pattern[i]不匹配
                return false;
            }
            if (map_char.count(pattern[i]) && map_char[pattern[i]] != words[i]) {//在哈希表中可以找到pattern[i]的前提下，这个pattern[i]和words[i]不匹配

                return false;
            }
	    /*匹配当前的pattern和word*/
            map_str[words[i]] = pattern[i];
            map_char[pattern[i]] = words[i];
        }
         return true;
    }
};
