class Solution {
public:
    int ans;
    void dfs(unordered_map<int,vector<int>>&adj, int root,vector<int>&visited,unordered_map<int,vector<int>>&directed)
    {
        visited[root] = 1;
        for(auto &x : adj[root])
        {
            if(!visited[x])
            {
                if(find(directed[x].begin(), directed[x].end(), root) == directed[x].end())
                {
                    ans++;
                }
                dfs(adj,x, visited, directed );
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<int>>adj;
        unordered_map<int,vector<int>>directed;
        ans = 0;
        for(int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            directed[u].push_back(v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>visited(n, 0);
        dfs(adj, 0, visited, directed);
        return ans;
    }
};