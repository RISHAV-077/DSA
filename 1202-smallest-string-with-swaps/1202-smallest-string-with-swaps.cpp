class Solution {
public:
    class DSU {
    public:
        vector<int> parent, sz;

        DSU(int n) {
            parent.resize(n);
            sz.assign(n, 1);

            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int x) {
            if (parent[x] == x)
                return x;

            return parent[x] = find(parent[x]);
        }

        void unite(int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b)
                return;

            if (sz[a] < sz[b])
                swap(a, b);

            parent[b] = a;
            sz[a] += sz[b];
        }
    };

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {

        int n = s.size();

        DSU dsu(n);

        // Build connected components
        for (auto &edge : pairs)
            dsu.unite(edge[0], edge[1]);

        unordered_map<int, vector<int>> comp;

        // Group indices by component
        for (int i = 0; i < n; i++)
            comp[dsu.find(i)].push_back(i);

        // Rearrange characters within each component
        for (auto &it : comp) {

            vector<int> &indices = it.second;
            vector<char> chars;

            for (int idx : indices)
                chars.push_back(s[idx]);

            sort(indices.begin(), indices.end());
            sort(chars.begin(), chars.end());

            for (int i = 0; i < indices.size(); i++)
                s[indices[i]] = chars[i];
        }

        return s;
    }
};