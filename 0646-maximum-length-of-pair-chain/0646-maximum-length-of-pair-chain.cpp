class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int i, int prev, vector<vector<int>>& pairs) {
        if (i >= n)
            return 0;
        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
        int not_take = solve(i + 1, prev, pairs);
        int take = 0;
        if (prev == -1 || pairs[prev][1] < pairs[i][0]) {
            take = 1 + solve(i + 1, i, pairs);
        }
        return dp[i][prev + 1] = max(take, not_take);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        dp.assign(n, vector<int>(n + 1, -1));
        sort(pairs.begin(), pairs.end());
        return solve(0, -1, pairs);
    }
};