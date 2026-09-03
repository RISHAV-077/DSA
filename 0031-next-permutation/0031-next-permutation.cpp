class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Step 1 — Find the first decreasing element from the end
        int n = nums.size();
        int idx = -1;

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        // If no such element is found, reverse the entire array
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return; // Important to exit here
        }

        // Step 2 — Find the element just greater than nums[idx]
        for (int i = n - 1; i > idx; i--) {
            if (nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]);
                break;
            }
        }

        // Step 3 — Reverse the remaining part after idx
        reverse(nums.begin() + idx + 1, nums.end());
    }
};
