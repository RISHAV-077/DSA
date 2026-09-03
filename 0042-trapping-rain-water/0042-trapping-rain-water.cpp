class Solution {
public:
    vector<int> prefixMax(vector<int>& arr) {
        int n = arr.size();
        vector<int> preMax(n);
        preMax[0] = arr[0];
        for (int i = 1; i < n; i++) {
            preMax[i] = max(preMax[i-1], arr[i]);
        }
        return preMax;
    }
    
    vector<int> suffixMax(vector<int>& arr) {
        int n = arr.size();
        vector<int> sufMax(n);
        sufMax[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; i--) {
            sufMax[i] = max(sufMax[i+1], arr[i]);
        }
        return sufMax;
    }
    
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        
        vector<int> premax = prefixMax(height);
        vector<int> sufmax = suffixMax(height);
        
        int total= 0;
        for (int i = 0; i < n; i++) {
            
            total += min(premax[i], sufmax[i]) - height[i];
        }
        
        return total;
    }
};