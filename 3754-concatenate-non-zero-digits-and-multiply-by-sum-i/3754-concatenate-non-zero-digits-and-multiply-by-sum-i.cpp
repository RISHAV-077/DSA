class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        string s = to_string(n);
        long long num = 0;

        for (char c : s) {
            if (c != '0') {
                sum += c - '0';
                num = num * 10 + (c - '0');
            }
        }

        return 1LL * sum * num;
    }
};