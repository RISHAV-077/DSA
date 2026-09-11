class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        stack<char>st;
        for(int i=0 ; i< n ; i++){
            char ele = s[i];
            if(!st.empty() && st.top()=='(' && ele ==')') st.pop();
            else st.push(ele);
        }
        return st.size();
        
    }
};