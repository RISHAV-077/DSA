class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, int node, int target, vector<int>& path, vector<vector<int>>& result) {

        if (node == target) {
            result.push_back(path);
            return;
        }
        for (int next : adj[node]) {

            path.push_back(next);
            dfs(adj, next, target, path, result);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        int n = graph.size();

        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++) {
            for (int node : graph[i]) {
                adj[i].push_back(node);
            }
        }

        vector<vector<int>> result;
        vector<int> path;
        path.push_back(0);
        dfs(adj, 0, n - 1, path, result);
        return result;
    }
};