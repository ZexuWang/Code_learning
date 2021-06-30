/*
剑指 Offer 13. 机器人的运动范围

地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

 

示例 1：

输入：m = 2, n = 3, k = 1
输出：3
示例 2：

输入：m = 3, n = 1, k = 0
输出：1
*/

// DFS
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n,0));
        return dsf(0, 0, 0, 0, visited, m, n, k);
    }
private:
    int dsf(int i, int j, int si, int sj, vector<vector<bool>> &visited, int m, int n, int k) {
        // i/j is the row/col num of current location, 
        // si/sj is the row/col num sum of current location
        if (i >= m || j >= n || visited[i][j] || k < si + sj) return 0;
        visited[i][j] = true;
        return 1 + dsf(i+1, j, (i + 1)%10 == 0 ? si - 8: si + 1, sj, visited, m, n, k)
                 + dsf(i, j+1, si, (j + 1)%10 == 0 ? sj - 8: sj + 1, visited, m, n, k);

    }
};

// BFS
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n,0));
        int count = 0;
        queue<vector<int>> que;
        que.push({0, 0, 0, 0});
        while(que.size() > 0) {
            vector<int> cur = que.front();
            que.pop();
            int i = cur[0];
            int j = cur[1];
            int si = cur[2];
            int sj = cur[3];
            if (i >= m || j >= n || visited[i][j] || k < si + sj) continue;
            visited[i][j] = true;
            count ++;
            que.push({i + 1, j, (i + 1) % 10 == 0 ? si - 8: si + 1, sj});
            que.push({i, j + 1, si, (j + 1) % 10 == 0 ? sj - 8: sj + 1});
        }
    return count;
    }

};