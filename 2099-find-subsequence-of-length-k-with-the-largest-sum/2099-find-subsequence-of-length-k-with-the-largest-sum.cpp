class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();


        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<pair<int, int>> selected;

        while (!pq.empty()) {
            selected.push_back(pq.top());
            pq.pop();
        }
        sort(selected.begin(), selected.end(),
             [](pair<int, int>& a, pair<int, int>& b) {
                 return a.second < b.second;
             });

        vector<int> ans;
        for (auto &p : selected) {
            ans.push_back(p.first);
        }

        return ans;
    }
};