class Solution {
public:
vector<vector<int>>dp;
    int solve(int l, int r, vector<int>& presum, vector<int>& stoneValue) {
        if (l == r) {
            return 0;
        }
        if(dp[l][r] != -1) return dp[l][r];
        int ans = 0;
        for (int j = l; j < r; j++) {
            int left = presum[j + 1] - presum[l]; // intially presum[l] is 0
            int right = presum[r + 1] - presum[j + 1];  //presum[r+1] beacuse we hac=ve inserted 0 initially

            if (left < right) {
                ans = max(ans, left + solve(l, j, presum, stoneValue));
            }
            else if (right < left) {
                ans = max(ans, right + solve(j + 1, r, presum, stoneValue));
            }
            else {
                ans = max(ans,max(left + solve(l, j, presum, stoneValue),right + solve(j + 1, r, presum, stoneValue)));
            }
        }
        return dp[l][r]=ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n+1 , vector<int>(n+1 , -1));
        vector<int> presum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            presum[i + 1] = presum[i] + stoneValue[i];
        }
        return solve(0, n - 1, presum, stoneValue);
    }
};