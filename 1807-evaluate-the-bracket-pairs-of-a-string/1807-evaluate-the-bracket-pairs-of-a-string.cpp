class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mpp;

        for (int i = 0; i < knowledge.size(); i++) {
            mpp[knowledge[i][0]] = knowledge[i][1];
        }

        int n = s.length();
        bool open = false;
        string change = "";
        string ans = "";

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (ch == '(') {
                open = true;
                change = "";
            }
            else if (ch == ')') {
                open = false;

                if (mpp.find(change) != mpp.end()) {
                    ans += mpp[change];
                }
                else {
                    ans += "?";
                }

                change = "";
            }
            else if (open == true) {
                change += ch;
            }
            else {
                ans += ch;
            }
        }

        return ans;
    }
};