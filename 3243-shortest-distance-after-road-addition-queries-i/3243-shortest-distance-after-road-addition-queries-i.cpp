class Solution {
public:
    unordered_map<int, vector<int>> adj;

    int bfs(int n) {

        queue<int> q;

        vector<bool> vis(n, false);
        vector<int> dist(n, -1);

        q.push(0);
        vis[0] = true;
        dist[0] = 0;

        while (!q.empty()) {

            int top = q.front();
            q.pop();

            for (auto& nei : adj[top]) {

                if (!vis[nei]) {

                    q.push(nei);
                    vis[nei] = true;
                    dist[nei] = dist[top] + 1;
                }
            }
        }

        return dist[n - 1];
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {

        int m = queries.size();
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }

        vector<int> ans;

        for (int i = 0; i < m; i++) {

            int u = queries[i][0];
            int v = queries[i][1];
            adj[u].push_back(v);
            ans.push_back(bfs(n));
        }

        return ans;
    }
};