/*5. 最长回文子串
给你一个字符串 s，找到 s 中最长的回文子串。

 

示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：

输入：s = "cbbd"
输出："bb"
 

提示：

1 <= s.length <= 1000
s 仅由数字和英文字母组成
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int max_len = 0, left_max = 0;
        int center = 2 * n - 1;
        /*以单数为中心的扩展方式有n种，以双数为中心的扩展方式有n-1种，因此所有的中心数为 2n-1*/

        for (int i = 0; i < center; ++i) {
	    //找到扩展的左右边界。
	    //如果以单数为中心，则左边界为该单数的左侧，右边界为该单数的右侧，在此情形下，我们以i为偶数作为单数扩展的条件，则此时的左右边界恰好就是这个单数本身
	    //如果以双数为中心，我们以i为奇数作为双数衷心的扩展条件，则此时的左边界为双数的左侧数字，右边界为双数的右侧数字
            int left = i / 2;
            int right = left + i % 2;

            while (left >= 0 && right < n && s[left] == s[right]) {
                int len = right - left + 1;
                if (len > max_len) {
                    max_len = len;
                    left_max = left;
                }
                left--;
                right++;
            }
        }
    return s.substr(left_max, max_len);
    }
};
