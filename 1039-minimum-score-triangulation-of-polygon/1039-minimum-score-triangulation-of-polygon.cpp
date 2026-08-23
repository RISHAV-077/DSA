class Solution {
public:
    vector<vector<int>> dp;
    int n;

    int solve(vector<int>& values, int i, int j) {
        if (j - i + 1 < 3)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int result = INT_MAX;

        for (int k = i + 1; k < j; k++) {
            int left = solve(values, i, k);
            int right = solve(values, k, j);
            int wt = values[i] * values[j] * values[k] + left + right;

            result = min(result, wt);
        }
        return dp[i][j] = result;
    }
    int minScoreTriangulation(vector<int>& values) {
        n = values.size();

        dp.assign(n, vector<int>(n, -1));

        return solve(values, 0, n - 1);
    }
};