class Solution {
public:
    typedef pair<double,int>p;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>>adj;
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            double dist = succProb[i];

            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }
        priority_queue<p>pq;
        pq.push({1, start_node});
        vector<double>distance(n, 0);
        distance[start_node] = 1;
        while(!pq.empty())
        {
            int u = pq.top().second;
            double dist_u = pq.top().first;
            pq.pop();
            for(auto &x : adj[u])
            {
                double dist_v = x.second;
                int v = x.first;
                if(distance[v] < (dist_v * dist_u))
                {
                    distance[v] = dist_u * dist_v;
                    pq.push({distance[v], v});
                }
            }
        }
        return distance[end_node];
    }
};