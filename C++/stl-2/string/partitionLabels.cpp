/*763. 划分字母区间
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。

 

示例：

输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
 

提示：

S的长度在[1, 500]之间。
S只包含小写字母 'a' 到 'z' 。*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int look_table[26];
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            look_table[s[i] - 'a'] = i;//找到每个字母最后一次出现的下标并记录在look-table中
        }

        int start = 0, end = 0;
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            end = max(end, look_table[s[i] - 'a']);//在表中找到当前字母出现的最后下标

            if (i == end) {//此条件满足代表当前字母位于字符串中最后一个当前字母对应位置，那么可以返回
                res.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return res;
    }
};
