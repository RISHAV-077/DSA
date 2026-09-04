class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        int n = nums.size();
        int maxele = INT_MIN;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i][0], i, 0});
            maxele = max(maxele, nums[i][0]);
        }

        vector<int> ans = {-1000000, 1000000};

        while (!pq.empty()) {

            auto t = pq.top();pq.pop();
            int ele = t[0];
            int listidx = t[1];
            int idx = t[2];
            if (maxele - ele < ans[1] - ans[0]) {
                ans[0] = ele;
                ans[1] = maxele;
            }
            if (idx + 1 < nums[listidx].size()) {
                int next = nums[listidx][idx + 1];
                maxele = max(maxele, next);
                pq.push({next, listidx, idx + 1});
            } else {
                break;
            }
        }

        return ans;
    }
};