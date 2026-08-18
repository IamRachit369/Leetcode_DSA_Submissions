class Solution {
public:
    int dp[201][20001];
    bool recur(vector<int>&nums, int i, int target)
    {
        //pick or no pick
        if(target == 0)
        {
            return true;
        }
        if(target < 0)
        {
            return false;
        }
        if(i == nums.size())
        {
            return false;
        }
        if(dp[i][target] != -1)
        {
            return dp[i][target];
        }
        return dp[i][target] = recur(nums, i + 1, target) || recur(nums, i + 1, target - nums[i]);
    }
    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total%2 == 1) return false;
        int target = total/2;
        return recur(nums, 0, target);
    }
};