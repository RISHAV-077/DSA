class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int i = 0;
        int count = 0;

        string ans = "";
        int mini = INT_MAX;

        for (int j = 0; j < n; j++) {

            if (s[j] == '1')count++;
            while (count == k) {

                int len = j - i + 1;
                string curr = s.substr(i, len);

                if (len < mini) {
                    mini = len;
                    ans = curr;
                }
                else if (len == mini) {
                    ans = min(ans, curr);
                }
                if (s[i] == '1')count--;
                i++;
            }
        }

        return ans;
    }
};