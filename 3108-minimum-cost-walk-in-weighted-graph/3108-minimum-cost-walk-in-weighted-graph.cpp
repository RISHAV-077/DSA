class Solution {
public:

    class UnionFind {
    private:
        vector<int> parent;
        vector<int> size;
        vector<int> rank;
        vector<int> cost;

    public:

        UnionFind(int n) {
            parent.resize(n);
            size.resize(n, 1);
            rank.resize(n, 0);
            cost.resize(n, -1);

            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] != x)
                return parent[x] = find(parent[x]);

            return x;
        }

        int Union(int x, int y) {
            int p_x = find(x);
            int p_y = find(y);

            if (p_x == p_y)
                return p_x;

            if (rank[p_x] > rank[p_y]) {
                parent[p_y] = p_x;
                size[p_x] += size[p_y];
                cost[p_x] &= cost[p_y];   // and operation 

                return p_x;
            }

            else if (rank[p_y] > rank[p_x]) {
                parent[p_x] = p_y;
                size[p_y] += size[p_x];
                cost[p_y] &= cost[p_x];

                return p_y;
            }

            else {
                parent[p_x] = p_y;
                size[p_y] += size[p_x];
                rank[p_y]++;
                cost[p_y] &= cost[p_x];

                return p_y;
            }
        }

        void addCost(int x, int w) {
            int px = find(x);
            cost[px] &= w;
        }

        int getCost(int x) {
            int px = find(x);
            return cost[px];
        }
    };


    vector<int> minimumCost(
        int n,
        vector<vector<int>>& edges,
        vector<vector<int>>& query
    ) {

        UnionFind uf(n);
       for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            int parent_u = uf.find(u);
            int parent_v = uf.find(v);

            if (parent_u != parent_v) {
                int newParent = uf.Union(parent_u, parent_v);
                uf.addCost(newParent, w);
            }
            else {
                uf.addCost(parent_u, w);
            }
        }

        vector<int> res;

        for (auto &q : query) {

            int s = q[0];
            int t = q[1];

            int p1 = uf.find(s);
            int p2 = uf.find(t);

            if (s == t) {
                res.push_back(0);
            }

            else if (p1 != p2) {
                res.push_back(-1);
            }

            else {
                res.push_back(uf.getCost(s));
            }
        }

        return res;
    }
};