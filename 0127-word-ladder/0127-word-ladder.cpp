class Solution {
public:
    typedef pair<int, string>p;
    bool valid(string s, string t)
    {
        int count = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != t[i])
            {
                count++;
            }
        }
        return count == 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& nums) {
        unordered_map<string, vector<string>>adj;
        if(find(nums.begin(), nums.end(), endWord) == nums.end())
        {
            return 0;
        }
        if(find(nums.begin(), nums.end(), beginWord) == nums.end())
        {
            nums.push_back(beginWord);
        }
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if(valid(nums[i], nums[j]))
                {
                    adj[nums[i]].push_back(nums[j]);
                    adj[nums[j]].push_back(nums[i]);
                }
            }
        }
        priority_queue<p, vector<p>, greater<p>>pq;
        pq.push({1, beginWord});
        unordered_map<string, int>mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]] = INT_MAX;
        }
        mp[beginWord] = 1;
        while(!pq.empty())
        {
            int dist = pq.top().first;
            string u = pq.top().second;
            pq.pop();
            for(auto &x : adj[u])
            {
                if(1 + dist < mp[x])
                {
                    mp[x] = 1 + dist;
                    pq.push({1 + dist, x});
                }
            }
        }
        return (mp[endWord] == INT_MAX ? 0 : mp[endWord]);
    }
};