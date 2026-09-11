class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int>store(10 , 0);
        for(int i=0 ; i< n ; i++){
            store[digits[i]]++;
        }
        vector<int>ans;
        for(int i= 100 ; i<=999 ; i++){
            if(i%2 !=0) continue;
            int x = i;
            vector<int>need(10 , 0);
            while(x>0){
                need[x%10]++;
                x=x/10;
            } bool flag = true;
            for(int j=0 ; j<10 ; j++){
                if(need[j] >  store[j]){
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(i);
        }
        return ans;
    }
};