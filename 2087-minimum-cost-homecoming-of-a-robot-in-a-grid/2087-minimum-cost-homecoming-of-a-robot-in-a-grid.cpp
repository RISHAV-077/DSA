class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos,
                vector<int>& rowCosts, vector<int>& colCosts) {

        int n = rowCosts.size();
        int m = colCosts.size();

        int i = startPos[0];
        int j = startPos[1];

        int cost = 0;

        // Move up
        while (i > homePos[0]) {
            i--;
            cost += rowCosts[i];
        }

        // Move down
        while (i < homePos[0]) {
            i++;
            cost += rowCosts[i];
        }

        while (j > homePos[1]) {
            j--;
            cost += colCosts[j];
        }
        while (j < homePos[1]) {
            j++;
            cost += colCosts[j];
        }

        return cost;
    }
};