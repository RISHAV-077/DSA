class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();

        int smallIndex = 0;
        int largeIndex = 0;

        for (int i = 1; i < n; i++) {

            if (nums[i] < nums[smallIndex])
                smallIndex = i;

            if (nums[i] > nums[largeIndex])
                largeIndex = i;
        }
        if (smallIndex > largeIndex)
            swap(smallIndex, largeIndex);

        int bothLeft = largeIndex + 1;

        int bothRight = n - smallIndex;

        int oneEachSide =
            (smallIndex + 1) + (n - largeIndex);

        return min({
            bothLeft,
            bothRight,
            oneEachSide
        });
    }
};