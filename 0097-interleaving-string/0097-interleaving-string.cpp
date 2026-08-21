class Solution {
public:
    int n, m, N;
    vector<vector<vector<int>>> dp;
    bool solve(int i, int j, int k, string& s1, string& s2, string& s3) {

        if (k == N && i == n && j == m)
            return true;

        if (k == N)
            return false;

        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        bool result = false;

        if (i < n && s1[i] == s3[k])
            result = solve(i + 1, j, k + 1, s1, s2, s3);
        
        if(result == true) return dp[i][j][k]= result;
        if (j < m && s2[j] == s3[k])
            result = solve(i, j + 1, k + 1, s1, s2, s3);

        return dp[i][j][k] = result;
    }

    bool isInterleave(string s1, string s2, string s3) {
        n = s1.length();
        m = s2.length();
        N = s3.length();
        if (n + m != N)
            return false;
        dp.resize(n + 1, vector<vector<int>>(m + 1, vector<int>(N + 1, -1)));
        return solve(0, 0, 0, s1, s2, s3);
    }
};