class Solution {
public:
    int dp[100001];
    bool recur(int n)
    {
        if(n == 0)
        {
            return false;
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }
        for(int k = 1; k * k <= n; k++)
        {
            if(!recur(n - (k * k)))
            {
                return dp[n] = true;
            }
        }
        return dp[n] = false;
    }
    bool winnerSquareGame(int n) {
        memset(dp, -1, sizeof(dp));
        return recur(n);
    }
};