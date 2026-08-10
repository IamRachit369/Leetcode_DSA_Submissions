class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>degree(n,0);
        for(int i = 0; i < roads.size(); i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            degree[u]++;
            degree[v]++;
        }
        vector<pair<int,int>>p;
        for(int i = 0; i < n; i++)
        {
            p.push_back({degree[i], i});
        }
        sort(p.begin(), p.end());
        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++)
        {
            mp[p[i].second] = i + 1;
        }
        long long ans = 0;
        for(int i = 0; i < roads.size(); i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            ans += mp[u];
            ans += mp[v];
        }
        return ans;
    }
};