class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> presum(n);
        vector<int> sufsum(n);

        presum[0] = nums[0];
        sufsum[n - 1] = nums[n - 1];

        for(int i = 1; i < n; i++) {
            presum[i] = presum[i - 1] * nums[i];
        }

        for(int i = n - 2; i >= 0; i--) {
            sufsum[i] = sufsum[i + 1] * nums[i];
        }

        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            int left = 1;
            int right = 1;
            if(i > 0)
                left = presum[i - 1];

            if(i < n - 1)
                right = sufsum[i + 1];

            ans[i] = left * right;
        }

        return ans;
    }
};