class Solution {
public:
    int dp[367];
    int recur(int day, vector<int>&days, vector<int>&costs)
    {
        if(day >= days.size())
        {
            return 0;
        }
        if(dp[day] != -1) return dp[day];
        int cost = INT_MAX;
        cost = min(cost, costs[0] + recur(day + 1, days, costs));
        int seven = lower_bound(days.begin(), days.end(), days[day] + 7) - days.begin();
        int thirty = lower_bound(days.begin(), days.end(), days[day] + 30) - days.begin();
        cost = min(cost, costs[1] + recur(seven, days, costs));
        cost = min(cost, costs[2] + recur(thirty, days, costs));
        return dp[day] = cost;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        return recur(0, days, costs);
    }
};