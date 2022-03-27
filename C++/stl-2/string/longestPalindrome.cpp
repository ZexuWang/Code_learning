/*409. 最长回文串
给定一个包含大写字母和小写字母的字符串 s ，返回 通过这些字母构造成的 最长的回文串 。

在构造过程中，请注意 区分大小写 。比如 "Aa" 不能当做一个回文字符串。

 

示例 1:

输入:s = "abccccdd"
输出:7
解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
示例 2:

输入:s = "a"
输入:1
示例 3:

输入:s = "bb"
输入: 2
 

提示:

1 <= s.length <= 2000
s 只能由小写和/或大写英文字母组成
*/

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map;//key 为字符， val为该字符出现的频率
        int ans = 0;

        for (auto& ch : s) {
            map[ch]++;
        }

         for (auto& count : map) {
             int num = count.second;
             ans += num / 2 * 2;//先对频率取最大偶数，这些字符必定可以组合成为回文字符串
             if (ans % 2 == 0 && num %2 == 1) {//若当前考察的字符频率为基数且当前的总回文数字符串长度为偶数，可以增加当前字符作为中间字符向两侧扩展
                 ans++;
             }
         }
         return ans;
    }
};
