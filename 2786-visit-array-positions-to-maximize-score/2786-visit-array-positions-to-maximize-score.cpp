class Solution {
public:
    long long dp[100001];
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        long long bestOdd = LLONG_MIN;
        long long bestEven = LLONG_MIN;
        for(int i = n - 1; i >= 0; i--)
        {
            dp[i] = nums[i];
            if(nums[i]%2 == 1)
            {
                if(bestOdd != LLONG_MIN)
                {
                    dp[i] = max(dp[i], nums[i] + bestOdd);
                }
                if(bestEven != LLONG_MIN)
                {
                    dp[i] = max(dp[i], nums[i] + bestEven - x);
                }
                bestOdd = max(bestOdd, dp[i]);
            }
            else
            {
                if(bestOdd != LLONG_MIN)
                {
                    dp[i] = max(dp[i], nums[i] + bestOdd - x);
                }
                if(bestEven != LLONG_MIN)
                {
                    dp[i] = max(dp[i], nums[i] + bestEven);
                }
                bestEven = max(bestEven, dp[i]);
            }
        }
        return dp[0];
    }
};