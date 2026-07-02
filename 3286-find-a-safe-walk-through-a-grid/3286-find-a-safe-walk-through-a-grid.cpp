class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        deque<pair<int, int>> dq;

        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));

        ans[0][0] = grid[0][0];

        dq.push_front({0, 0});

        while (!dq.empty()) {

            auto [i, j] = dq.front();
            dq.pop_front();

            for (auto& dir : directions) {

                int ni = i + dir[0];
                int nj = j + dir[1];

                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {

                    if (ans[ni][nj] > ans[i][j] + grid[ni][nj]) {

                        ans[ni][nj] = ans[i][j] + grid[ni][nj];

                        if (grid[ni][nj] == 0)
                            dq.push_front({ni, nj});
                        else
                            dq.push_back({ni, nj});
                    }
                }
            }
        }

        return ans[n - 1][m - 1] < health;
    }
};