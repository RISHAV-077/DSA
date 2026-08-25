class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mpp;

        for(int i = 0; i < n; i++) {
            if(nums[i] % k == 0) {
                mpp[nums[i]] = 1;
            }
        }

        for(int i = k; ; i += k) {
            if(mpp.find(i) == mpp.end()) {
                return i;
            }
        }
    }
};