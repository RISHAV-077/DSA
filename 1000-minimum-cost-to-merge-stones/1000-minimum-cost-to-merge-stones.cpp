class Solution {
public:
    vector<vector<int>> dp;
    vector<int> presum;
    int getSum(int i, int j) {
        return presum[j + 1] - presum[i];
    }
    int solve(int i, int j , int k) {
        if (i >= j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mincost = INT_MAX;
        for (int mid = i; mid < j; mid += k - 1) {

            int left = solve(i, mid , k);
            int right = solve(mid + 1, j , k);
            mincost = min(mincost, left + right);
        }

        // If this entire interval can now be
        // merged into ONE pile, pay its total sum.
        if ((j - i) % (k - 1) == 0) {
            mincost += getSum(i, j);
        }
        return dp[i][j] = mincost;
    }

    int mergeStones(vector<int>& stones, int k) {

        int n = stones.size();
        if ((n - 1) % (k - 1) != 0)  return -1;
       presum.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            presum[i + 1] =presum[i] + stones[i];
        }
        dp.assign(n, vector<int>(n, -1));
        return solve(0, n - 1 , k);
    }
};