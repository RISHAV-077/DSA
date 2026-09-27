class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> open;
        string result;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open.push(result.size());
            }
            else if (s[i] == ')') {
                int idx = open.top();
                open.pop();
                reverse(result.begin() + idx, result.end());
            }
            else {
                result += s[i];
            }
        }
        return result;
    }
};