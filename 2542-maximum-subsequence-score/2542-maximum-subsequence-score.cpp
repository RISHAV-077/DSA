class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({nums2[i], nums1[i]});
        }

        long long ksum = 0;
        sort(vec.begin(), vec.end(), greater<pair<int, int>>());
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; i++) {
            ksum += vec[i].second;
            pq.push(vec[i].second);
        }

        long long result = ksum * vec[k - 1].first;
        for (int i = k; i < n; i++) {
            // Remove the smallest nums1
            ksum -= pq.top();
            pq.pop();

            // Add current nums1
            ksum += vec[i].second;
            pq.push(vec[i].second);
            result = max(result, ksum * vec[i].first);
        }

        return result;
    }
};