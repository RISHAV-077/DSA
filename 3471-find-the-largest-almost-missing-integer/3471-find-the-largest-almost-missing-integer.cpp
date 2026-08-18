class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        // k = 1
        if (k == 1) {
            int ans = -1;

            for (int i = 0; i < n; i++) {
                if (mpp[nums[i]] == 1) {
                    ans = max(ans, nums[i]);
                }
            }

            return ans;
        }

        // k = n
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        int first = nums[0];
        int last = nums[n - 1];

        if (mpp[first] == 1 && mpp[last] == 1) {
            return max(first, last);
        }
        else if (mpp[first] > 1 && mpp[last] == 1) {
            return last;
        }
        else if (mpp[first] == 1 && mpp[last] > 1) {
            return first;
        }
        else {
            return -1;
        }
    }
};