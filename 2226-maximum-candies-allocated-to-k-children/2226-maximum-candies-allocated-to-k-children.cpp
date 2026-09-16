class Solution {
public:

    int n;
    bool ispossible(int mid, vector<int>& candies, long long k) {
        long long count = 0;
        for(int i = 0; i < n; i++) {
            count += candies[i] / mid;
            if(count >= k)
                return true;
        }

        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {

        n = candies.size();
        int low = 1;
        int high = *max_element(candies.begin(), candies.end());
        int result = 0;
        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(ispossible(mid, candies, k)) {
                result = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return result;
    }
};