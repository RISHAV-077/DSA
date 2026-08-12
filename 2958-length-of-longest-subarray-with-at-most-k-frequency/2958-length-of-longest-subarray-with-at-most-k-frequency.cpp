class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0 ; int j=0 ;
        int result =INT_MIN;
        unordered_map<int , int>mpp;
        int culprit=0;
        while(j<n){
            mpp[nums[j]]++;
            if(mpp[nums[j]] == k+1){
                culprit++;
            }
            if(culprit >0){
                mpp[nums[i]]--;
                if(mpp[nums[i]]==k){
                    culprit--;
                }
                i++;
            }
            result = max(result , j-i+1);
            j++;

        }
        return result;
    }
};