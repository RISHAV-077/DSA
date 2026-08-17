class Solution {
public:
int n;
int solve(vector<int>&presum , int L , int M){
    int result =INT_MIN;
    int maxLsum=INT_MIN;
    for(int Mend = L+M-1; Mend <n ;Mend++){
          int Lend = Mend -M;
          int Lstartprev = Lend-L;
          int Mblocksum = presum[Mend] - presum[Lend];
          int Lblocksum =  presum[Lend] - (Lstartprev <0?0 :presum[Lstartprev]);
          maxLsum = max(maxLsum , Lblocksum);
          result = max(result , maxLsum+ Mblocksum);
    }
    return result;
}
    int maxSumTwoNoOverlap(vector<int>& nums, int L, int M) {
        n = nums.size();
        vector<int>presum(n , 0);
        presum[0]= nums[0];
        for(int i=1 ; i< n ; i++){
            presum[i] =presum[i-1] + nums[i];
        }
        return max(solve(presum , L , M), solve(presum , M , L));
    }
};