class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();

        // Step 1: Replace invalid numbers with 1
        bool contains1 = false;

        for(int i = 0; i < n; i++) {

            if(nums[i] == 1)
                contains1 = true;

            if(nums[i] <= 0 || nums[i] > n)
                nums[i] = 1;
        }
        if(contains1 == false) return 1;

        // Step 2: Mark presence using indices.  --" using thr concept of index as numbers"
        for(int i = 0; i < n; i++) {

            int num = abs(nums[i]);
            int index = num - 1;

            if(nums[index] > 0)
                nums[index] *= -1;
        }
        for(int i = 0; i < n; i++) {

            if(nums[i] > 0)
                return i + 1;
        }
        return n + 1;
    }
};