class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int mineven = INT_MAX;
        int minodd = INT_MAX;
        for (auto num : nums1) {
            if (num % 2 == 0) {
                mineven = min(mineven, num);
            } else
                minodd = min(minodd, num);
        }
        // even
        bool flag1 = 1;
        for (auto num : nums1) {
            if (num % 2 == 0) {
                continue;
            } else {
                if (num - minodd >= 1)
                    continue;
                else {
                    flag1 = false;
                    break;
                }
            }
        }
        // odd
        bool flag2 = 1;
        for (auto num : nums1) {
            if (num % 2 != 0) {
                continue;
            } else {
                if (num - minodd >= 1)
                    continue;
                else {
                    flag2 = 0;
                    break;
                }
            }
        }

        if (flag1 || flag2)
            return 1;
        return 0;
    }
};