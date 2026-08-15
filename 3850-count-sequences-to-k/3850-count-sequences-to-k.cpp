class Solution {
public:
    unordered_map<string,int>dp;
    unordered_map<int,vector<int>>mp;
    int recur(vector<int>&nums, int i, long long k, int two, int three, int five)
    {
        string temp = to_string(i) + ":" + to_string(two) + ":" + to_string(three) + ":" + to_string(five);
        if(i == nums.size())
        {
            double val = pow(2, two) * pow(3, three) * pow(5, five);
            if(val == k)
            {
                return 1;
            }
            return 0;
        }
        if(dp.find(temp) != dp.end())
        {
            return dp[temp];
        }
        int twos = mp[nums[i]][0];
        int threes = mp[nums[i]][1];
        int fives = mp[nums[i]][2];
        return dp[temp] = recur(nums,i + 1, k,two + twos, three + threes, five + fives) + recur(nums,i + 1, k,two - twos, three - threes, five - fives) + recur(nums,i + 1, k,two, three, five);
    }
    int countSequences(vector<int>& nums, long long k) {
        mp[1] = {0,0,0};
        mp[2] = {1,0,0};
        mp[3] = {0,1,0};
        mp[4] = {2,0,0};
        mp[5] = {0,0,1};
        mp[6] = {1,1,0};
        return recur(nums, 0, k, 0, 0, 0);
    }
};