class Solution {
public:
    int dp[501][501][3];
    int n;
    int m;
    int recur(vector<vector<int>>&nums, int i, int j, int neu)
    {
        if(i == n - 1 && j == m - 1)
        {
            if(nums[i][j] < 0 && neu > 0)
            {
                return 0;
            }
            return nums[i][j];
        }
        if(i >= n || j >= m) return -1e7;
        if(dp[i][j][neu] != -1e7)
        {
            return dp[i][j][neu];
        }
        if(nums[i][j] < 0 && neu > 0)
        {
           int to_pick = max(recur(nums, i + 1, j, neu - 1), recur(nums, i, j + 1, neu - 1));
           int no_pick = nums[i][j] + max(recur(nums, i + 1, j, neu), recur(nums, i, j + 1, neu));
           return dp[i][j][neu] = max(to_pick, no_pick);
        }
        return dp[i][j][neu] = nums[i][j] + max(recur(nums, i + 1, j, neu), recur(nums, i, j + 1, neu));
    }
    int maximumAmount(vector<vector<int>>& nums) {
        n = nums.size();
        m = nums[0].size();
        for(int i = 0; i < 501; i++)
        {
            for(int j = 0; j < 501; j++)
            {
                for(int k = 0; k < 3; k++)
                {
                    dp[i][j][k] = -1e7;
                }
            }
        }
        return recur(nums, 0, 0, 2);
    }
};