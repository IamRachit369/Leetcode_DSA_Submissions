class Solution {
public:
    vector<int>dp;
    int recur(int l, vector<int>&nums)
    {
        if(l >= nums.size())
        {
            return 0;
        }
        if(dp[l] != INT_MIN)
        {
            return dp[l];
        }
        int count = INT_MIN;
        int temp = 0;
        for(int i = 0; i < 3; i++)
        {
            if(l + i >= nums.size())
            {
                break;
            }
            temp += nums[l + i];
            count = max(count, temp - recur(l + i + 1, nums));
        }
        return dp[l] = count;
    }
    string stoneGameIII(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, INT_MIN);
        int ans = recur(0, nums);
        cout << ans << endl;
        if(ans > 0)
        {
            return "Alice";
        }
        else if(ans < 0)
        {
            return "Bob";
        }
        return "Tie";
    }
};