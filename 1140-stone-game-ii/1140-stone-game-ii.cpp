class Solution {
public:
    int recur(int i, int m, vector<int>& nums, vector<vector<int>>& dp)
    {
        if(i >= nums.size())
        {
            return 0;
        }

        if(dp[i][m] != -1)
        {
            return dp[i][m];
        }

        int ans = INT_MIN;
        int sum = 0;

        for(int j = 1; j <= 2 * m; j++)
        {
            if(i + j > nums.size())
            {
                break;
            }

            sum += nums[i + j - 1];

            ans = max(ans, sum - recur(i + j, max(m, j), nums, dp));
        }

        return dp[i][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        int total = accumulate(piles.begin(), piles.end(), 0);

        int diff = recur(0, 1, piles, dp);

        return (total + diff) / 2;
    }
};