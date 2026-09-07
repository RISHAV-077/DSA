class Solution {
public:
    vector<int> dp;
    vector<int> prev;

    int M = 1e9 + 7;

    int solve(int n, string& s) {

        if (n == 0) {
            return 1; 
        }
        if (dp[n] != -1)return dp[n];
        long long totalSubseq = (2LL * solve(n - 1, s)) % M;
        if (prev[n] != 0) {
            int duplicates = solve(prev[n] - 1, s);
            totalSubseq = (totalSubseq - duplicates + M) % M;
        }

        return dp[n] = totalSubseq;
    }

    int distinctSubseqII(string s) {

        int n = s.length();

        dp.assign(n + 1, -1);
        prev.assign(n + 1, 0);

        vector<int> lastseen(26, 0);
        for (int i = 1; i <= n; i++) {
            int ele = s[i - 1] - 'a';
            prev[i] = lastseen[ele];
            lastseen[ele] = i;
        }
        int ans = solve(n, s);
        return (ans - 1 + M) % M;
    }
};