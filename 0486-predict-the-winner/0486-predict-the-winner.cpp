class Solution {
public:
int solve(int i , int j , vector<int>&nums){
    if(i>j) return 0;
    if(i == j) return nums[i];

    //take not take concept
    int take_i = nums[i] + min(solve(i+2 , j , nums) , solve(i+1 , j-1 , nums));
    int take_j = nums[j] + min(solve(i , j-2 ,nums) , solve(i+1 , j-1 , nums));

    return max(take_i , take_j);
}
    bool predictTheWinner(vector<int>& nums) {
        //dp-- optimal game strategy
        int n = nums.size();
        int totalsum = accumulate(nums.begin() , nums.end(),0);
        int player1 = solve(0 , n-1 , nums);
        int player2 = totalsum - player1;
        return player1>= player2;
        
    }
};