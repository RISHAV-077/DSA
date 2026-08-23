class Solution {
public:
    vector<vector<int>> dp;

    int maxval(vector<int>& arr, int st, int end) {
        int maxval = INT_MIN;
        for(int i = st; i <= end; i++) {
            maxval = max(maxval, arr[i]);
        }
        return maxval;
    }

    int solve(vector<int>& arr, int i, int j) {
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int result = INT_MAX;
        for(int k = i; k < j; k++) {
            int leftsubtree = solve(arr, i, k);
            int rightsubtree = solve(arr, k + 1, j);
            int wt = maxval(arr, i, k) * maxval(arr, k + 1, j) + leftsubtree  + rightsubtree;
            result = min(result, wt);
        }

        return dp[i][j] = result;
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        dp.assign(n, vector<int>(n, -1));
        return solve(arr, 0, n - 1);
    }
};