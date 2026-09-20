class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int ans=0;
        for(int i=1 ; i<=n ; i++){
            ans += ( i *(26-(s[i-1]-'a')));
        }
        return ans;
        
    }
};