class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int i, int j, vector<int>& piles) {

        // dp-- optimal game strategy
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == j)
            return piles[i];
        // take_not take
        int take_i = piles[i] - solve(i + 1, j, piles);
        int not_take_i = piles[j] - solve(i, j - 1, piles);

        return dp[i][j] = max(take_i, not_take_i);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n, vector<int>(n, -1));

        return solve(0, n - 1, piles) >= 0;
    }
};