class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int l, int r, vector<int>& presum) {
        if (l == r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];
        int leftSum = presum[r + 1] - presum[l + 1];
        int rightSum = presum[r] - presum[l];

        int left = leftSum - solve(l + 1, r, presum);
        int right = rightSum - solve(l, r - 1, presum);

        return dp[l][r] = max(left, right);
    }

    int stoneGameVII(vector<int>& stones) {
        n = stones.size();
        vector<int> presum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            presum[i + 1] = presum[i] + stones[i];
        }
        dp.assign(n, vector<int>(n, -1));
        return solve(0, n - 1, presum);
    }
};