class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<int , int>mpp;
        int sum=0;
        mpp[0]=-1;
        for(int i=0 ; i<n ; i++){
            sum+= nums[i];
            mpp[sum]=i;
        }
        int requiredsum = sum-x;
        int total=0;
        int longestsubarr= -1;
        for(int i=0 ; i< n ; i++){
                 total+= nums[i];
                int removedele = total-requiredsum;
                if(mpp.find(removedele) != mpp.end()){
                    int index = mpp[removedele];
                    longestsubarr = max(longestsubarr , i-index);
                }

        }
        if(longestsubarr == -1) return -1;
        return n-longestsubarr;
    }
};