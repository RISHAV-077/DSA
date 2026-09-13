class Solution {
public:
int n;
int overlap(vector<vector<int>>& img1, vector<vector<int>>& img2 , int row , int col){
    int count=0;
    for(int i=0 ; i< n ; i++){
        for(int j=0 ; j< n ; j++){
            int b_row = i+ row;
            int b_col = col+j;
            if(b_row >=n|| b_row<0 || b_col>=n || b_col<0) continue;
            if(img1[i][j] ==1 && img2[b_row][b_col]==1){
                count++;
            }
        }
    }
    return count;
}
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
         n = img1.size();
        int ans =INT_MIN;
        if(n==1 && img1[0][0] ==1 && img2[0][0]==1) return 1;
        if(n==1) return 0;
        for(int row = -n+1 ; row <n ; row++){
            for(int col = -n+1 ; col <n ; col++){
                ans = max(ans , overlap(img1 , img2 , row , col));
            }
        }
        return ans;
    }
};