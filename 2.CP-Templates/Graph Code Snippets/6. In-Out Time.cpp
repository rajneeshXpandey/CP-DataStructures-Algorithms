// In Out Time for each node in Graph using DFS

int timer=0;
bool dfs(vector<vector<int>> &adj, vector<bool> &visited, int root, vector<int> &in, vector<int> &out)
{
    in[root] = timer;
    timer++;
    visited[root] = 1;
    for (auto child : adj[root])
    {
        if (!visited[child])
        {
            dfs(adj, visited, child,in,out);
        }
    }
    out[root] = timer;
    timer++;
}