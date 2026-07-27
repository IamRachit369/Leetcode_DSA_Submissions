class Solution {
public:
    int dp[10][2][1024][2][2];
    int recur(string &s, int idx, int tight, int mask, int repitition, int lz)
    {
        if(idx == s.size()) return repitition;
        int lb = 0;
        int ub = (tight == 1) ? s[idx] - '0' : 9;
        int count = 0;
        if(dp[idx][tight][mask][repitition][lz] != -1) return dp[idx][tight][mask][repitition][lz];
        for(int i = lb; i <= ub; i++)
        {
            int isDuplicate = (1 & (mask >> i));
            if(i == 0 && lz)
            {
                isDuplicate = 0;
            }
            count += recur(s, idx + 1, (tight && i == ub) ? 1 : 0, (lz && i == 0) ? mask : (mask | 1 << i), isDuplicate || repitition, lz && i == 0);
        }
        return dp[idx][tight][mask][repitition][lz] = count;
    }
    int numDupDigitsAtMostN(int n) {
        memset(dp, -1, sizeof(dp));
        string s = to_string(n);
        return recur(s, 0, 1, 0, 0, 1);
    }
};