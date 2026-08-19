class Solution {
public:
    vector<int> LIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lenlis(n);
        vector<int> sorted;
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(sorted.begin(), sorted.end(), nums[i]);
            if (it == sorted.end()) {
                sorted.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
            lenlis[i] = sorted.size();
        }
        return lenlis;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lisLR = LIS(nums);
        reverse(nums.begin(), nums.end());
        vector<int> lisRL = LIS(nums);
        reverse(lisRL.begin(), lisRL.end());
        int maxmountainsize = 0;
        for (int i = 0; i < n; i++) {
            if (lisLR[i] > 1 && lisRL[i] > 1) {
                maxmountainsize = max(maxmountainsize, lisLR[i] + lisRL[i] - 1);
            }
        }

        return n - maxmountainsize;
    }
};