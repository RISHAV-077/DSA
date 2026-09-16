class Solution {
public:

    bool ispossible(int mid, vector<int>& nums, int maxops) {
        for (int &n : nums) {
            int ops = (n - 1) / mid;
            if (ops > maxops)
                return false;

            maxops -= ops;
        }

        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        int result = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (ispossible(mid, nums, maxOperations)) {
                result = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return result;
    }
};