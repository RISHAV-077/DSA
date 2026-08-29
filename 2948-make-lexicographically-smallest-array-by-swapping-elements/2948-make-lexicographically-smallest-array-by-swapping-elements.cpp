class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> vec = nums;
        sort(begin(vec), end(vec));

        int grpnum= 0;
        unordered_map<int, int> numtogrp;
        numtogrp[vec[0]] = grpnum;

        unordered_map<int, list<int>> mpp;
        mpp[grpnum].push_back(vec[0]); 

        for(int i = 1; i < n; i++) {
            if(abs(vec[i] - vec[i-1]) > limit) {
                grpnum += 1;
            }

            numtogrp[vec[i]] = grpnum;
            mpp[grpnum].push_back(vec[i]);
        }
        vector<int> result(n);
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            int group = numtogrp[num];
            result[i] = *mpp[group].begin(); ///delete the used one
            mpp[group].pop_front();
        }

        return result;
    }
};