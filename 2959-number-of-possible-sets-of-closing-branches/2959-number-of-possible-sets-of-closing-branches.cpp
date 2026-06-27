class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int result = 0;

        //O(2^n * (n^3))
        for(int set = 0; set < (1 << n); set++) { //trying all possible subsets

            vector<vector<int>> grid(n, vector<int>(n, 1e9)); //updated graph

            //Update the Graph based on the selected nodes - present in set
            for(auto &it : roads) {
                int u  = it[0];
                int v  = it[1];
                int wt = it[2];

                //[[1,0,11],[1,0,16],[0,2,13]]
                if((set >> u & 1) && (set >> v & 1)) {
                    grid[u][v] = min(grid[u][v], wt);
                    grid[v][u] = min(grid[v][u], wt);
                }
            }

            for(int i = 0; i<n; i++) {
                grid[i][i] = 0;
            }

            //Floyd Warshall to find shortest distance from any node to any other node
            for(int via = 0; via < n; via++) {
                for(int i = 0; i<n; i++) {
                    for(int j = 0; j<n; j++) {

                       grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);

                    }
                }
            }

            
            //Check if all shortest paths <= maxDistance
            bool ok = true;
            for(int i = 0; i<n; i++) {
                for(int j = 0; j<n; j++) {
                    if(i == j) continue;

                    if((set >> i & 1) && (set >> j & 1)) {
                        if(grid[i][j] > maxDistance) {
                            ok = false;
                            break;
                        }
                    }
                }
            }

            if(ok == true) {
                result++;
            }

        }


        return result;
    }
};

