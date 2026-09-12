class Solution {
public:
    typedef pair<int, pair<int, int>> pp;

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();

        priority_queue<pp, vector<pp>, greater<pp>> pq;
        vector<vector<int>> ans;
        set<pair<int,int>> visited;
        pq.push({nums1[0] + nums2[0], {0, 0}});
        visited.insert({0, 0});

        while(k-- && !pq.empty()) {
            pp top = pq.top();
            pq.pop();

            int u = top.second.first;
            int v = top.second.second;

            ans.push_back({nums1[u], nums2[v]});
            if(u + 1 < n && visited.find({u + 1, v}) == visited.end()) {
                pq.push({nums1[u + 1] + nums2[v], {u + 1, v}});
                visited.insert({u + 1, v});
            }
            if(v + 1 < m && visited.find({u, v + 1}) == visited.end()) {
                pq.push({nums1[u] + nums2[v + 1], {u, v + 1}});
                visited.insert({u, v + 1});
            }
        }

        return ans;
    }
};