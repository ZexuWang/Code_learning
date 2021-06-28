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