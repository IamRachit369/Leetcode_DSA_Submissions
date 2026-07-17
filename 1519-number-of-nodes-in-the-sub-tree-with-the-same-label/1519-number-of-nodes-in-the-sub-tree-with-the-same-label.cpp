class Solution {
public:
    vector<int>visited;
    vector<int> dfs(unordered_map<int,vector<int>>&adj, int root, string &labels, vector<int>&count)
    {
        visited[root] = 1;
        vector<int>curr(26, 0);
        curr[labels[root] - 'a']++;
        for(auto &x : adj[root])
        {
            if(visited[x]) continue;
            vector<int>child = dfs(adj, x, labels, count);
            for(int i = 0; i < child.size(); i++)
            {
                curr[i] += child[i];
            }
        }
        count[root] = curr[labels[root] - 'a'];
        return curr;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        visited.resize(n,0);
        vector<int>count(n,0);
        unordered_map<int,vector<int>>adj;
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>ans = dfs(adj,0, labels, count);
        return count;
    }
};