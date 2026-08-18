class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();

        //patience sorting more optimal then the bootom up lis
        map<int, long long> mp;

        long long ans = INT_MIN;
        
        for(int i = 0; i < n; i++){
            auto it = mp.upper_bound(nums[i]-i); //Find the element just greater than nums[i]-i;

            long long cur_ans = nums[i];

            if(it != mp.begin()) {
                it--;
                cur_ans += (*it).second;
            }
            mp[nums[i]-i] = max(mp[nums[i]-i], cur_ans);

            it = mp.upper_bound(nums[i]-i);

            while(it != mp.end() && (*it).second <= cur_ans) {
                 mp.erase(it++);
            }

            ans = max(ans, cur_ans);
        }

        return ans;
    }
};


// lass Solution {
// public:
//     long long maxBalancedSubsequenceSum(vector<int>& nums) {
//         int n = nums.size();
        
//         int maxEl = *max_element(begin(nums), end(nums));
//         if(maxEl <= 0) {
//             return maxEl;
//         }

//         vector<long long> t(n);
//         for(int i = 0; i<n; i++) {
//             t[i] = nums[i];
//         }

//         long long maxSum = INT_MIN;
//         for(int i = 0; i<n; i++) {

//             for(int j = 0; j<i; j++) {

//                 if(nums[i] - i >= nums[j] - j) {
//                     t[i] = max<long long>(t[i], t[j] + nums[i]);
//                     maxSum = max<long long>(maxSum, t[i]);
//                 }

//             }
//         }

//         return maxSum > maxEl ? maxSum : maxEl;
//     }
// };