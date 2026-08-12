class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();

        unordered_map<int, vector<int>> adj;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j) continue;

                long long dx = bombs[i][0] - bombs[j][0];
                long long dy = bombs[i][1] - bombs[j][1];

                long long r = bombs[i][2];

                if(dx * dx + dy * dy <= r * r)
                {
                    adj[i].push_back(j);
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            vector<int>visited(n, 0);
            queue<int>q;

            q.push(i);
            visited[i] = 1;

            int count = 0;

            while(!q.empty())
            {
                int u = q.front();
                q.pop();

                count++;

                for(auto &x : adj[u])
                {
                    if(!visited[x])
                    {
                        visited[x] = 1;
                        q.push(x);
                    }
                }
            }

            ans = max(ans, count);
        }

        return ans;
    }
};