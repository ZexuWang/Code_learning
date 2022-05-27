/*844. 比较含退格的字符串
给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，请你判断二者是否相等。# 代表退格字符。

如果相等，返回 true ；否则，返回 false 。

注意：如果对空文本输入退格字符，文本继续为空。

 

示例 1：

输入：s = "ab#c", t = "ad#c"
输出：true
解释：S 和 T 都会变成 “ac”。
示例 2：

输入：s = "ab##", t = "c#d#"
输出：true
解释：s 和 t 都会变成 “”。
示例 3：

输入：s = "a##c", t = "#a#c"
输出：true
解释：s 和 t 都会变成 “c”。
示例 4：

输入：s = "a#c", t = "b"
输出：false
解释：s 会变成 “c”，但 t 仍然是 “b”。
 

提示：

1 <= s.length, t.length <= 200
s 和 t 只含有小写字母以及字符 '#'
 

进阶：

你可以用 O(N) 的时间复杂度和 O(1) 的空间复杂度解决该问题吗？
*/
class Solution {
public:
    // 方法1:直接对比，时间复杂度和空间复杂度都为 o(n)
    bool backspaceCompare(string s, string t) {
        return clear_string(s) == clear_string(t);
    }

    string clear_string(string s) {
        string ret;
        for (auto& ch : s){
            if (ch != '#') {
                ret.push_back(ch);
            } else if (!ret.empty()){
                ret.pop_back();
            }
        }
        return ret;
    }

    // 方法二：双指针
    bool backspaceCompare(string s, string t) {
        int s_idx = s.length() - 1;//记录当前所在的下标位置
        int t_idx = t.length() - 1;
        int skips = 0;//记录#的个数
        int skipt = 0;

        while(s_idx >= 0 || t_idx >= 0) {
            //从s和t的最右侧开始往左滑动两个指针
            while (s_idx >= 0) {
                if(s[s_idx] == '#') {
                    //删除当前的‘#’并记录需要删除的字符个数
                    s_idx--;
                    skips++;
                } else if (skips > 0) {
                    //删除‘#’个数对应的字符个数
                    skips--;
                    s_idx--;
                } else {
                    break;
                }
            }
            while (t_idx >= 0) {
                if(t[t_idx] == '#') {
                    t_idx--;
                    skipt++;
                } else if (skipt > 0) {
                    skipt--;
                    t_idx--;
                } else {
                    break;
                }
            }
            if (s_idx >=0 && t_idx >= 0) {
                if (s[s_idx] != t[t_idx]) {
                    return false;
                }
            } else if (s_idx >= 0 || t_idx >= 0) {
                return false;
            }
        //移动指针
        s_idx--;
        t_idx--;
        }
        return true;
    }
};
