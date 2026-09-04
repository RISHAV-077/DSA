class Solution {
public:
    vector<vector<int>> ans;

    void twosum(vector<int>& nums, int tar, int i, int j) {

        while(i < j) {

            if(nums[i] + nums[j] > tar) {
                j--;
            }
            else if(nums[i] + nums[j] < tar) {
                i++;
            }
            else {

                ans.push_back({-tar, nums[i], nums[j]});

                // Skip duplicates
                while(i < j && nums[i] == nums[i + 1])
                    i++;

                while(i < j && nums[j] == nums[j - 1])
                    j--;

                // Move past the current pair
                i++;
                j--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();

        if(n < 3)
            return {};

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 2; i++) {

            if(i > 0 && nums[i - 1] == nums[i])
                continue;

            int n1 = nums[i];
            int target = -n1;

            twosum(nums, target, i + 1, n - 1);
        }

        return ans;
    }
};