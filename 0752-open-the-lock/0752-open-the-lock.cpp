class Solution {
public:
    string add(string temp, int i)
    {
        if(temp[i] == '9')
        {
            temp[i] = '0';
        }
        else
        {
            temp[i]++;
        }
        return temp;
    }
    string rev(string temp, int i)
    {
        if(temp[i] == '0')
        {
            temp[i] = '9';
        }
        else
        {
            temp[i]--;
        }
        return temp;
    }
    int openLock(vector<string>& nums, string target) {
        unordered_set<string>st(nums.begin(), nums.end());
        if(st.find("0000") != st.end())
        {
            return -1;
        }
        unordered_map<string, int>mp;
        queue<pair<string,int>>q;
        q.push({"0000",0});
        mp["0000"] = 1;
        int ans = 0;
        while(!q.empty())
        {
            string curr = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(curr == target)
            {
                return steps;
            }
            for(int i = 0; i < 4; i++)
            {
                string forward = add(curr, i);
                string backward = rev(curr, i);
                if(st.find(forward) == st.end() && mp.find(forward) == mp.end())
                {
                    q.push({forward, steps + 1});
                    mp[forward] = 1;
                }
                if(st.find(backward) == st.end() && mp.find(backward) == mp.end())
                {
                    q.push({backward, steps + 1});
                    mp[backward] = 1;
                }
            }
        }
        return -1;
    }
};