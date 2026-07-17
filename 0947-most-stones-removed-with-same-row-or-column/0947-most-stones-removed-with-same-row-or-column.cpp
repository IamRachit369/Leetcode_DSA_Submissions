class Solution {
public:
    vector<int>parent;
    vector<int>rank;    
    int find(int i)
    {
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void Union(int i, int j)
    {
        int parI = find(i);
        int parJ = find(j);
        if(parI == parJ) return;
        if(rank[parI] > rank[parJ])
        {
            parent[parJ] = parI;
        }
        else if(rank[parJ] > rank[parI])
        {
            parent[parI] = parJ;
        }
        else
        {
            parent[parJ] = parI;
            rank[parI]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n);
        rank.resize(n,1);
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    Union(i, j);
                }
            }
        }
        int count = 0;
        for(int i = 0; i < parent.size();i++)
        {
            if(parent[i] == i)
            {
                count++;
            }
        }
        return n - count;
    }
};