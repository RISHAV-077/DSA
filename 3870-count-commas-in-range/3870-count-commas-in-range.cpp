class Solution {
public:
    int countCommas(int n) {
        int count=0;
        if(n<1000) return 0;
        else{
            for(int i=1000 ; i<=n; i++){
                if(i>999999){
                       count+=2;
                }
                count++;
            }
        }
        return count;
    }
};