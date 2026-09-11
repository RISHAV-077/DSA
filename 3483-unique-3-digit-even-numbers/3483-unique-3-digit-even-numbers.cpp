class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int>count(10 , 0);
        for(int i=0 ; i< n; i++){
            count[digits[i]]++;
        }
        int cnt=0;
        for(int i= 100 ; i<= 999 ; i++){
            if(i%2 !=0) continue;
            int x = i;
            vector<int>need(10 , 0);
            while(x>0){
                need[x%10]++;
                x =x/10;
            }
            bool flag = true;
            for(int j=0 ; j<10 ; j++){
                if(need[j] > count[j]){
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};