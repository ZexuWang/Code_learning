/*797. 所有可能的路径
给你一个有 n 个节点的 有向无环图（DAG），请你找出所有从节点 0 到节点 n-1 的路径并输出（不要求按特定顺序）

 graph[i] 是一个从节点 i 可以访问的所有节点的列表（即从节点 i 到节点 graph[i][j]存在一条有向边）。

 

示例 1：



输入：graph = [[1,2],[3],[3],[]]
输出：[[0,1,3],[0,2,3]]
解释：有两条路径 0 -> 1 -> 3 和 0 -> 2 -> 3
示例 2：



输入：graph = [[4,3,1],[3,2,4],[3],[4],[]]
输出：[[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
 

提示：

n == graph.length
2 <= n <= 15
0 <= graph[i][j] < n
graph[i][j] != i（即不存在自环）
graph[i] 中的所有元素 互不相同
保证输入为 有向无环图（DAG）
 */

class Solution {
public:
    // 方法1:dfs
    vector<vector<int>> ret;//返回值：所有可行路径的集合
    vector<int> res;//形成最终解答的每一条可行路径
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        res.push_back(0);//初始路径永远是0位置，因此先压入0位置
        dfs(0, graph);//深度优先搜索
        return ret;
    }
    void dfs(int i, vector<vector<int>>& graph) {
        int n = graph.size() - 1;//最终达到终点的下标
        if (i == n) {
            ret.push_back(res);//达到终点，则将当前的res压入ret中
            return;
        }
        for (auto& j : graph[i]) {
            res.push_back(j);//将当前节点能到达的所有的节点一次压入res中
            dfs(j, graph);//如果可以满足条件，则该res会被存入ret中
            res.pop_back();//否则在每次返回时，删除res，只保留前一个位置的节点继续深度搜索
        }
        return;
    }
};

//方法2: 广度优先搜索
/*由于需要记录路径，因此在bfs中需要建立一个search node的结构体来帮助我们作回溯*/
class Solution {
public:
    class searchNode {
        public:
        int cur_idx;//当前的下标
        vector<int> path;//当前的path，已经包含单前的下标
        // 两种构造方式，第一种用以初始化搜索节点，后一种用来拼接搜索节点形成path
        searchNode(int idx) :cur_idx(idx) {
            // vector<int> path;
            this->path.push_back(cur_idx);
        }
        searchNode(int idx, vector<int> vec) : cur_idx(idx) {
            this->path = vec;
            this->path.push_back(cur_idx);
        }
    };
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size() - 1;
        vector<vector<int>> ret;
        std::queue<searchNode> Q;//包含所有searchNode的队列
        Q.push(searchNode(0));//0点永远在先
        while (!Q.empty()) {
            auto cur_node = Q.front();
            Q.pop();
            int cur_idx = cur_node.cur_idx;
            if (cur_idx == n) {//已经找到最终的点
                ret.push_back(cur_node.path);//将记录的成功的路径压入ret中
                continue;
            }
            for (auto& idx : graph[cur_idx]) {
                Q.push(searchNode(idx, cur_node.path));//将当前节点可到达的所有节点构造为searchNode加入队列中
            }
        }
    return ret;
    }
};
