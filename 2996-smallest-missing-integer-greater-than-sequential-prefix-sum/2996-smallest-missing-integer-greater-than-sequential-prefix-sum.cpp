class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            mpp[nums[i]] = 1;
        }

        int prefixSum = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                prefixSum += nums[i];
            }
            else {
                break;
            }
        }

        int ans = prefixSum;

        while (mpp.find(ans) != mpp.end()) {
            ans++;
        }

        return ans;
    }
};