class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int dis = roads[i][2];

            adj[u].push_back({v, dis});
            adj[v].push_back({u, dis});
        }

        vector<int> vis(n + 1, 0);

        queue<int> q;
        q.push(1);
        vis[1] = 1;

        int ans = INT_MAX;

        while (!q.empty()) {

            int node = q.front();
            q.pop();
            for (auto &ngbr : adj[node]) {
                ans = min(ans, ngbr.second);
                if (!vis[ngbr.first]) {
                    vis[ngbr.first] = 1;
                    q.push(ngbr.first);
                }
            }
        }

        return ans;
    }
};