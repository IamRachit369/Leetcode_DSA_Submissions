class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int count = 0;
        if(s.size() == 1) return 1;
        unordered_map<char,int>mp;
        for(int i = 0; i < s.size(); i++)
        {
            count = 0;
            mp.clear();
            for(int j = 0; j <= 100; j++)
            {
                 int idx = i + j;
                 if(idx < s.size())
                 {
                    if(mp.find(s[idx])==mp.end())
                    {
                        count++;
                        mp[s[idx]] = 1;
                    }
                    else
                    {
                        break;
                    }
                }   
            }   
            ans = max(count, ans);
        }
        return ans;
    }
};