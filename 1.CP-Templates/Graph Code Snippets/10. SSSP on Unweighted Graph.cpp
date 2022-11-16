void bfs(vector<vector<int>> &adj,vector<int> minDistance, int root, int n)
{
    vector<bool> visited(n, 0);
    queue<int> q;
    q.push(root);
    distance[root] = 0;
    visited[root] = 1; 
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            int curr = q.front();
            for (auto nb : adj[curr])
            {
                if (!visited[nb]){
                    q.push(nb);
                    distance[nb] = distance[curr]+1;
                    visited[nb] = 1;
                }
            }
            q.pop();
        }
    }
}