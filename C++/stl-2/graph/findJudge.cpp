/*997. 找到小镇的法官
小镇里有 n 个人，按从 1 到 n 的顺序编号。传言称，这些人中有一个暗地里是小镇法官。

如果小镇法官真的存在，那么：

小镇法官不会信任任何人。
每个人（除了小镇法官）都信任这位小镇法官。
只有一个人同时满足属性 1 和属性 2 。
给你一个数组 trust ，其中 trust[i] = [ai, bi] 表示编号为 ai 的人信任编号为 bi 的人。

如果小镇法官存在并且可以确定他的身份，请返回该法官的编号；否则，返回 -1 。

 

示例 1：

输入：n = 2, trust = [[1,2]]
输出：2
示例 2：

输入：n = 3, trust = [[1,3],[2,3]]
输出：3
示例 3：

输入：n = 3, trust = [[1,3],[2,3],[3,1]]
输出：-1
 
提示：

1 <= n <= 1000
0 <= trust.length <= 104
trust[i].length == 2
trust 中的所有trust[i] = [ai, bi] 互不相同
ai != bi
1 <= ai, bi <= n*/

class Solution {
public:
/*
题干描述了一个有向图。每个人是图的节点，trust 的元素trust[i] 是图的有向边，从trust[i][0] 指向trust[i][1]。我们可以遍历 trust，统计每个节点的入度和出度，存储在 inDegrees 和 outDegrees 中。

根据题意，在法官存在的情况下，法官不相信任何人，每个人（除了法官外）都信任法官，且只有一名法官。因此法官这个节点的入度是 n−1, 出度是 0。

我们可以遍历每个节点的入度和出度，如果找到一个符合条件的节点，由于题目保证只有一个法官，我们可以直接返回结果；如果不存在符合条件的点，则返回 -1。
*/
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusting(n + 1);
        vector<int> be_trusted(n + 1);
        for (auto& person : trust) {
            int x = person[0];
            int y = person[1];
            be_trusted[y]++;//给被信任的人增加计数
            trusting[x]++;//给信任的人增加计数
        }

        for (int i = 1; i <= n; ++i) {
            if (trusting[i] == 0 && be_trusted[i] == n - 1){
                return i;
            }
        }
        return -1;
    }
};
