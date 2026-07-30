class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    void Union(int x, int y)
    {
        int parX = find(x);
        int parY = find(y);
        if(parX == parY)
        {
            return;
        }
        if(rank[parX]  > rank[parY])
        {
            rank[parX]++;
            parent[parY] = parX;
        }
        else
        {
            rank[parY]++;
            parent[parX] = parY;
        }
    }
    int find(int x)
    {
        if(parent[x] == x)
        {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        parent.resize(n, 0);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        for(int i = 0; i < n; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            if(find(u) == find(v))
            {
                return {u, v};
            }
            Union(u, v);
        }
        return {-1,-1};
    }
};