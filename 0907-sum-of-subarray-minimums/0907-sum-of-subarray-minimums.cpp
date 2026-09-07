class Solution {
public:

    int n;

    vector<int> getnsr(vector<int>& arr) {

        vector<int> nsr(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                nsr[i] = n;
            }
            else {
                nsr[i] = st.top();
            }

            st.push(i);
        }

        return nsr;
    }


    vector<int> getnsl(vector<int>& arr) {

        vector<int> nsl(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                nsl[i] = -1;
            }
            else {
                nsl[i] = st.top();
            }

            st.push(i);
        }

        return nsl;
    }


    int sumSubarrayMins(vector<int>& arr) {

        n = arr.size();

        vector<int> nsr = getnsr(arr);
        vector<int> nsl = getnsl(arr);

        long long sum = 0;
        int MOD = 1e9 + 7;

        for(int i = 0; i < n; i++) {

            long long leftside = i - nsl[i];
            long long rightside = nsr[i] - i;

            long long totalways = leftside * rightside;

            long long totalsumvalue =
                (long long)arr[i] * totalways;

            sum = (sum + totalsumvalue) % MOD;
        }

        return sum;
    }
};