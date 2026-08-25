class Solution {
public:
    vector<vector<int>> dp;

    int solve(int start, int end) {
        if (start >= end) return 0;

        if (dp[start][end] != -1)
            return dp[start][end];

        int ans = INT_MAX;

        for (int i = start; i <= end; i++) {

            int cost = i + max(solve(start, i - 1), solve(i + 1, end) );
            ans = min(ans, cost);
        }

        return dp[start][end] = ans;
    }

    int getMoneyAmount(int n) {
        dp.assign(n + 1, vector<int>(n + 1, -1));

        return solve(1, n);
    }
};