class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < n; i++) {
            int sum = 0;

            for(int j = i; j < n; j++) {
                sum += nums[j];
                pq.push(sum);
            }
        }

        long long ans = 0;
        int MOD = 1e9 + 7;

        // Remove elements before 'left'
        for(int i = 1; i < left; i++) {
            pq.pop();
        }

        // Add elements from left to right
        for(int i = left; i <= right; i++) {
            ans = (ans + pq.top()) % MOD;
            pq.pop();
        }

        return ans;
    }
};