class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        stack<char> st;
        int count = 0;
        int close=0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                st.push('(');
            else {
                close++;
                if (close == 1) {
                    if (i + 1 > n || s[i + 1] != ')') {
                         count++;
                         close=0;

                    if (!st.empty())st.pop();
                    else count++;
                    }
                }
                else if(close==2){
                    if(!st.empty()) st.pop();
                    else count++;

                    close=0;

                }
            }
        }
        count+= st.size()*2;
        return count;
    }
};