class Solution {
public:
    vector<pair<int,int>> RLE(string s)
    {
        vector<pair<int,int>>ans;
        int count = 1;
        int prev = s[0] - '0';

        for(int i = 1; i < s.size(); i++)
        {
            int curr = s[i] - '0';

            if(curr != prev)
            {
                ans.push_back({prev, count});
                count = 1;
                prev = s[i] - '0';
            }
            else
            {
                count++;
            }
        }

        ans.push_back({prev, count});
        return ans;
    }

    string convert(vector<pair<int,int>>&pq)
    {
        string ans = "";

        for(auto &x : pq)
        {
            ans += to_string(x.second) + to_string(x.first);
        }

        return ans;
    }

    string solve(int n)
    {
        if(n == 1)
        {
            return "1";
        }

        string prev = solve(n - 1);
        vector<pair<int,int>> pq = RLE(prev);

        return convert(pq);
    }

    string countAndSay(int n) {
        return solve(n);
    }
};