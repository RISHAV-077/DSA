class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
  // dp + patience sorting
        sort(envelopes.begin(), envelopes.end(),
             [](vector<int>& e1, vector<int>& e2) {
                 if (e1[0] == e2[0])
                     return e1[1] > e2[1];

                 return e1[0] < e2[0];
             });

        vector<int> lis;
        for (int i = 0; i < envelopes.size(); i++) {
            int h = envelopes[i][1];
            auto it = lower_bound(lis.begin(), lis.end(), h);
            if (it == lis.end())
                lis.push_back(h);
            else
                *it = h;
        }
        return lis.size();
    }
};