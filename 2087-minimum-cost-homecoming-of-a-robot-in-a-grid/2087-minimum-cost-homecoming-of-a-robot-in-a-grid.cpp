class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int ans = 0;
        int x = startPos[0], y = startPos[1];
        int homeX = homePos[0], homeY = homePos[1];

        while (x != homeX) {
            x += (homeX > x) ? 1 : -1;
            ans += rowCosts[x];
        }

        while (y != homeY) {
            y += (homeY > y) ? 1 : -1;
            ans += colCosts[y];
        }

        return ans;
    }
};