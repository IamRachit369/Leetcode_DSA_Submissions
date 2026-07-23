class Solution {
public:
    int n;
    int dp[301][11];
    int recur(vector<int>&nums, int i, int d)
    {
        if(d == 1)
        {
            return dp[i][d] = *max_element(nums.begin() + i, nums.end());
        }
        if(dp[i][d] != -1) return dp[i][d];
        int ans = INT_MAX;
        int maxD = 0;
        for(int idx = i; idx <= n - d; idx++)
        {
            maxD = max(maxD, nums[idx]);
            ans = min(ans, maxD + recur(nums, idx + 1, d - 1));
        }
        return dp[i][d] = ans;
    }
    int minDifficulty(vector<int>& nums, int d) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        int ans = recur(nums, 0, d);
        return (ans == INT_MAX ? -1 : ans);
    }
};