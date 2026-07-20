class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int prev = -1;
        for(int i = 0; i < 31; i++)
        {
            if((n >> i)&1)
            {
                if(prev != -1)
                {
                    ans = max(ans, i - prev);
                }
                prev = i;
            }
        }
        return ans;
    }
};