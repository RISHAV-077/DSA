class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;

        for (char c : s) {
            if (c == '(')  st.push(0);
             else {
                int curr = 0;
                while (st.top() != 0) {
                    curr += st.top();
                    st.pop();
                }
                st.pop();
                if (curr == 0) curr = 1;
                else curr *= 2;
                st.push(curr);
            }
        }

        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};