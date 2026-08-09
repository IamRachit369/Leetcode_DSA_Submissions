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

    int ladderLength(string beginWord, string endWord, vector<string>& nums) 
    {
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
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(valid(nums[i], nums[j]))
                {
                    adj[nums[i]].push_back(nums[j]);
                    adj[nums[j]].push_back(nums[i]);
                }
            }
        }

        queue<string>q;
        q.push(beginWord);

        unordered_map<string, int>mp;
        mp[beginWord] = 1;

        while(!q.empty())
        {
            string u = q.front();
            q.pop();

            if(u == endWord)
            {
                return mp[u];
            }

            for(auto &x : adj[u])
            {
                if(mp.find(x) == mp.end())
                {
                    mp[x] = mp[u] + 1;
                    q.push(x);
                }
            }
        }

        return 0;
    }
};