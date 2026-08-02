class Solution {
public:
    int dp[501][501];
    int recur(vector<int>&piles, int l, int r)
    {
        if(l == r)
        {
            return piles[l];
        }
        if(dp[l][r] != -1){
            return dp[l][r];
        }
        int left = piles[l] - recur(piles, l + 1, r);
        int right = piles[r] - recur(piles, l, r-1);
        return dp[l][r] = max(left, right);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));
        return recur(piles, 0, n-1) > 0;
    }
};