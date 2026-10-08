class Solution {
public:

    static bool comp(string a, string b) {
        if (a + b > b + a)
            return true;
        else
            return false;
    }

    string largestNumber(vector<int>& nums) {
        int n = nums.size();

        vector<string> m;

        for (int i = 0; i < n; i++) {
            m.push_back(to_string(nums[i]));
        }

        sort(m.begin(), m.end(), comp);

        string ans = "";

        for (int i = 0; i < n; i++) {
            ans += m[i];
        }

        if (ans[0] == '0')
            return "0";

        return ans;
    }
};