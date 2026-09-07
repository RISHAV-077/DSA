class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        stack<pair<int, int>> st;
        st.push({position[n - 1], speed[n - 1]});
        for (int i = n - 2; i >= 0; i--) {

            int left = st.top().first;
            int right = st.top().second;
            if (left - position[i] <= distance || speed[i] > right) {
                st.top().first = position[i];
            }
            else {
                st.push({position[i], speed[i]});
            }
        }

        return st.size();
    }
};