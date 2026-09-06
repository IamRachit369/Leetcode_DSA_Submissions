class Solution {
public:
    int countRotations(string s, int k) {
        //rotate for every possible position
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            //rotate the array this many times
            reverse(s.begin(), s.end());
            reverse(s.begin(), s.begin() + 1);
            reverse(s.begin() + 1, s.end());
            int temp = 0;
            for(int j = 0; j < n - 1; j++)
            {
                if(s[j] == s[j + 1])
                {
                    temp++;
                }
            }
            if(temp == k)
            {
                ans++;
            }
        }
        return ans;
    }
};