// Check whether Graph is bipartite or not

bool checkBipartite(vector<vector<int>> &adj, vector<bool> &visited, int root, bool color)
{
    colors[root] = color;
    visited[root] = 1;
    for (auto child : adj[root])
    {
        if (!visited[child])
        {
            if (checkBipartite(adj, visited, child, (color ^ 1)) == false)
                return false;
        }
        else if (colors[root] == colors[child])
        {
            return false;
        }
    }
    return true;
}