class Solution {
public:
    int minSwaps(string s) {
        int n = s.length();

        stack<char> st;

        for (char ele : s) {
            if (!st.empty() && st.top() == '[' && ele == ']') {
                st.pop();
            } 
            else {
                st.push(ele);
            }
        }

        int countopen = 0;

        while (!st.empty()) {
            if (st.top() == '[') {
                countopen++;
            }
            st.pop();
        }

        return (countopen + 1) / 2;
    }
};