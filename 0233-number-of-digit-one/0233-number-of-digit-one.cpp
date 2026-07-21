class Solution {
public:
    int dp[11][2][11];
    int recur(string s, int idx, int tight, int curr)
    {
        if(idx == s.size()) return curr;
        if(dp[idx][tight][curr] != -1) return dp[idx][tight][curr];
        int ub = (tight == 1) ? (s[idx]-'0') : 9;
        int count = 0;
        for(int i = 0; i <= ub; i++)
        {
            count += recur(s, idx + 1, tight && (i == s[idx]-'0'), curr + ((i == 1) ? 1 : 0)); 
        }
        return dp[idx][tight][curr] = count;
    }
    int countDigitOne(int n) {
        memset(dp, -1, sizeof(dp));
        string s = to_string(n);
        return recur(s, 0, 1, 0);
    }
};