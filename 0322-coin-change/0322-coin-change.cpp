class Solution {
public:
    int dp[10001];
    int recur(vector<int>&nums, int target)
    {
        if(target == 0) return 0;
        if(target < 0) return INT_MAX;
        if(dp[target] != -1) return dp[target];
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++)
        {
            ans = min(ans, recur(nums, target - nums[i]));
        }
        if(ans == INT_MAX) return dp[target] = INT_MAX;
        return dp[target] = ans + 1;
    }
    int coinChange(vector<int>& nums, int amount) {
        memset(dp, -1, sizeof(dp));
        int ans = recur(nums, amount);
        return (ans == INT_MAX ? -1 : ans);
    }
};