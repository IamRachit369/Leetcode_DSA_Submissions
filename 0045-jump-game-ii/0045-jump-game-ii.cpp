class Solution {
public: 
    int n;
    int dp[10001];
    int recur(int i, vector<int>&nums)
    {
        if(i >= n - 1) return 0;
        if(dp[i]!=-1) return dp[i];
        int count = INT_MAX;
        for(int j = 1; j <= nums[i]; j++)
        {
            int temp = recur(i + j, nums);
            if(temp != INT_MAX)
            {
                count = min(count, temp + 1);
            }
        }
        return dp[i] = count;
    }
    int jump(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        int ans = recur(0, nums);
        return (ans == INT_MAX ? -1 : ans);
    }
};