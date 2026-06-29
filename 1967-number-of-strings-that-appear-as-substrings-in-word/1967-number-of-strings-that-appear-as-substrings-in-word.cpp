class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            string s = patterns[i];
            bool flag = false;

            for (int i = 0; i + s.length() <= word.length(); i++) {
                int w = 0;
                while (w < s.length() && word[i + w] == s[w]) {
                    w++;
                }
                if (w == s.length()) {
                    flag = true;
                    break;
                }
            }

            if (flag)
                count++;
        }

        return count;
    }
};