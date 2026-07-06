class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];  
                 return a[0] < b[0];
             });

        int s1 = intervals[0][0];
        int e1 = intervals[0][1];
        int count = 1;  

        int i = 1;

        while (i < n) {
            int s2 = intervals[i][0];
            int e2 = intervals[i][1];
            if (s2 >= s1 && e2 <= e1) {
                i++;
            }
            else {
                count++;
                s1 = s2;
                e1 = e2;
                i++;
            }
        }

        return count;
    }
};
