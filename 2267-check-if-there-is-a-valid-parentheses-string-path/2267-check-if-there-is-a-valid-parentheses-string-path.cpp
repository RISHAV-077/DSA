class Solution {
public:
    int n, m;
    vector<vector<vector<int>>>dp;
    bool solve(int i, int j, int balance, vector<vector<char>>& grid) {
        if(balance < 0)
            return false;
        if(i == n-1 && j == m-1) {
            int newbalance = balance;
            if(grid[i][j] == '(')
                newbalance++;
            else
                newbalance--;
            return newbalance == 0;
        }
        
        int newbalance = balance;

        if(grid[i][j] == '(')
            newbalance++;
        else
            newbalance--;

        if(newbalance < 0)
            return false;

        bool right = false;
        bool down = false;
        if(dp[i][j][balance] != -1) return dp[i][j][balance];
        if(j + 1 < m)
            right = solve(i, j+1, newbalance, grid);

        if(i + 1 < n)
            down = solve(i+1, j, newbalance, grid);

        return dp[i][j][balance]=(right || down);
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        n = grid.size();
        m = grid[0].size();
        dp.assign(n , vector<vector<int>>(m , vector<int>(n+m , -1)));
        if((n + m - 1) % 2 != 0)
            return false;
        if(grid[0][0] == ')')
            return false;
        return solve(0, 0, 0, grid);
    }
};