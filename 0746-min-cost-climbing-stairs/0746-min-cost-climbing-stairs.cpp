class Solution {
public:
    int dp[1001];
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
         memset(dp, -1, sizeof(dp));
         dp[0] = 0;
         dp[1] = 0;
         for(int i = 2; i <= n; i++)
         {
            dp[i] = min(cost[i-1] + dp[i-1], cost[i-2] + dp[i-2]);
         }
         return dp[n];
    }
};