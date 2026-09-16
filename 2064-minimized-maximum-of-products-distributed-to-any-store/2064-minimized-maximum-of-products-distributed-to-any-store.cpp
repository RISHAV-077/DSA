class Solution {
public: 

    bool ispossible(int mid, vector<int>& quantities, int n) {
        for (int& prod : quantities) {
            n -= (prod + mid - 1) / mid;

            if (n < 0)
                return false;
        }

        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {

        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());

        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (ispossible(mid, quantities, n)) {
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