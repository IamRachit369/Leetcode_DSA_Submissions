class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        for(int i = 0; i < word.size(); i++)
        {
            mp[word[i]]++;
        }
        int freqCount = 0;
        int ans = 0;
        int mul = 1;
        for(auto &x : mp)
        {
            ans += x.second * mul;
            freqCount++;
            if(freqCount >= 8)
            {
                mul++;
                freqCount = 0;
            }
        }
        return ans;
    }
};