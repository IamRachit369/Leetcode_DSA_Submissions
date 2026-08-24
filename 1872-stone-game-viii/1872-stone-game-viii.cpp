class Solution {
public:
    vector<int>prefix;
    int dp[100001];
    int recur(vector<int>&nums, int i)
    {
        if(i == nums.size() - 1) return prefix[i];
        if(dp[i] != INT_MIN)
        {
            return dp[i];
        }
        int take = prefix[i] - recur(nums, i + 1);
        int skip = recur(nums, i + 1);
        return dp[i] = max(take, skip);
    }
    int stoneGameVIII(vector<int>& nums) {
        for(int i = 0; i < 100001; i++)
        {
            dp[i] = INT_MIN;
        }
        prefix.resize(nums.size(),0);
        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            prefix[i] = prefix[i-1] + nums[i];
        } 
        return recur(nums, 1);
    }
};