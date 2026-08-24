class Solution {
public:
    int dp[100001][26];
    int recur(int i, char prev, string &s, int k)
    {
        //pick and no pick
        //pick valid if prev == -1 || abs(curr - prev) <= k
        //no pick valid in both cases
        if(i == s.size()) return 0;
        if(prev != '#' && dp[i][prev - 'a'] != -1) 
        {
            return dp[i][prev - 'a'];
        }
        int pick = INT_MIN;
        if(prev == '#' || abs(s[i] - prev) <= k)
        {
            pick = 1 + recur(i + 1, s[i], s, k);
        }
        int no_pick = recur(i + 1, prev, s, k);
        int ans = max(pick, no_pick);
        if(prev != '#')
        {
            return dp[i][prev - 'a'] = ans;
        } 
        return ans;
    }
    int longestIdealString(string s, int k) {
        memset(dp, -1, sizeof(dp));
        return recur(0, '#', s, k);
    }
};