class Solution {
public:
    //returns true if "need" exists in the sorted vector
    bool binarySearch(vector<int>& arr, int need) {
        int low = 0, hi = arr.size() - 1;

        while(low <= hi) {
            int mid = low + (hi - low) / 2;
            if(arr[mid] == need)       
                return true;
            else if(arr[mid] < need)  
                low = mid + 1;
            else
                hi = mid - 1;
        }

        return false;
    }

    bool splitArraySameAverage(vector<int>& nums) {
        int N = nums.size();
        int S = accumulate(begin(nums), end(nums), 0);
        int n1 = N/2;      
        int n2 = N - n1;   

        //Key idea: both groups must have average = S/N.
        //So we just need ONE non-empty proper subset A with:
        //   sum(A)/size(A) == S/N   =>   sum(A)*N == size(A)*S

        
        unordered_map<int, vector<int>> sumsLeft;
        for(int mask = 0; mask < (1 << n1); mask++) {
            int s = 0; 
            int count = 0;
            for(int i = 0; i < n1; i++) {
                if(mask & (1 << i)) {
                    s += nums[i];
                    count++;
                }
            }
            sumsLeft[count].push_back(s);
        }
        unordered_map<int, vector<int>> sumsRight;
        for(int mask = 0; mask < (1 << n2); mask++) {
            int s = 0; 
            int count = 0;
            for(int i = 0; i < n2; i++) {
                if(mask & (1 << i)) {
                    s += nums[n1+i];
                    count++;
                }
            }
            sumsRight[count].push_back(s);
        }

        //NOTE : Sorting a bucket of size b costs O(b log b). Time Complexity -  O(2^n · log(2^n)) = O(n · 2^n).
        for(int count = 0; count <= n2; count++) {
            //sumsRight[count] this is my vector of subset sum having subset of size count
            sort(begin(sumsRight[count]), end(sumsRight[count]));
        }

        for(int k = 0; k <= n1; k++) { //how many elements from left
            for(int leftSubSum : sumsLeft[k]) {
                //size is NOT fixed. can pick m elements from right, m is free.
                for(int m = 0; m <= n2; m++) {
                    int size = k + m; //total size of subset
                    if(size == 0 || size == N) continue; //A empty or B empty is not allowed

                    //need : rightSubSum such that (leftSubSum + rightSubSum)*N == size*S
                    //   =>  rightSubSum = size*S/N - leftSubSum
                    if(size * S % N != 0) 
                        continue; //if not integer, no subset sum can match

                    int need = size * S / N - leftSubSum;

                    //exact match check via binary search
                    if(binarySearch(sumsRight[m], need)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
