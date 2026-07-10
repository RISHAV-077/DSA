class Solution {
public:
    bool ispalindrome(int i, int j, string &s) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        
        // Base case: empty string requires 0 cuts
        dp[n] = 0;
        
        for(int i = n - 1; i >= 0; i--) {
            int mini = INT_MAX;
            
            for(int j = i; j < n; j++) {
                if(ispalindrome(i, j, s)) {
                    int cost = 1 + dp[j + 1];
                    mini = min(mini, cost);
                }
            }
            dp[i] = mini;
        }
        // For "aab": partitions are ["aa","b"] (2 partitions, 1 cut)
        return dp[0] - 1;
    }
};