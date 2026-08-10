class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>degree(n,0);
        set<pair<int,int>>st;
        for(int i = 0; i < roads.size(); i++)
        {
            st.insert({roads[i][0], roads[i][1]});
            st.insert({roads[i][1], roads[i][0]});
            degree[roads[i][0]]++;
            degree[roads[i][1]]++;
        }
        int ans = 0;
        for(int i = 0; i < degree.size(); i++)
        {
            for(int j = i + 1; j < degree.size(); j++)
            {
                int curr = degree[i] + degree[j];
                if(st.find({i,j}) != st.end())
                {
                    curr--;
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};