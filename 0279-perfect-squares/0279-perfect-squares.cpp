class Solution {
public:
    vector<int>nums;
    int dp[10001];
    int recur(int n)
    {
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int count = INT_MAX;
        for(int i  = 0; i < nums.size(); i++)
        {
            if(nums[i] > n)
            {
                break;
            }
            count = min(count, 1 + recur(n - nums[i]));
        }
        return dp[n] = count;
    }
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        int curr = 1;
        int square = 1;
        while(square <= n)
        {
            nums.push_back(square);
            curr++;
            square = pow(curr, 2);
        }
        return recur(n);
    }
};