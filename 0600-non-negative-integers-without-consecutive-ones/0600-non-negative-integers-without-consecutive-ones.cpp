class Solution {
public:
    int dp[32][2][2];

    int recur(string &s, int idx, int tight, int prev)
    {
        if(idx == s.size()) return 1;

        if(dp[idx][tight][prev] != -1)
            return dp[idx][tight][prev];

        int ub = tight ? s[idx] - '0' : 1;
        int count = 0;

        for(int i = 0; i <= ub; i++)
        {
            if(prev && i == 1) continue;

            count += recur(s,
                           idx + 1,
                           tight && (i == ub),
                           i == 1);
        }

        return dp[idx][tight][prev] = count;
    }

    int findIntegers(int n)
    {
        if(n == 0) return 1;

        bitset<32> b(n);

        string s = b.to_string();
        
        memset(dp, -1, sizeof(dp));

        return recur(s, 0, 1, 0);
    }
};