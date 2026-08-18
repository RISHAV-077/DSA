class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        int n = capacity.size();
        vector<pair<int, pair<int, int>>> vec;
        for (int i = 0; i < n; i++) {
            int cap = capacity[i];
            int rock = rocks[i];

            int spaceleft = cap - rock;

            vec.push_back({spaceleft, {cap, rock}});
        }
        sort(vec.begin(), vec.end());
        int count = 0;
        for (int i = 0; i < n; i++) {
            int leftspace = vec[i].first;
            if (additionalRocks == leftspace) {
                count++;
                return count;
            }
            else if (additionalRocks > leftspace) {
                count++;
                additionalRocks -= leftspace;
            }
            else {
                return count;
            }
        }

        return count;
    }
};