void dfs(vector<vector<int>> &adj, vector<bool> &visited, int root)
{
    cout << root << " ";
    // tasks while first visit.
    visited[root] = 1;
    for (auto child : adj[root])
    {
        if (!visited[child])
            dfs(adj, visited, child);
    }
    // tasks while returning.
}