class Solution {
public:
void parenthesis(int n, int left , int right , vector<string>& ans , string &temp){

    //base condition
    if(left+right == 2*n){
        ans.push_back(temp);
        return ;
    }
    //for left
    if(left<n){
        temp.push_back('(');
        parenthesis(n,left+1,right,ans,temp);
        temp.pop_back();
    }
    //for right
    if(right<left){
        temp.push_back(')');
        parenthesis(n,left,right+1,ans,temp);
        temp.pop_back();
    }

}
    vector<string> generateParenthesis(int n) {
        int left=0;
        int right=0;
        vector<string> ans;
        string temp;
        parenthesis(n , left , right , ans , temp);

        return ans;
        
    }
};