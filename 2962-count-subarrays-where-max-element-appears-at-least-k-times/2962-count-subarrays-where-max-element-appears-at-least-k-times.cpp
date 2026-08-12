class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int maxi = *max_element(nums.begin(), nums.end());
        int countmax = 0;
        int i = 0;
        long long len = 0;

        for (int j = 0; j < n; j++) {
            if (nums[j] == maxi) {
                countmax++;
            }
            while (countmax >= k) {
                if (nums[i] == maxi) {
                    countmax--;
                }
                i++;
            }
            len += i;
        }

        return len;
    }
};