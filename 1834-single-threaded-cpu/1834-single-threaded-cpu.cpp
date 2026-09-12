class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<vector<int>> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = {tasks[i][0], tasks[i][1], i};
        }
        sort(result.begin(), result.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>pq;

        long long totaltime = 0;
        int i = 0;
        vector<int> ans;

        while (i < n || !pq.empty()) {
            // idle time
            if (pq.empty() && totaltime < result[i][0]) {
                totaltime = result[i][0];
            }

            // add all other times
            while (i < n && result[i][0] <= totaltime) {
                pq.push(
                    {result[i][1], result[i][2]}); // processing time , index
                i++;
            }
            if (!pq.empty()) {
                auto tp = pq.top();
                pq.pop();
                totaltime += tp.first;
                ans.push_back(tp.second);
            }
        }

        return ans;
    }
};