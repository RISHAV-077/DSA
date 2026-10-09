class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        // from left to right
        int close=0;
        int open=0;
        int maxlen = INT_MIN;
        for(int i=0 ; i< n ; i++){
            if(s[i]=='(') open++;
            else{
                close++;
            }
            if(open == close) maxlen=max(maxlen , close);
            if(close> open){
                //reset
                close=0;
                open=0;
            }
        }
        open=0;
        close=0;
        for(int i=n-1 ; i>=0 ;i--){
            if(s[i]=='(')open++;
            else close++;
            if(open == close) maxlen = max(maxlen , close);
            if(open > close){
                open=0;
                close=0;
            }
        }
        return (long long)maxlen*2;
    }
};