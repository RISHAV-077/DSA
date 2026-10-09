class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        if(n==1) return "";
        if(n==2 && palindrome[0] =='a') return "ab";
        int i=0;
        int j= n-1;
        bool flag = true;
        while(i<j){
            if(palindrome[i]=='a' && palindrome[j] =='a'){
                i++;
                j--;
                flag=true;
            }
            else{
                flag = false;
                break;
            }
        } 
        if(flag == true){
            palindrome[n-1] ='b';
            return palindrome;
        }
        // all other cases
        for(int i=0 ; i< n ; i++){
            if(palindrome[i] =='a') continue;
            else{
                palindrome[i] ='a';
                break;
            }
        }
        return palindrome;
    }
};