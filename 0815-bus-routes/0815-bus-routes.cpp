class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {

        if (source == target)
            return 0;

        int n = routes.size();
        unordered_map<int, vector<int>> mpp;
        for (int i = 0; i < n; i++) {
            for (int stop : routes[i]) {
                mpp[stop].push_back(i);
            }
        }

        queue<int> q;
        vector<bool> visited(n, false);
        for (int route : mpp[source]) {
            q.push(route);
            visited[route] = true;
        }

        int buses = 1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int route = q.front();q.pop();
                for (int stop : routes[route]) {
                    if (stop == target)
                        return buses;
                    for (int nextRoute : mpp[stop]) {
                        if (!visited[nextRoute]) {
                            visited[nextRoute] = true;
                            q.push(nextRoute);
                        }
                    }
                }
            }

            buses++;
        }

        return -1;
    }
};