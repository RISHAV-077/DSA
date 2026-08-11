class Solution {
public:
    int n;
    int dp[101][101][2];

    int solve(int AB, int i, int M, vector<int>& piles) {
        if (i >= n)
            return 0;
        if (dp[i][M][AB] != -1)
            return dp[i][M][AB];

        int result;
        if (AB == 1)
            result = INT_MIN; 
        else
            result = INT_MAX; 
        int stones = 0;
        for (int x = 1; x <= min(2 * M, n - i); x++) {
            stones += piles[i + x - 1];
            if (AB == 1) {
                result = max(result, stones + solve(0, i + x, max(M, x), piles));
            } else {

                result = min(result, solve(1, i + x, max(M, x), piles));
            }
        }

        return dp[i][M][AB] = result;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp, -1, sizeof(dp));
        return solve(1, 0, 1, piles);
    }
};