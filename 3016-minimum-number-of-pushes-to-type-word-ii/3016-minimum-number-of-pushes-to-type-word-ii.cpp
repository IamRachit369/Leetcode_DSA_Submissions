class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        priority_queue<pair<int,int>>pq;
        for(int i = 0; i < word.size(); i++)
        {
            mp[word[i]]++;
        }
        for(auto &x: mp)
        {
            pq.push({x.second, x.first});
        }
        int freqCount = 0;
        int ans = 0;
        int mul = 1;
        while(!pq.empty())
        {
            ans += pq.top().first * mul;
            freqCount++;
            if(freqCount >= 8)
            {
                mul++;
                freqCount = 0;
            }
            pq.pop();
        }
        // for(auto &x : mp)
        // {
        //     ans += x.second * mul;
        //     freqCount++;
        //     if(freqCount >= 8)
        //     {
        //         mul++;
        //         freqCount = 0;
        //     }
        // }
        return ans;
    }
};