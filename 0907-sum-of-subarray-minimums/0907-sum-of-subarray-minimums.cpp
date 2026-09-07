class Solution {
public:
    vector<int> getnsl(vector<int>& arr, int n) {
        vector<int> nsl(n);
        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            
            if(st.empty()) {
                nsl[i] = -1; // no smaller element on left
            } else {
                nsl[i] = st.top();
            }
            
            st.push(i);
        }
        return nsl;
    }
    
    vector<int> getnsr(vector<int>& arr, int n) {
        vector<int> nsr(n);
        stack<int> st;
        
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            
            if(st.empty()) {
                nsr[i] = n; // no smaller element on right
            } else {
                nsr[i] = st.top();
            }
            
            st.push(i);
        }
        return nsr;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nsl = getnsl(arr, n);
        vector<int> nsr = getnsr(arr, n);
        
        long long sum = 0;
        int M = 1e9 + 7;
        
        for(int i = 0; i < n; i++) {
            int leftSpan = i - nsl[i];
            int rightSpan = nsr[i] - i;
            
            long long totalWays = (long long)leftSpan * rightSpan;
            long long contribution = (long long)arr[i] * totalWays;
            
            sum = (sum + contribution) % M;
        }
        
        return sum;
    }
};