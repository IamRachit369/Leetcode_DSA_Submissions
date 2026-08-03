class Solution {
public:
    string stoneGameIII(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 3, 0);
        for(int l = n - 1; l >= 0; l--)
        {
            int temp = 0;
            dp[l] = INT_MIN;

            for(int i = 0; i < 3 && l + i < n; i++)
            {
                temp += nums[l + i];

                dp[l] = max(dp[l], temp - dp[l + i + 1]);
            }
        }
        if(dp[0] > 0)
            return "Alice";
        else if(dp[0] < 0)
            return "Bob";
        return "Tie";
    }
};