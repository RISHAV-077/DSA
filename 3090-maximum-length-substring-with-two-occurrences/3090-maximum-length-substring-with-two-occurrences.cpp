class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int i = 0;
        int len = 0;
        unordered_map<char, int> mpp;
        for (int j = 0; j < n; j++) {
            mpp[s[j]]++;
            while (mpp[s[j]] > 2) {
                mpp[s[i]]--;
                i++;
            }
            len = max(len, j - i + 1);
        }

        return len;
    }
};