class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[v].push_back(u);
        }
        vector<int>ans;
        for(int i = 0; i < n; i++)
        {
            if(adj[i].size() == 0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};