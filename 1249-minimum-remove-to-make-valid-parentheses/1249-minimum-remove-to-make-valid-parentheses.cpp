class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        unordered_set<int>removedindex;
        stack<int>st;
        for(int i=0 ; i< n ; i++){
            char ele = s[i];
            if(ele == '(') st.push(i);
            else if( ele == ')'){
                if(st.empty()) removedindex.insert(i);
                else st.pop();
            }
        }
        //adding other elements left in stack
        while(!st.empty()){
            removedindex.insert(st.top());
            st.pop();
        }
        //deleting the elements
        string ans="";
        for(int i=0 ; i< n ; i++){
            if(removedindex.find(i) ==  removedindex.end()) ans.push_back(s[i]);
        }
        return ans;
    }
};