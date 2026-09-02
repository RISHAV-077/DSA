class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int even = 0, odd = 0;

        for (int x : nums1) {
            if (x % 2 == 0) even++;
            else odd++;
        }
        if(nums1.size()==1) return true;
        if (even > 0 && odd > 0) return true;
        if (even >= 2 || odd >= 2) return true;

        return false;
    }
};