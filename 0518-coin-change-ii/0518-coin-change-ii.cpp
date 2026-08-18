class Solution {
public:
    int dp[301][5001];
    int recur(int i, int target, vector<int>&nums)
    {
        if(target == 0) return 1;
        if(target < 0) return 0;
        if(i >= nums.size()) return 0;
        if(dp[i][target] != -1) return dp[i][target];
        return dp[i][target] = recur(i, target - nums[i], nums) + recur(i + 1, target, nums);
    }
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return recur(0, amount, coins);
    }
};